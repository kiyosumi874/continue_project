#include "DxLib.h"
#include "PlayScene_shougo.h"
#include "ResultScene_shougo.h"
#include "PlayUI.h"
#include "PlayCamera_shougo.h"
#include "Object_shougo.h"
#include "Player.h"

/// <summary>
/// 初期化
/// </summary>
PlayScene_shougo::PlayScene_shougo()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
	, mPlayUI(nullptr)
	, mObject(nullptr)
	, mPlayer(nullptr)
	, mGameCountFlag3(true)
	, mScore(0)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_shougo::~PlayScene_shougo()
{
	delete mPlayCamera;
	delete mPlayUI;
	delete mObject;
	delete mPlayer;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* PlayScene_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// プレイUIの更新
	mPlayUI->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	mScore = mPlayUI->GetScore();

	// プレイヤーの更新
	mPlayer->Update(mDeltaTime);

	mPlayCamera->SetTargetPosition(mPlayer->PlayerGetPosition());

	// プレイカメラの更新
	mPlayCamera->Update();

	// シーン遷移条件
	if (!mGameCountFlag3)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new ResultScene_shougo(mScore);
	}

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
void PlayScene_shougo::Draw()
{
	// プレイカメラの描画
	mPlayCamera->Draw();
	// プレイヤーの描画
	mPlayer->Draw();
	// ステージの描画
	mObject->Draw();
	// プレイUIの描画
	mPlayUI->Draw();
	
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene_shougo::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene_shougo::Load()
{
	mPlayCamera = new PlayCamera_shougo;
	mPlayUI = new PlayUI;
	mObject = new Object_shougo;
	mPlayer = new Player;
	// プレイカメラの初期化
	mPlayCamera->Load();
	// プレイUIの初期化
	mPlayUI->Load();
}
