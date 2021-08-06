//----------------------------------------------------------------------------------//
// @file         CameraBase_shougo.h
// @brief        CameraBase_shougo�N���X
// @note         CameraBase_shougo�N���X
// @author       ��� �Č�  (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

// UI�x�[�X�N���X
class CameraBase_shougo
{
public:
	CameraBase_shougo() {};    // �R���X�g���N�^
	virtual ~CameraBase_shougo() {};    // ���z�f�X�g���N�^

	virtual void Update() = 0;    // �V�[���̍X�V���� (�I�[�o�[���C�h�K�{)
	virtual void Draw() = 0;    // �V�[���̕`�揈�� (�I�[�o�[���C�h�K�{)
	virtual void Load() = 0;    // ������ (�I�[�o�[���C�h�K�{)
};
