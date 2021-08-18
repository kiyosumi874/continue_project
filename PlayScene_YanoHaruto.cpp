#include "DxLib.h"
#include "Audience.h"
#include "ResultScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"
#include "PlayCamera_YanoHaruto.h"
#include "Pool.h"

/// <summary>
/// 初期化
/// </summary>
PlayScene_YanoHaruto::PlayScene_YanoHaruto()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
	mTargetPos = VGet(0.0f, 0.0f, 0.0f);
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_YanoHaruto::~PlayScene_YanoHaruto()
{
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* PlayScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	//プレイカメラの更新
	mPlayCamera->Update();
	//観客の更新
	mAudience->Update();
	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// デバッグ用
	printfDx("今PlayScene_YanoHaruto\n");

	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new ResultScene_YanoHaruto();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画8/12追加
/// </summary>
void PlayScene_YanoHaruto::Draw()
{
	mAudience->Draw();
	mPool->Draw();
	mPlayCamera->Draw();
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene_YanoHaruto::Sound()
{
}

/// <summary>
/// 初期化8/12追記
/// </summary>
void PlayScene_YanoHaruto::Load()
{	
	mPool = new Pool;
	mAudience = new Audience;
	mPlayCamera = new PlayCamera_YanoHaruto;
	mTargetPos = mAudience->mGetAudiencePos();
	mPlayCamera->mSetTargetPos(mTargetPos);
}
