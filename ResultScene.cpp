#include "DxLib.h"
#include "ResultScene.h"
#include "TitleScene.h"

/// <summary>
/// 初期化
/// </summary>
ResultScene::ResultScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene::~ResultScene()
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
SceneBase* ResultScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// デバッグ用
	printfDx("今ResultScene\n");

	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new TitleScene();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void ResultScene::Draw()
{
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene::Load()
{
}
