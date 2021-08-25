#include "DxLib.h"

#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"

/// <summary>
/// 初期化
/// </summary>
TitleScene_YanoHaruto::TitleScene_YanoHaruto()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
TitleScene_YanoHaruto::~TitleScene_YanoHaruto()
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
SceneBase* TitleScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// デバッグ用
	printfDx("今TitleSceneYano\n");

	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new PlayScene_YanoHaruto();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void TitleScene_YanoHaruto::Draw()
{
}

/// <summary>
/// 音楽
/// </summary>
void TitleScene_YanoHaruto::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene_YanoHaruto::Load()
{
}
