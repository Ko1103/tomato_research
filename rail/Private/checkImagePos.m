function result = checkImagePos(currentImagePos, error)
%checkCartPos �摜�̈ʒu�����n�g�}�g������ʒu���ǂ����𔻒�
%   ����
%   currentImagePos: struct �J�[�g�̈ʒu�������B
%   error: double �덷�B���̒l�́}�Ŕ��肷��B
%   �o��
%   result: bool ���n�g�}�g������ʒu�ł����true, �����łȂ��ꍇ��false
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

