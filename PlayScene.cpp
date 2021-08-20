#include "PlayScene.h"
#include "ResultScene.h"
#include "PlayUI.h"
#include "PlayCamera.h"
#include "BGM.h"
#include "Audience.h"
#include "Pool.h"
#include "Player.h"


/// <summary>
/// 初期化
/// </summary>
PlayScene::PlayScene()
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
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPool(nullptr)
	, mAudience(nullptr)
	, mPlayer(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene::~PlayScene()
{
	delete mPlayCamera;
	delete mPlayUI;
	delete mBGM;
	delete mPool;
	delete mAudience;
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
SceneBase* PlayScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	// プレイカメラの更新
	mPlayCamera->Update();
	//観客の更新
	mAudience->Update();
	// プレイUIの更新
	mPlayUI->Update(mDeltaTime);
	// プレイヤーの更新
	mPlayer->Update(mDeltaTime);
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	// プレイヤーモーション開始
	mPlayer->SetFlag(mGameCountFlag3);

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
		return new ResultScene(mScore);
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void PlayScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mAudience->Draw();
	mPool->Draw();
	// プレイヤーの描画
	mPlayer->Draw();
	// プレイUIの描画
	mPlayUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void PlayScene::Sound()
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
void PlayScene::Load()
{
	mPlayCamera = new PlayCamera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new Pool;
	mAudience = new Audience;
	mPlayer = new Player;
	// プレイカメラの初期化
	mPlayCamera->Load();
	mTargetPos = mAudience->mGetAudiencePos();
	mPlayCamera->SetTargetPos(mTargetPos);
	// プレイUIの初期化
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
}
