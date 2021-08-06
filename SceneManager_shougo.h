//----------------------------------------------------------------------------------//
// @file         SceneManager_shougo.h
// @brief        SceneManager_shougo�N���X
// @note         �V�[���̊Ǘ��N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class SceneManager_shougo
{
public:
	SceneManager_shougo();	// �R���X�g���N�^
	~SceneManager_shougo();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V
	void Draw();		              // �`��
	void Sound();		              // ���y

	void SetScene(class SceneBase* _scene);    // Set�֐� (�������̎��ɂ����g��Ȃ�) (�����ɖ��O������Ƃ��͍ŏ��ɃA���_�[�o�[������) (�v����)				

private:
	class SceneBase* mScene;    // �V�[���x�[�X�ւ̃|�C���^�����o�ϐ� (�v����)

};
