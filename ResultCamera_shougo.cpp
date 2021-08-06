#include "DxLib.h"
#include "ResultCamera_shougo.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
ResultCamera_shougo::ResultCamera_shougo()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// �㏈��
/// </summary>
ResultCamera_shougo::~ResultCamera_shougo()
{
}

/// <summary>
/// �X�V
/// </summary>
void ResultCamera_shougo::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void ResultCamera_shougo::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void ResultCamera_shougo::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}