function armComBlock(block)
% Help for Writing Level-2 M-File S-Functions:
%   web([docroot '/toolbox/simulink/sfg/f7-67622.html']

%   Copyright 2011 The MathWorks, Inc.

% define instance variables
mySerial = [];

arm.state.position = zeros(6,1);
arm.state.joint = zeros(6,1);
arm.target.position = zeros(6,1);
arm.target.joint = zeros(6,1);
arm.target.acc = 0.0;
arm.target.vel = 0.0;
arm.home.go = 0;
arm.moved = 1;
arm.bcr.on = 0;
arm.reset.on = 0;

setup(block);

%% ---------------------------------------------------------

    function setup(block)
        % Register the number of ports.
        block.NumInputPorts  = 2;
        block.NumOutputPorts = 2;
        
        % Set up the states
        block.NumContStates = 0;
        block.NumDworks = 0;
        
        % Register the parameters.
        block.NumDialogPrms     = 3; % COM port, Baud Rate, Temporary position
        block.DialogPrmsTunable = {'Nontunable', 'Nontunable', 'Nontunable'};
        
        % Setup functional port properties to dynamically inherited
        block.SetPreCompInpPortInfoToDynamic;
        block.SetPreCompOutPortInfoToDynamic;
        
        % Calibration port setting
        block.InputPort(1).Complexity        = 'Inherited';
        block.InputPort(1).DataTypeId        = -1;
        block.InputPort(1).SamplingMode      = 'Sample';
        block.InputPort(1).DimensionsMode    = 'Fixed';
        block.InputPort(1).DirectFeedthrough = true; % 入力を出力関数で直接利用する
        
        % end-effector port setting
        block.InputPort(2).Complexity        = 'Inherited';
        block.InputPort(2).DataTypeId        = 0;
        block.InputPort(2).SamplingMode      = 'Sample';
        block.InputPort(2).DimensionsMode    = 'Fixed';
        block.InputPort(2).DirectFeedthrough = true; % 入力を出力関数で直接利用する
        
        % Register the properties of the output port
        block.OutputPort(1).DataTypeId = 0;
        block.OutputPort(1).DimensionsMode = 'Fixed';
        block.OutputPort(1).SamplingMode   = 'Sample';
        % Register the properties of the output port
        block.OutputPort(2).DataTypeId = 0;
        block.OutputPort(2).DimensionsMode = 'Fixed';
        block.OutputPort(2).SamplingMode   = 'Sample';
        
        
        % Block is fixed in minor time step, i.e., it is only executed on major
        % time steps. With a fixed-step solver, the block runs at the fastest
        % discrete rate.
        block.SampleTimes = [0 1];
        
        block.SetAccelRunOnTLC(false); % run block in interpreted mode even w/ Acceleration
        block.SimStateCompliance = 'DefaultSimState';
        
        block.InputPort(1).Dimensions = 1;
        block.InputPort(2).Dimensions = 8;
        block.OutputPort(1).Dimensions = 6;
        block.OutputPort(2).Dimensions = 1;
        
        
        % If the creation of a new variable is requested, (i.e. no
        % previously instantiated workspace arduino variable is used)
        % then the ArduinoIO block uses the Start method to initialize the
        % arduino connection before the variable is actually accessed
        
        block.RegBlockMethod('CheckParameters', @CheckPrms); % called during update diagram
        block.RegBlockMethod('Start', @Start); % called first
        block.RegBlockMethod('Outputs', @Output); % called first in sim loop
        % block.RegBlockMethod('InitializeConditions', @InitConditions); % called second
        block.RegBlockMethod('Terminate', @Terminate);
    end

%%
    function CheckPrms(block)
        try
            validateattributes(block.DialogPrm(1).Data, {'char'}, {'nonempty'}); % Serial port
            validateattributes(block.DialogPrm(2).Data, {'double'}, {'nonempty'}); % BaudRate
            validateattributes(block.DialogPrm(3).Data, {'double'}, {'nonempty'}); % Temporary position
        catch %#ok<CTCH>
            % パラメータの型が異なる場合にエラーを出力
            error('Port or BaudRate error');
        end
        
    end

%%
    function Start(block)
        
        % create the serial object
        if ~isempty(block.DialogPrm(1).Data),
            mySerial = serial(block.DialogPrm(1).data, 'BaudRate', block.DialogPrm(2).data, ...
                'InputBufferSize', 1024*10, 'Parity', 'none', 'StopBits', 1, 'Terminator', 'LF');
            set(mySerial, 'BytesAvailableFcn' ,@SerialRcv);
            %disp(get(mySerial));
        end
        
        try
            fopen(mySerial);                
        catch me
            error(['Serial Port ', block.DialogPrm(1).data,' could not open!']);
        end
        
        disp('1')
        fwrite(mySerial,['#bcr,1,1,1,1',10],'char');
        disp('<-- Angle Calibrating -->')
        arm.bcr.on = 1;   
        while arm.bcr.on
            pause(1);
        end
        disp('<-- Angle Calibrated -->')
        %fwrite(mySerial,['#max,1,1,1,1',10],'char'); % 現在の手先位置を取得
        
        prm3 = block.DialogPrm(3).data;
        if length(prm3)~=8
            error('Parameter 3 is wrong!');
        end

        % Temporary Positionへ移動
        fwrite(mySerial,['#axy,1,1,1,', num2str(prm3(1)), ',', num2str(prm3(2)), ',',...
            num2str(prm3(3)), ',', num2str(prm3(4)), ',', num2str(prm3(5)), ',',...
            num2str(prm3(6)), ',', num2str(prm3(7)), ',', num2str(prm3(8)), 10],'char');
        arm.moved = 0; % 移動開始
    end

%%
    function Output(block)
        
        % キャリブレーション動作
        if ~isempty(block.InputPort(1).Data)
            if block.InputPort(1).Data==1 && arm.bcr.on==0
                fwrite(mySerial,['#bcr,1,1,1,1',10],'char');
                disp('<-- Angle Calibrating -->')
                arm.bcr.on = 1;
            end
        end
        
        % 手先位置のターゲットを取得し，アームへ送信
        if ~isempty(block.InputPort(2).Data) && arm.moved==1 && sum(abs(block.InputPort(2).Data(1:6))) > 0.1
            % 変更があった場合のみ送信
            %if abs(sum(arm.target.position-block.InputPort(2).Data(1:6))) > 1.0e-3,
                pos = block.InputPort(2).Data;
                fwrite(mySerial,['#itm,1,1,1,', num2str(pos(1)), ',', num2str(pos(2)), ',',...
                num2str(pos(3)), ',', num2str(pos(4)), ',', num2str(pos(5)), ',',...
                num2str(pos(6)), ',', num2str(pos(7)), ',', num2str(pos(8)), 10],'char');
                arm.target.position = pos;
                arm.moved = 0; % 移動開始
            %end
        end
        
        %disp(mySerial.BytesAvailable);
        
        % 現在のポジションを出力
        block.OutputPort(1).Data = arm.state.position;
        
        % 動作完了かどうかを出力
        block.OutputPort(2).Data = arm.moved;    
        
    end

%%
    function Terminate(block)
        
        if mySerial.BytesAvailable > 0
            fread(mySerial, mySerial.BytesAvailable, 'char');
        end
        
        fclose(mySerial);
        delete(mySerial);
        
    end

%%
    function SerialRcv(obj,event)
        if mySerial.BytesAvailable == 0,
            return;
        end
        
        %disp('getData!');
        %rcvBytes = mySerial.BytesAvailable; %　受信文字数を取得
        buf = fscanf(mySerial);% 改行まで取得
        rcvdlm = regexp(buf,'[,]'); % ','で区切られた位置を取得
        rcvCmd = strfind(buf,'#'); % 先頭が'#'の文字を探して取得
        
        disp(char(buf));
        
        if isempty(rcvCmd), % 受信データの有無をチェック
            %コマンドを含まない場合はなにもしない．
            return;
        end
        cmdNum = length(buf); % 受信データの長さをチェック
        command = buf(rcvCmd:rcvdlm(1)-1); % 受信コマンドの取得
        if length(command) > 4
            % コマンドの長さが4より大きい場合は何もしない
            return;
        end
        
        indexList = [rcvdlm, cmdNum+1];
        
        % カンマのある位置のデータを取得する
        switch command
            case '#bcr' % キャリブレーション
                if length(rcvdlm) == 5,
                    arm.moved = str2double(buf(rcvdlm(4)+1:rcvdlm(5)-1));
                    if arm.moved,
                        disp('<-- Angle Calibrated -->');
                        arm.bcr.on = 0;
                    end
                end
                
            case '#axy' % 絶対位置移動
                if length(rcvdlm) >= 10
                    index = 4;
                    arm.moved = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                    if arm.moved,
                        index = 6;
                        for j = 1:6;
                            arm.state.position(j) = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                            index = index+1;
                        end
                    end
                end
                
            case '#ixy' % 相対位置移動
                if length(rcvdlm) >= 10
                    index = 4;
                    arm.moved = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                    if arm.moved,
                        index = 6;
                        for j = 1:6;
                            arm.state.position(j) = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                            index = index+1;
                        end
                    end
                end
                
            case '#itm' % 相対位置移動
                if length(rcvdlm) >= 10
                    index = 4;
                    arm.moved = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                    if arm.moved,
                        index = 6;
                        for j = 1:6;
                            arm.state.position(j) = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                            index = index+1;
                        end
                    end
                end
                
            case '#max' % 位置取得
                if length(rcvdlm) >= 10
                    index = 4;
                    arm.moved = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                    if arm.moved,
                        index = 6;
                        for j = 1:6;
                            arm.state.position(j) = str2double(buf(indexList(index)+1:indexList(index+1)-1));
                            index = index+1;
                        end
                    end
                end
                
            otherwise
                disp('other');
        end
    end

end

