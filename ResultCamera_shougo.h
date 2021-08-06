//----------------------------------------------------------------------------------//
// @file         ResultCamera_shoguo.h
// @brief        ResultCamera_shougo�N���X
// @note         �p����:CameraBase�N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase_shougo.h"

class ResultCamera_shougo : public CameraBase_shougo
{
public:
	ResultCamera_shougo();    // �R���X�g���N�^
	~ResultCamera_shougo();    // �f�X�g���N�^

	void Update()                override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

private:
	VECTOR mCameraPosition;    // �J�����̈ʒu
	VECTOR mCameraTarget;      // �J�����̒����_( ���Ă�����W )
	VECTOR mCameraUp;          // �J�����̏����

};