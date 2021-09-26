#include "PlayerActor.h"
#include "Effect.h"
/// <summary>
/// ������
/// </summary>
PlayerActor::PlayerActor()
	: Actor()
	, mAttachIndex(0)
	, mTotalTime(0)
	, mPlayTime(0)
	, mNowState(PLAYER_STATE::STATE_TITLE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_NUM)
	, mAura(nullptr)
	, mWind(nullptr)
{
	mAura = new Effect("data/effect/Aura.efk", 3.0f);
	mWind = new Effect("data/effect/Wind.efk", 1.0f);
}

/// <summary>
/// �㏈��
/// </summary>
PlayerActor::~PlayerActor()
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
void PlayerActor::UpdateActor(float _deltaTime)
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

	case PLAYER_STATE::STATE_PLAY_JUMP2:
		PlayJump2Behavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_PLAY_FLOAT:
		PlayFloatBehavior(_deltaTime);
		break;

	case PLAYER_STATE::STATE_RESULT_IDLE:
		ResultIdleBehavior(_deltaTime);
		break;

	default:
		break;
	}
}
//-----------------------------
// 0->Idle,1->�܂��J���W�����v,2->run,3->��э���,4->�̑�
// 5->��񑫎�,6->��э���,7->����,8->���L,9->�[�ċz
//--------------------------
void PlayerActor::TitleIdleBehavior(float _deltaTime)
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

void PlayerActor::PlayIdleBehavior(float _deltaTime)
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

void PlayerActor::PlayRunBehavior(float _deltaTime)
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

void PlayerActor::PlayGame1Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 5/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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

void PlayerActor::PlayGame2Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 9/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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

void PlayerActor::PlayGame3Behavior(float _deltaTime)
{

	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 8/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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

void PlayerActor::PlayJumpBehavior(float _deltaTime)
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
		mAttachIndex = MV1AttachAnim(mMHandle, 6/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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

void PlayerActor::PlayJump2Behavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 10/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
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


void PlayerActor::PlayFloatBehavior(float _deltaTime)
{
	// ���߂Ă��̃X�e�[�g�ɓ���ꍇ
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 7/*Idle�̃A�j���[�V�����ԍ�*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 20.0f * _deltaTime;
	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
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
