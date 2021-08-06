#include "DxLib.h"
#include "TitleCamera_shougo.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// ������
/// </summary>
TitleCamera_shougo::TitleCamera_shougo()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// �㏈��
/// </summary>
TitleCamera_shougo::~TitleCamera_shougo()
{
}

/// <summary>
/// �X�V����
/// </summary>
void TitleCamera_shougo::Update()
{
}

/// <summary>
/// ���[�h
/// </summary>
void TitleCamera_shougo::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void TitleCamera_shougo::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
