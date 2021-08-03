#include "DxLib.h"
#include "TitleCamera.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
TitleCamera::TitleCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -2.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
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
