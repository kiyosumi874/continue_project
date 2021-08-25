#include "Player.h"



/// <summary>
/// 初期化
/// </summary>
Player::Player()
//                          固定   Playerの前後
	: mPlayerPos(VGet(0.0f, 32.0f, -16.0f))
	, mDeltaTime(0.000001f)
	, mModelHandle(MV1LoadModel("data/model/player5/waterboy.pmx"))
	, mAttachIndex(NULL)
	, mTotalTime(NULL)
	, mPlayTime(0.0f)
	, mJumpFlag(false)
	, mPlayFlag(true)
	, mScale(VGet(0.5f,0.5f,0.5f))
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1SetScale(mModelHandle, mScale);
	mAttachIndex = MV1AttachAnim(mModelHandle, 0, -1, FALSE);
	mTotalTime = MV1GetAttachAnimTotalTime(mModelHandle, mAttachIndex);
}

/// <summary>
/// 後処理
/// </summary>
Player::~Player()
{
	MV1DeleteModel(mModelHandle);
	MV1DetachAnim(mModelHandle, mAttachIndex);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime"></param>
void Player::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	if (mPlayFlag == false)
	{
		if (mPlayerPos.z < -17.f && mJumpFlag == false)
		{
			if (mPlayerPos.y > 35.0f)
			{
				mJumpFlag = true;
			}

			mPlayerPos.y += 5.0f * mDeltaTime;
		}

		if (mJumpFlag == true) //飛び込み処理
		{
			mPlayerPos.y -= 20.0f * mDeltaTime;
		}
		else
		{
			mPlayerPos.z -= 10.0f * mDeltaTime;
		}

		// 再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
		if (mPlayTime >= mTotalTime)
		{
			mPlayTime = mTotalTime;
		}
		else
		{
			mPlayTime += 40.0f * mDeltaTime;
		}
		mAttachIndex = MV1AttachAnim(mModelHandle, 0, -1, FALSE);
	}
	if(mPlayFlag == true)
	{
		mPlayTime += 15.0f * mDeltaTime;
		if (mPlayTime >= mTotalTime)
		{
			mPlayTime = 0.0f;
		}
		mAttachIndex = MV1AttachAnim(mModelHandle, 1, -1, FALSE);
	}

	// 再生時間をセットする
	MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
	MV1SetPosition(mModelHandle, mPlayerPos);

}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw()
{
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Player::Load()
{
}
