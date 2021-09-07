
#include "PlayerActor_YanoHaruto.h"
#include "Effect.h"

/// <summary>
/// ������
/// </summary>
PlayerActor_YanoHaruto::PlayerActor_YanoHaruto()
	: Actor()
	, mAttachIndex(0)
	, mAura(nullptr)
	, mTotalTime(0)
	, mPlayTime(0)
	, mNowState(PLAYER_STATE::STATE_TITLE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_NUM)
	, mWind(nullptr)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayerActor_YanoHaruto::~PlayerActor_YanoHaruto()
{
	mAura->StopEffect3D();
	mAura->Delete();
	delete mAura;
	mWind->StopEffect3D();
	mWind->Delete();
	delete mWind;
}

/// <summary>
/// 
/// </summary>
/// <param name="_deltaTime"></param>
void PlayerActor_YanoHaruto::UpdateActor(float _deltaTime)
{
	switch (mNowState)
	{
	case PLAYER_STATE::STATE_TITLE_IDLE:
		TitleIdleBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_IDLE:
		PlayIdleBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_RUN:
		PlayRunBehavior(_deltaTime);
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

	case PLAYER_STATE::STATE_PLAY_JUMP:
		PlayJumpBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_RESULT_IDLE:
		ResultIdleBehavior(_deltaTime);
		break;

	default:
		break;
	}
}
void PlayerActor_YanoHaruto::Load()
{
	mAura = new Effect("data/effect/Aura.efk", 3.0f);
	mWind = new Effect("data/effect/Wind.efk", 1.0f);
}
//-----------------------------
// 0->Idle,1->�܂��J���W�����v,2->run,3->��э���,4->�̑�
//--------------------------
void PlayerActor_YanoHaruto::TitleIdleBehavior(float _deltaTime)
{
	// ���̍��W�Ɍ��݂̍��W����
	VECTOR tmpPos = mPosition;
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
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
	/*if (tmpPos.x <= 3.0f)
	{
		tmpPos.x += 1.0f * _deltaTime;
	}
	else
	{
		tmpPos.x = 0.0f;
	}*/

	// ���W���X�V����Ă�����
	if ((tmpPos.x != mPosition.x) || (tmpPos.y != mPosition.y) || (tmpPos.z != mPosition.z))
	{
		// �X�V���̍��W��Set
		SetPosition(tmpPos);
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayIdleBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayRunBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		//�G�t�F�N�g�ǉ�
		//-----------------------------------------------------------------
		mAura->PlayEffekseer(mPosition);
		//-----------------------------------------------------------------

		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 2/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	//�G�t�F�N�g�ǉ�
	//-----------------------------------------------------------------
	mAura->SetPlayingEffectPos(mPosition);
	//-----------------------------------------------------------------
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}


	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayGame1Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayGame2Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}

	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayGame3Behavior(float _deltaTime)
{

	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}


	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayJumpBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		//�G�t�F�N�g�ǉ�
		//-----------------------------------------------------------------
		mWind->PlayEffekseer(mPosition);
		//-----------------------------------------------------------------
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 3/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = mTotalTime;
	}


	// �ҋ@�A�j���[�V�����Đ�
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}


void PlayerActor_YanoHaruto::ResultIdleBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
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
