//----------------------------------------------------------------------------------//
// @file         SceneManager.h
// @brief        SceneManager�N���X
// @note         �V�[���̊Ǘ��N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class SceneManager
{
public:
	 SceneManager();	// �R���X�g���N�^
	~SceneManager();    // �f�X�g���N�^
										     
	void Update(float _deltaTime);    // �X�V
	void Draw();		              // �`��
	void Sound();		              // ���y

	void SetScene(class SceneBase* _scene);    // Set�֐� (�������̎��ɂ����g��Ȃ�) (�����ɖ��O������Ƃ��͍ŏ��ɃA���_�[�o�[������) (�v����)				

private:
	class SceneBase* mScene;    // �V�[���x�[�X�ւ̃|�C���^�����o�ϐ� (�v����)
};
