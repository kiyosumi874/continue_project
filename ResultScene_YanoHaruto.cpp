#include "DxLib.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"

/// <summary>
/// 初期化
/// </summary>
ResultScene_YanoHaruto::ResultScene_YanoHaruto(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mScore(_score)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene_YanoHaruto::~ResultScene_YanoHaruto()
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
SceneBase* ResultScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// デバッグ用
	printfDx("今ResultScene_YanoHaruto\n");

	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new TitleScene_YanoHaruto();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void ResultScene_YanoHaruto::Draw()
{
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene_YanoHaruto::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene_YanoHaruto::Load()
{
}
