#include "PlayerActor.h"
/// <summary>
/// 初期化
/// </summary>
PlayerActor::PlayerActor()
	: Actor()
	, mAttachIndex(0)
	, mTotalTime(0)
	, mPlayTime(0)
	, mNowState(PLAYER_STATE::STATE_TITLE_IDLE)
	, mPrevState(PLAYER_STATE::STATE_NUM)
{
}

/// <summary>
/// 後処理
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
//-----------------------------
// 0->Idle,1->また開きジャンプ,2->run,3->飛び込み,4->体操
//--------------------------
void PlayerActor::TitleIdleBehavior(float _deltaTime)
{
	// 仮の座標に現在の座標を代入
	VECTOR tmpPos = mPosition;
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
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
	/*if (tmpPos.x <= 3.0f)
	{
		tmpPos.x += 1.0f * _deltaTime;
	}
	else
	{
		tmpPos.x = 0.0f;
	}*/

	// 座標が更新されていたら
	if ((tmpPos.x != mPosition.x) || (tmpPos.y != mPosition.y) || (tmpPos.z != mPosition.z))
	{
		// 更新分の座標のSet
		SetPosition(tmpPos);
	}

	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayIdleBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayRunBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 2/*Idleのアニメーション番号*/, -1, FALSE);
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame1Behavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}

	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame2Behavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}

	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayGame3Behavior(float _deltaTime)
{

	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 4/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0;
	}


	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor::PlayJumpBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 3/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = mTotalTime;
	}


	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}


void PlayerActor::ResultIdleBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 1/*Idleのアニメーション番号*/, -1, FALSE);
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
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}
