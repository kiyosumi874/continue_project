#include "DxLib.h"
#include "PlayCamera_shougo.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
PlayCamera_shougo::PlayCamera_shougo()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// �㏈��
/// </summary>
PlayCamera_shougo::~PlayCamera_shougo()
{
}

/// <summary>
/// �X�V
/// </summary>
void PlayCamera_shougo::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void PlayCamera_shougo::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void PlayCamera_shougo::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
