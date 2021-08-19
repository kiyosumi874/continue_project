#include "DxLib.h"
#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "PlayUI.h"
#include "PlayCamera.h"
#include "BGM.h"

/// <summary>
/// 初期化
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mPlayCamera(nullptr)
	, mPlayUI(nullptr)
	, mGameCountFlag3(true)
	, mScore(0)
	, mPlayCircleGameFlag(true)
	, mPlayGaugeGameFlag(false)
	, mPlayPendulumGameFlag(false)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGM(nullptr)
	, mBGMFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
{
	delete mPlayCamera;
	delete mPlayUI;
	delete mBGM;
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
	mDeltaTime = _deltaTime / 1000000.0f;
	// プレイカメラの更新
	mPlayCamera->Update();

	// プレイUIの更新
	mPlayUI->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();

	mScore = mPlayUI->GetScore();

	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= 400.0f * mDeltaTime;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (!mGameCountFlag3)
	{
		mAlphaPal += 400.0f * mDeltaTime;
	}
	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new ResultScene_kiyosumi(mScore);
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
void PlayScene_kiyosumi::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// プレイカメラの描画
	mPlayCamera->Draw();
	// プレイUIの描画
	mPlayUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene_kiyosumi::Sound()
{
	if (!mGameCountFlag3)
	{
		mBGM->FadeOutMusic(500, mDeltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, mDeltaTime);
	}
	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
	mPlayUI->Sound();
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene_kiyosumi::Load()
{
	////「読み込み中」の表示
	//DrawString(0, 0, "Now Loading ...", GetColor(255, 255, 255));
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	// プレイカメラの初期化
	mPlayCamera->Load();
	// プレイUIの初期化
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
}
