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
	, mScale(VGet(0.5f, 0.5f, 0.5f))
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1SetScale(mModelHandle, mScale);
	//MV1AttachAnim(mModelHandle,0,-1,FALSE)
	//MV1GetAttachAnimTotalTime(mModelHandle,mAttachIndex)
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

	//mPlayTime += 0.5f;

	//if (mPlayerPos.z < 30 && mJumpFlag == false)
	//{
	//	mJumpFlag = true;
	//	mPlayerPos.y += 5;
	//}

	//if (mJumpFlag == true) //地面にめり込まない処理
	//{
	//	mPlayerPos.y -= 0.4;		
	//}
	//else
	//{
	//	mPlayerPos.z -= 0.1;
	//}

	// 再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}

	// 再生時間をセットする
	//MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
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
