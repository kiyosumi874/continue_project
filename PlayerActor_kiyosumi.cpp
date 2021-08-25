#include "PlayerActor_kiyosumi.h"

PlayerActor_kiyosumi::PlayerActor_kiyosumi()
	: Actor()
	, mAttachIndex(0)
	, mTotalTime(0)
	, mPlayTime(0)
	, mJumpFlag(false)
	, mNowState(PLAYER_STATE::STATE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_IDLE)
{
}

PlayerActor_kiyosumi::~PlayerActor_kiyosumi()
{
}

void PlayerActor_kiyosumi::UpdateActor(float _deltaTime)
{
	switch (mNowState)
	{
	case PLAYER_STATE::STATE_IDLE:
		IdleBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_JUMP:
		JumpBehavior(_deltaTime);
		break;

	default:
		break;
	}
}

void PlayerActor_kiyosumi::IdleBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 0/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::JumpBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 1/*Jump�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}
