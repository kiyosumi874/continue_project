#include "PlayerActor_kiyosumi.h"
/// <summary>
/// 初期化
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
/// 後処理
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
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 0/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	// debug
	if (mPosition.x <= 3.0f)
	{
		mPosition.x += 1.0f * _deltaTime;
		// プレイヤーを動かすときはこのフラグをtrue
		mRecomputeWorldTransform = true;
	}
	else
	{
		mPosition.x = 0.0f;
		// プレイヤーを動かすときはこのフラグをtrue
		mRecomputeWorldTransform = true;
	}

	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::TitleJumpBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 1/*Jumpのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// ジャンプアニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::PlayIdleBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 0/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}

void PlayerActor_kiyosumi::ResultIdleBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mAttachIndex = MV1AttachAnim(mMHandle, 0/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mTotalTime);
}
