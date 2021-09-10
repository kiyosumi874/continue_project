//----------------------------------------------------------------------------------//
// @file         SceneBase.h
// @brief        SceneBase�N���X
// @note         SceneBase�N���X
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

// �V�[���x�[�X�N���X
class SceneBase
{
public:
	         SceneBase()   ;    // �R���X�g���N�^
	virtual ~SceneBase() {};    // ���z�f�X�g���N�^

	virtual SceneBase* Update(float _deltaTime, int& _hiScore) = 0;    // �V�[���̍X�V���� (�I�[�o�[���C�h�K�{)
	virtual void       Draw()                   = 0;    // �V�[���̕`�揈�� (�I�[�o�[���C�h�K�{)
	virtual void       Sound(float _deltaTime)  = 0;    // ���y	  (�I�[�o�[���C�h�K�{)
	virtual void       Load()                   = 0;    // ������ (�I�[�o�[���C�h�K�{)

	protected:
	int mVolumePal     ;    // ����
	int mNormalFontSize;    // �t�H���g�T�C�Y
};