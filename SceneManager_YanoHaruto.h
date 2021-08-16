#pragma once

class SceneManager_YanoHaruto
{
public:
	SceneManager_YanoHaruto();	// �R���X�g���N�^
	~SceneManager_YanoHaruto();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V
	void Draw();		              // �`��
	void Sound();		              // ���y

	void SetScene(class SceneBase* _scene);    // Set�֐� (�������̎��ɂ����g��Ȃ�) (�����ɖ��O������Ƃ��͍ŏ��ɃA���_�[�o�[������) (�v����)				

private:
	class SceneBase* mScene;    // �V�[���x�[�X�ւ̃|�C���^�����o�ϐ� (�v����)
};