%%
%%clear all
%% �t�H���_�[�쐬
cd('.\')
folder_name = datestr(now,'yyyymmdd_HHMM');
mkdir(folder_name)
%% mat�t�@�C�����ۑ�����Ă���ꏊ�Ɉړ����ăf�[�^���ړ�
movefile('*.mat',folder_name)

%% ���݂̃t�H���_�[���ړ�
cd('.\')