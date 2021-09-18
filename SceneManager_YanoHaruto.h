//----------------------------------------------------------------------------------//
// @file         SceneManager_YanoHaruto.h
// @brief        SceneManager_YanoHaruto�N���X
// @note         �V�[���̊Ǘ��N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class SceneManager_YanoHaruto
{
public:
	SceneManager_YanoHaruto();	// �R���X�g���N�^
	~SceneManager_YanoHaruto();    // �f�X�g���N�^

	void Update(float _deltaTime, int& _hiScore);    // �X�V
	void Draw();		              // �`��
	void Sound(float _deltaTime);		              // ���y

	void SetScene(class SceneBase* _scene);    // Set�֐� (�������̎��ɂ����g��Ȃ�) (�����ɖ��O������Ƃ��͍ŏ��ɃA���_�[�o�[������) (�v����)				

private:
	class SceneBase* mScene;    // �V�[���x�[�X�ւ̃|�C���^�����o�ϐ� (�v����)

};
