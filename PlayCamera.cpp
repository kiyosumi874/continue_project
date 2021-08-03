#include "DxLib.h"
#include "PlayCamera.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
PlayCamera::PlayCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -2.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// �㏈��
/// </summary>
PlayCamera::~PlayCamera()
{
}

/// <summary>
/// �X�V
/// </summary>
void PlayCamera::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void PlayCamera::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void PlayCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}

