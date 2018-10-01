function result = checkTomatoPos(currentImagePos,currentCartPos, error)
%checkTomatoPos 入力位置を未熟トマトの位置情報と比較
%   入力
%   currentImagePos: struct
%   currentCartPos: double
%   error: double
%   出力
%   result: bool

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

