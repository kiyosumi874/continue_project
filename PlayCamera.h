//----------------------------------------------------------------------------------//
// @file         PlayCamera.h
// @brief        PlayCamera�N���X
// @note         �p����:CameraBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/ 2    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase.h"

class PlayCamera : public CameraBase
{
public:
	 PlayCamera();    // �R���X�g���N�^
	~PlayCamera();    // �f�X�g���N�^

	void Update()                override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��
	VECTOR SetTargetPos(const VECTOR& _pos) { return mCameraTarget = _pos; };

private:
	VECTOR mCameraPosition;    // �J�����̈ʒu
	VECTOR mCameraTarget;      // �J�����̒����_( ���Ă�����W )
	VECTOR mCameraUp;          // �J�����̏����

};