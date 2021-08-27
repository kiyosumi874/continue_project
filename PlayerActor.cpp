#include "PlayerActor.h"
/// <summary>
/// ������
/// </summary>
PlayerActor::PlayerActor()
	: Actor()
	, mAttachIndex(0)
	, mTotalTime(0)
	, mPlayTime(0)
	, mGameCountFlag1(true)
	, mGameCountFlag2(true)
	, mGameCountFlag3(true)
	, mNowState(PLAYER_STATE::STATE_TITLE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_NUM)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayerActor::~PlayerActor()
{
}

/// <summary>
/// 
/// </summary>
/// <param name="_deltaTime"></param>
void PlayerActor::UpdateActor(float _deltaTime)
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

	case PLAYER_STATE::STATE_PLAY_GAME1:
		PlayGame1Behavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_GAME2:
		PlayGame2Behavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_GAME3:
		PlayGame3Behavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_RESULT_IDLE:
		ResultIdleBehavior(_deltaTime);
		break;

	default:
		break;
	}
}

void PlayerActor::LoadGameCount(bool _gameCountFlag1, bool _gameCountFlag2, bool _gameCountFlag3)
{
	mGameCountFlag1 = _gameCountFlag1;
	mGameCountFlag2 = _gameCountFlag2;
	mGameCountFlag3 = _gameCountFlag3;
}

void PlayerActor::TitleIdleBehavior(float _deltaTime)
{
	// ���̍��W�Ɍ��݂̍��W����
	VECTOR tmpPos = mPosition;
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
	if (tmpPos.x <= 3.0f)
	{
		tmpPos.x += 1.0f * _deltaTime;
	}
	else
	{
		tmpPos.x = 0.0f;
	}

	// ���W���X�V����Ă�����
	if ((tmpPos.x != mPosition.x) || (tmpPos.y != mPosition.y) || (tmpPos.z != mPosition.z))
	{
		// �X�V���̍��W��Set
		SetPosition(tmpPos);
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::TitleJumpBehavior(float _deltaTime)
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayIdleBehavior(float _deltaTime)
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
	if (!mGameCountFlag1)
	{
		mNowState = PLAYER_STATE::STATE_PLAY_GAME1;
		return;
	}
	

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame1Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 2/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	if (!mGameCountFlag2)
	{
		mNowState = PLAYER_STATE::STATE_PLAY_GAME2;
		return;
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame2Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 3/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	if (!mGameCountFlag3)
	{
		mNowState = PLAYER_STATE::STATE_PLAY_GAME3;
		return;
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame3Behavior(float _deltaTime)
{
	VECTOR tmpPos = mPosition;
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 2/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	tmpPos.y += 50 * _deltaTime;

	// ���W���X�V����Ă�����
	if ((tmpPos.x != mPosition.x) || (tmpPos.y != mPosition.y) || (tmpPos.z != mPosition.z))
	{
		// �X�V���̍��W��Set
		SetPosition(tmpPos);
	}
	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}


void PlayerActor::ResultIdleBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 1/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}
