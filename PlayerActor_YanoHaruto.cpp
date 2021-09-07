
#include "PlayerActor_YanoHaruto.h"
#include "Effect.h"

/// <summary>
/// 初期化
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
/// 後処理
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
// 0->Idle,1->また開きジャンプ,2->run,3->飛び込み,4->体操
//--------------------------
void PlayerActor_YanoHaruto::TitleIdleBehavior(float _deltaTime)
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

void PlayerActor_YanoHaruto::PlayIdleBehavior(float _deltaTime)
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

void PlayerActor_YanoHaruto::PlayRunBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		//エフェクト追加
		//-----------------------------------------------------------------
		mAura->PlayEffekseer(mPosition);
		//-----------------------------------------------------------------

		MV1DetachAnim(mMHandle, mAttachIndex);
		mPlayTime = 0;
		mAttachIndex = MV1AttachAnim(mMHandle, 2/*Idleのアニメーション番号*/, -1, FALSE);
		mTotalTime = MV1GetAttachAnimTotalTime(mMHandle, mAttachIndex);
		mPrevState = mNowState;
	}
	//エフェクト追加
	//-----------------------------------------------------------------
	mAura->SetPlayingEffectPos(mPosition);
	//-----------------------------------------------------------------
	mPlayTime += 50.0f * _deltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}


	// 待機アニメーション再生
	MV1SetAttachAnimTime(mMHandle, mAttachIndex, mPlayTime);
}

void PlayerActor_YanoHaruto::PlayGame1Behavior(float _deltaTime)
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

void PlayerActor_YanoHaruto::PlayGame2Behavior(float _deltaTime)
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

void PlayerActor_YanoHaruto::PlayGame3Behavior(float _deltaTime)
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

void PlayerActor_YanoHaruto::PlayJumpBehavior(float _deltaTime)
{
	// 初めてこのステートに入る場合
	if (mNowState != mPrevState)
	{
		//エフェクト追加
		//-----------------------------------------------------------------
		mWind->PlayEffekseer(mPosition);
		//-----------------------------------------------------------------
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


void PlayerActor_YanoHaruto::ResultIdleBehavior(float _deltaTime)
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
