%%
%%clear all
%% フォルダー作成
cd('.\')
folder_name = datestr(now,'yyyymmdd_HHMM');
mkdir(folder_name)
%% matファイルが保存されている場所に移動してデータを移動
movefile('*.mat',folder_name)

%% 現在のフォルダーを移動
cd('.\')