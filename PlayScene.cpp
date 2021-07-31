#include "DxLib.h"
#include "PlayScene.h"
#include "ResultScene.h"

/// <summary>
/// 初期化
/// </summary>
PlayScene::PlayScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene::~PlayScene()
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
SceneBase* PlayScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	// デバッグ用
	printfDx("今PlayScene\n");

	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new ResultScene();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void PlayScene::Draw()
{
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene::Load()
{
}
