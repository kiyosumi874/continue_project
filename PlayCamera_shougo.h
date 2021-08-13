//----------------------------------------------------------------------------------//
// @file         PlayCamera_shougo.h
// @brief        PlayCamera_shougo�N���X
// @note         �p����:CameraBase_shougo�N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase_shougo.h"

class PlayCamera_shougo : public CameraBase_shougo
{
public:
	PlayCamera_shougo();    // �R���X�g���N�^
	~PlayCamera_shougo();    // �f�X�g���N�^

	void Update()                override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	void SetTargetPosition(const VECTOR& _targetPos) { mCameraTarget = _targetPos; }

private:
	VECTOR mCameraPosition;    // �J�����̈ʒu
	VECTOR mCameraTarget;      // �J�����̒����_( ���Ă�����W )
	VECTOR mCameraUp;          // �J�����̏����
};
