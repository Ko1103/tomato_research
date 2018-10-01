function result = checkCartPos(currentCartPos, error)
%checkCartPos カートの位置が未熟トマトがある位置かどうかを判定
%   入力
%   currentCartPos: double カートの位置を書く。
%   error: double 誤差。この値の±で判定する。
%   出力
%   result: bool 未熟トマトがある位置であればtrue, そうでない場合はfalse
minCartPos = currentCartPos - error;
maxCartPos = currentCartPos + error;
dists = load('cartPos'); 
dists(dists > minCartPos);
dists(dists < maxCartPos);
n = numel(dists);
result = logical(n > 0);
end