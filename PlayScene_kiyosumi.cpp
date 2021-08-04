#include "DxLib.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "PlayUI.h"
#include "PlayCamera.h"

/// <summary>
/// 初期化
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
	, mPlayUI(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
{
	delete mPlayCamera;
	delete mPlayUI;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* PlayScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// プレイカメラの更新
	mPlayCamera->Update();

	// プレイUIの更新
	mPlayUI->Update(mDeltaTime);

	//// Enterキーの連続入力防止
	//if (!CheckHitKey(KEY_INPUT_RETURN))
	//{
	//	mInputReturnFlag = true;
	//}

	//// シーン遷移条件
	//if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	//{
	//	mInputReturnFlag = false;
	//	// 条件を満たしていたら次のシーンを生成してそのポインタを返す
	//	return new ResultScene_kiyosumi();
	//}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void PlayScene_kiyosumi::Draw()
{
	// プレイカメラの描画
	mPlayCamera->Draw();
	// プレイUIの描画
	mPlayUI->Draw();
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene_kiyosumi::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene_kiyosumi::Load()
{
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	// プレイカメラの初期化
	mPlayCamera->Load();
	// プレイUIの初期化
	mPlayUI->Load();
}
