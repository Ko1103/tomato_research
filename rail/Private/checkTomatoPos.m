function result = checkTomatoPos(currentImagePos, currentCartPos, error)
%checkTomatoPos 入力位置を未熟トマトの位置情報と比較
%   入力
%   currentImagePos: struct 対象としているトマトの画像位置
%   currentCartPos: double 現在のカートの位置
%   error: double 許容誤差
%   出力
%   result: bool 未熟トマトの位置と一致するならばtrue, その他はfalse

posDatas = load('TomatoPos');
posDatas(posDatas.x > (currentImagePos.x - error));
posDatas(posDatas.x > (currentImagePos.x + error));
posDatas(posDatas.y > (currentImagePos.y - error));
posDatas(posDatas.y > (currentImagePos.y + error));
posDatas(posDatas.z > (currentImagePos.y - error));
posDatas(posDatas.z > (currentImagePos.y + error));
posDatas(posDatas.l > (currentCartPos - error));
posDatas(posDatas.l > (currentCartPos + error));
n = numel(posDatas);
result = logical(n > 0);
end

