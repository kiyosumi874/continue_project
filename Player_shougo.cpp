#include "DxLib.h"
#include "Player_shougo.h"



/// <summary>
/// ������
/// </summary>
Player_shougo::Player_shougo()
	: mDeltaTime(0.000001f)
	, mModelHandle(MV1LoadModel("data/model/swim/player.pmx"))
	, mAttachIndex(MV1AttachAnim(mModelHandle,0,-1,FALSE))
	, mTotalTime(MV1GetAttachAnimTotalTime(mModelHandle,mAttachIndex))
	, mPlayTime(0.0f)
{
	MV1SetPosition(mModelHandle, VGet(0, -10, 20));
}

/// <summary>
/// �㏈��
/// </summary>
Player_shougo::~Player_shougo()
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime"></param>
void Player_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	mPlayTime += 1.0f;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ�0�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
	MV1SetPosition(mModelHandle, VGet(0, -10, 20));
}

/// <summary>
/// �`�揈��
/// </summary>
void Player_shougo::Draw()
{
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// ������
/// </summary>
void Player_shougo::Load()
{
}
