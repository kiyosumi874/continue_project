//----------------------------------------------------------------------------------//
// @file         UIBase.h
// @brief        UIBase�N���X
// @note         UIBase�N���X
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

// UI�x�[�X�N���X
class UIBase
{
public:
	         UIBase()   ;    // �R���X�g���N�^
	virtual ~UIBase() {};    // ���z�f�X�g���N�^

	virtual void Update(float _deltaTime) = 0;    // �V�[���̍X�V���� (�I�[�o�[���C�h�K�{)
	virtual void Draw()                   = 0;    // �V�[���̕`�揈�� (�I�[�o�[���C�h�K�{)
	virtual void Load()                   = 0;    // ������ (�I�[�o�[���C�h�K�{)
protected:
	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
};