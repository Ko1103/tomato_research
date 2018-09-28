%%
clear all
%% Arm Position
% Armの初期位置
armInitPos=[120,0,280,0,0,0,10,20];
% pitch追加
pitchAdd = [0,0,50,0,60,0];
% Armの速度・加速度
velocity = 50;
acceleration = 100;
%% Armとカメラの幾何学的関係
% 右手座標
% EEあり Arm取付位置前
%relationOfArmCam=[660, 330, -100];
% EEあり Arm取付位置後(x-axis:-130)
relationOfArmCam=[530, 330, -100];

% EEなし Arm取付位置前
%relationOfArmCam=[300, 330, -100];
% EEなし Arm取付位置後
%relationOfArmCam=[200, 330, -100];
%% アームの位置補正値
%[moveflag = 1(左方向), moveflag = -1(右方向)]
% EEなし
%correct = [0, 0, 80, 0, -10, 80];
% EEあり[左、右]
correct = [15, -50, 130, 35, 60, 100];
% EEあり[右、左]
%correct = [10, 35, 90, 5, -65, 120];
%[15,35,100,0,-65,120]
%[0,-50,-130,0,70,100]
%% HSV：しきい値
% Define thresholds for channel 1 based on histogram settings
channel1Min = 0.921;
channel1Max = 0.049;

% Define thresholds for channel 2 based on histogram settings
channel2Min = 0.579;
channel2Max = 1.000;

% Define thresholds for channel 3 based on histogram settings
channel3Min = 0.138;
channel3Max = 0.579;

% channel 1
HMin=channel1Min; HMax=channel1Max;
% channel 2
SMin=channel2Min; SMax=channel2Max;
% channel 3 based
VMin=channel3Min; VMax=channel3Max;

value=[HMin, HMax, SMin, SMax, VMin, VMax];
%% 奥行のしきい値
range = 900;
range_m = range / 1000; % [m]
range_mm = range;       % [mm]
% 「Analysys Subsystem」のMATALAB Function2
dummyDepth = 600;
%% 「Image Subsytem」の関心領域
center = 450;
h1_1= 100;                      % 1_上側除去
h1_2 = 350;                     % 2_下側除去
w1_r1 = center - 10;            % 3_右側着目
w1_r2 = center + 10;            % 4_
w1_l1 = 77;                     % 5_左側着目
w1_l2 = 179;                    % 6_
limit_range_IMG = [h1_1, h1_2, w1_r1, w1_r2, w1_l1, w1_l2];
%% 「Analysys Subsytem」の関心領域
h2_1= 100;                      % 1_上側除去
h2_2 = 350;                     % 2_下側除去
w2_r1 = center - 25;            % 3_右側着目
w2_r2 = center + 25;            % 4_
w2_l1 = 77;                     % 5_左側着目
w2_l2 = 179;                    % 6_
limit_range_ANA = [h2_1, h2_2, w2_r1, w2_r2, w2_l1, w2_l2];
%% Cartの移動範囲
% 単位[m]
railDistance = 1.8;
first = 0;
robotLength = 0.8;
termDistance= railDistance - robotLength - first;
%% Cartの方向
% 初期移動方向
%direction = 1;      % 左
direction = -1;     % 右
%% 縮小率
erosion = 2;
%% サンプリングタイム
dt = 0.1;
%% Kinect用
cd('.\Params');
load('KinectParams.mat');
load('cameraParams.mat');
cd('..\');
%% 外部パラメータ
% 回転行列：回転なし
R = [1 0 0;0 1 0;0 0 1];
% 並進ベクトル
translationVector=[0, 0, 0];