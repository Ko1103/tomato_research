function result = checkImagePos(currentImagePos, error)
%checkCartPos 画像の位置が未熟トマトがある位置かどうかを判定
%   入力
%   currentImagePos: struct カートの位置を書く。
%   error: double 誤差。この値の±で判定する。
%   出力
%   result: bool 未熟トマトがある位置であればtrue, そうでない場合はfalse
images = load('imagePos'); 

images(images.x > (currentImagePos.x - error));
images(images.x < (currentImagePos.x + error));

images(images.y < (currentImagePos.y - error));
images(images.y < (currentImagePos.y + error));

images(images.z < (currentImagePos.z - error));
images(images.z < (currentImagePos.z + error));

n = numel(images);
result = logical(n > 0);
end

