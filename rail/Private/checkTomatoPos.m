function result = checkTomatoPos(currentImagePos,currentCartPos, error)
%checkTomatoPos ���͈ʒu�𖢏n�g�}�g�̈ʒu���Ɣ�r
%   ����
%   currentImagePos: struct
%   currentCartPos: double
%   error: double
%   �o��
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

