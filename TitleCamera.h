//----------------------------------------------------------------------------------//
// @file         TitleCamera.h
// @brief        TitleCamera�N���X
// @note         �p����:CameraBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/ 2    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase.h"


class TitleCamera : public CameraBase
{
public:
	 TitleCamera();    // �R���X�g���N�^
	~TitleCamera();    // �f�X�g���N�^

	void Update()                override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	VECTOR SetTargetPos(const VECTOR& _pos) { return mCameraTarget = _pos; };

private:
	VECTOR mCameraPosition;    // �J�����̈ʒu
	VECTOR mCameraTarget;      // �J�����̒����_( ���Ă�����W )
	VECTOR mCameraUp;          // �J�����̏����


};