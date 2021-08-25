#include "DxLib.h"
#include "TitleCamera.h"

//---------------------------------------------
// �萔
const float CAMERA_NEAR = 1.0f;
const float CAMERA_FAR  = 150.0f;
const VECTOR CAMERA_POSITION = VGet(0.0f, 0.0f, -1.0f);
const VECTOR CAMERA_TARGET = VGet(0.0f, 0.0f, 0.0f);
const VECTOR CAMERA_UP = VGet(0.0f, 1.0f, 0.0f);
//---------------------------------------------

/// <summary>
/// ������
/// </summary>
TitleCamera::TitleCamera()
	: mCameraPosition(CAMERA_POSITION)
	, mCameraTarget(CAMERA_TARGET)
	, mCameraUp(CAMERA_UP)
{
	SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
}

/// <summary>
/// �㏈��
/// </summary>
TitleCamera::~TitleCamera()
{
}

/// <summary>
/// �X�V����
/// </summary>
void TitleCamera::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void TitleCamera::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void TitleCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
