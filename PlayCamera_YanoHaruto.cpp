#include "DxLib.h"
#include "PlayCamera_YanoHaruto.h"

// SetCameraNearFar�̈���
#define NEAR  1.0f
#define FAR   150.0f

/// <summary>
/// ������
/// </summary>
PlayCamera_YanoHaruto::PlayCamera_YanoHaruto()
	: mCameraPosition(VGet(45.0f, 53.0f, -18.0f))//�ϋq(-30.0f, 15.0f, -30.0f)pool(45.0f, 53.0f, -18.0f)
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR,FAR);
}

/// <summary>
/// �㏈��
/// </summary>
PlayCamera_YanoHaruto::~PlayCamera_YanoHaruto()
{
}

/// <summary>
/// �X�V
/// </summary>
void PlayCamera_YanoHaruto::Update()
{
	
}

/// <summary>
/// ���[�h
/// </summary>
void PlayCamera_YanoHaruto::Load()
{
}

/// <summary>
/// �`�揈��
/// </summary>
void PlayCamera_YanoHaruto::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}

