#include "PlayScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "PlayUI.h"
#include "Camera.h"
#include "BGM.h"
#include "Audience.h"
#include "Pool.h"
#include "PlayerActor.h"

const VECTOR   PLAY_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   PLAY_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   PLAY_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);

/// <summary>
/// 初期化
/// </summary>
PlayScene::PlayScene()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mCamera(nullptr)
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
	, mFadeSpeed(3)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene::~PlayScene()
{
	//delete mPlayCamera;
	delete mCamera;
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
	//観客の更新
	mAudience->Update(0);
	// プレイUIの更新
	mPlayUI->Update(mDeltaTime);
	// プレイヤーの更新
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE);
	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// カメラの更新
	mCamera->Update(PLAY_CAMERA_POS, mTargetPos);

	// 振り子ゲーム終了のフラグ
	mGameCountFlag3 = mPlayUI->GetGameCountFlag3();
	//// プレイヤーモーション開始
	//mPlayer->SetFlag(mGameCountFlag3);

	mScore = mPlayUI->GetScore();

	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (!mGameCountFlag3)
	{
		mAlphaPal += mFadeSpeed;
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
	mCamera = new Camera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new Pool;
	mAudience = new Audience;
	mPlayer = new PlayerActor;

	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale   (PLAY_PLAYER_SCALE);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	mPlayer->SetPosition(PLAY_PLAYER_POS);

	mTargetPos = mAudience->mGetAudiencePos();

	// プレイUIの初期化
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
}
