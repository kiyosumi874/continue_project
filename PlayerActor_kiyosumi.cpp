#include "PlayerActor_kiyosumi.h"
/// <summary>
/// ������
/// </summary>
PlayerActor_kiyosumi::PlayerActor_kiyosumi()
	: Actor()
	, mAttachIndex(0)
	, mTotalTime(0)
	, mPlayTime(0)
	, mJumpFlag(false)
	, mNowState(PLAYER_STATE::STATE_TITLE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_TITLE_IDLE)
{
}
/// <summary>
/// �㏈��
/// </summary>
PlayerActor_kiyosumi::~PlayerActor_kiyosumi()
{
}

/// <summary>
/// 
/// </summary>
/// <param name="_deltaTime"></param>
void PlayerActor_kiyosumi::UpdateActor(float _deltaTime)
{
	switch (mNowState)
	{
	case PLAYER_STATE::STATE_TITLE_IDLE:
		TitleIdleBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_TITLE_JUMP:
		TitleJumpBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_IDLE:
		PlayIdleBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_RESULT_IDLE:
		ResultIdleBehavior(_deltaTime);
		break;

	default:
		break;
	}
}

void PlayerActor_kiyosumi::TitleIdleBehavior(float _deltaTime)
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

	// debug
	if (mPosition.x <= 3.0f)
	{
		mPosition.x += 1.0f * _deltaTime;
		// �v���C���[�𓮂����Ƃ��͂��̃t���O��true
		mRecomputeWorldTransform = true;
	}
	else
	{
		mPosition.x = 0.0f;
		// �v���C���[�𓮂����Ƃ��͂��̃t���O��true
		mRecomputeWorldTransform = true;
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::TitleJumpBehavior(float _deltaTime)
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
	// �W�����v�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::PlayIdleBehavior(float _deltaTime)
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

void PlayerActor_kiyosumi::ResultIdleBehavior(float _deltaTime)
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
