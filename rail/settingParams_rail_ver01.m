%%
clear all
%% Arm Position
% Arm�̏����ʒu
armInitPos=[120,0,280,0,0,0,10,20];
% pitch�ǉ�
pitchAdd = [0,0,50,0,60,0];
% Arm�̑��x�E�����x
velocity = 50;
acceleration = 100;
%% Arm�ƃJ�����̊􉽊w�I�֌W
% �E����W
% EE���� Arm��t�ʒu�O
%relationOfArmCam=[660, 330, -100];
% EE���� Arm��t�ʒu��(x-axis:-130)
relationOfArmCam=[530, 330, -100];

% EE�Ȃ� Arm��t�ʒu�O
%relationOfArmCam=[300, 330, -100];
% EE�Ȃ� Arm��t�ʒu��
%relationOfArmCam=[200, 330, -100];
%% �A�[���̈ʒu�␳�l
%[moveflag = 1(������), moveflag = -1(�E����)]
% EE�Ȃ�
%correct = [0, 0, 80, 0, -10, 80];
% EE����[���A�E]
correct = [15, -50, 130, 35, 60, 100];
% EE����[�E�A��]
%correct = [10, 35, 90, 5, -65, 120];
%[15,35,100,0,-65,120]
%[0,-50,-130,0,70,100]
%% HSV�F�������l
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
%% ���s�̂������l
range = 900;
range_m = range / 1000; % [m]
range_mm = range;       % [mm]
% �uAnalysys Subsystem�v��MATALAB Function2
dummyDepth = 600;
%% �uImage Subsytem�v�̊֐S�̈�
center = 450;
h1_1= 100;                      % 1_�㑤����
h1_2 = 350;                     % 2_��������
w1_r1 = center - 10;            % 3_�E������
w1_r2 = center + 10;            % 4_
w1_l1 = 77;                     % 5_��������
w1_l2 = 179;                    % 6_
limit_range_IMG = [h1_1, h1_2, w1_r1, w1_r2, w1_l1, w1_l2];
%% �uAnalysys Subsytem�v�̊֐S�̈�
h2_1= 100;                      % 1_�㑤����
h2_2 = 350;                     % 2_��������
w2_r1 = center - 25;            % 3_�E������
w2_r2 = center + 25;            % 4_
w2_l1 = 77;                     % 5_��������
w2_l2 = 179;                    % 6_
limit_range_ANA = [h2_1, h2_2, w2_r1, w2_r2, w2_l1, w2_l2];
%% Cart�̈ړ��͈�
% �P��[m]
railDistance = 1.8;
first = 0;
robotLength = 0.8;
termDistance= railDistance - robotLength - first;
%% Cart�̕���
% �����ړ�����
%direction = 1;      % ��
direction = -1;     % �E
%% �k����
erosion = 2;
%% �T���v�����O�^�C��
dt = 0.1;
%% Kinect�p
cd('.\Params');
load('KinectParams.mat');
load('cameraParams.mat');
cd('..\');
%% �O���p�����[�^
% ��]�s��F��]�Ȃ�
R = [1 0 0;0 1 0;0 0 1];
% ���i�x�N�g��
translationVector=[0, 0, 0];