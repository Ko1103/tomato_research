function result = checkTomatoPos(currentImagePos, currentCartPos, error)
%checkTomatoPos ���͈ʒu�𖢏n�g�}�g�̈ʒu���Ɣ�r
%   ����
%   currentImagePos: struct �ΏۂƂ��Ă���g�}�g�̉摜�ʒu
%   currentCartPos: double ���݂̃J�[�g�̈ʒu
%   error: double ���e�덷
%   �o��
%   result: bool ���n�g�}�g�̈ʒu�ƈ�v����Ȃ��true, ���̑���false

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

