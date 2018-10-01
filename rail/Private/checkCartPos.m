function result = checkCartPos(currentCartPos, error)
%checkCartPos �J�[�g�̈ʒu�����n�g�}�g������ʒu���ǂ����𔻒�
%   ����
%   currentCartPos: double �J�[�g�̈ʒu�������B
%   error: double �덷�B���̒l�́}�Ŕ��肷��B
%   �o��
%   result: bool ���n�g�}�g������ʒu�ł����true, �����łȂ��ꍇ��false
minCartPos = currentCartPos - error;
maxCartPos = currentCartPos + error;
dists = load('cartPos'); 
dists(dists > minCartPos);
dists(dists < maxCartPos);
n = numel(dists);
result = logical(n > 0);
end