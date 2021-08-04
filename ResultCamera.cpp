#include "DxLib.h"
#include "ResultCamera.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
ResultCamera::ResultCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// �㏈��
/// </summary>
ResultCamera::~ResultCamera()
{
}

/// <summary>
/// �X�V
/// </summary>
void ResultCamera::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void ResultCamera::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void ResultCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
