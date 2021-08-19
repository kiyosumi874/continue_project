#include "DxLib.h"
#include "PlayCamera.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 200.0f

/// <summary>
/// ������
/// </summary>
PlayCamera::PlayCamera()
	: mCameraPosition(VGet(45.0f, 53.0f, -18.0f))//�ϋq�S��(-30.0f, 15.0f, -30.0f)���(-38.5f, 12.0f, -35.0f)pool(45.0f, 53.0f, -18.0f)
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
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
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
}

