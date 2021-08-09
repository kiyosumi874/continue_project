#include "DxLib.h"
#include "Player_shougo.h"



/// <summary>
/// 初期化
/// </summary>
Player_shougo::Player_shougo()
	: mDeltaTime(0.000001f)
	, mModelHandle(MV1LoadModel("data/model/swim/player.pmx"))
	, mAttachIndex(MV1AttachAnim(mModelHandle,0,-1,FALSE))
	, mTotalTime(MV1GetAttachAnimTotalTime(mModelHandle,mAttachIndex))
	, mPlayTime(0.0f)
{
	MV1SetPosition(mModelHandle, VGet(0, -10, 20));
}

/// <summary>
/// 後処理
/// </summary>
Player_shougo::~Player_shougo()
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime"></param>
void Player_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	mPlayTime += 1.0f;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を0に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// 再生時間をセットする
	MV1SetAttachAnimTime(mModelHandle, mAttachIndex, mPlayTime);
	MV1SetPosition(mModelHandle, VGet(0, -10, 20));
}

/// <summary>
/// 描画処理
/// </summary>
void Player_shougo::Draw()
{
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// 初期化
/// </summary>
void Player_shougo::Load()
{
}
