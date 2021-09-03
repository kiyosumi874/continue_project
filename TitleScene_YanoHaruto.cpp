#include "DxLib.h"
#include <math.h>

#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"

#include "TitleUI.h"
#include "BGM.h"
#include "SE.h"
#include "PlayerActor.h"
#include "Camera.h"

const float    FIRST_DELTA_TIME = 0.000001f;
const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
const char* BGM_HANDLE = "data/sound/サイクリング_3.mp3";
const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const VECTOR   TITLE_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   TITLE_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);
const VECTOR   TITLE_CAMERA_POS = VGet(0.0f, 2.0f, -2.0f);
const int         MAX_ALPHA_PAL = 255;
const int        IMG_FADE_SPEED = 3;

/// <summary>
/// 初期化
/// </summary>
TitleScene_YanoHaruto::TitleScene_YanoHaruto()
	: mDeltaTime(FIRST_DELTA_TIME)
	, mCamera(nullptr)
	, mTitleUI(nullptr)
	, mBGM(nullptr)
	, mPlayer(nullptr)
	, mClickNormal(nullptr)
	, mInputReturnFlag(false)
	, mStartButtonFlag(false)
	, mAlphaPalFlag(false)
	, mBGMFlag(false)
	, mClickNormalFlag(false)
	, mSceneTransitionCount(0)
	, mMoveSceneHandle(NULL)
	, mAlphaPal(MAX_ALPHA_PAL)
	, mFadeSpeed(IMG_FADE_SPEED)
{
}

/// <summary>
/// 後処理
/// </summary>
TitleScene_YanoHaruto::~TitleScene_YanoHaruto()
{
	delete mCamera;
	delete mTitleUI;
	delete mBGM;
	delete mClickNormal;
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
SceneBase* TitleScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;

	// プレイヤーの更新
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE);
	mPlayer->UpdateActor(mDeltaTime);  // 1
	mPlayer->Update(mDeltaTime);       // 2 この順番で書く

	// タイトルUIの更新
	mTitleUI->Update(mDeltaTime);

	// カメラの更新
	mCamera->Update(TITLE_CAMERA_POS, mPlayer->GetPosition());
	// フェードイン
	if (0 <= mAlphaPal && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	// フェードアウト
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mAlphaPal += mFadeSpeed;
	}

	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
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
#ifdef _DEBUG
	// デバッグモード時のみ実行
	clsDx();
	printfDx("CameraPosX:%f\n", mCamera->GetPositionX());
	printfDx("CameraPosY:%f\n", mCamera->GetPositionY());
	printfDx("CameraPosZ:%f\n", mCamera->GetPositionZ());
	printfDx("CameraAimPosX:%f\n", mCamera->GetAimTargetPositionX());
	printfDx("CameraAimPosY:%f\n", mCamera->GetAimTargetPositionY());
	printfDx("CameraAimPosZ:%f\n", mCamera->GetAimTargetPositionZ());
	printfDx("PlayerPosX:%f\n", mPlayer->GetPositionX());
	printfDx("PlayerPosY:%f\n", mPlayer->GetPositionY());
	printfDx("PlayerPosZ:%f\n", mPlayer->GetPositionZ());
#endif

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// プレイヤーの描画
	mPlayer->Draw();
	// タイトルUIの描画
	mTitleUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void TitleScene_YanoHaruto::Sound()
{
	// フェードイン/フェードアウト(BGM)
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, mDeltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, mDeltaTime);
	}

	// ENTERキーを押したときの音
	if (mStartButtonFlag && mAlphaPalFlag && !mClickNormalFlag)
	{
		mClickNormalFlag = true;
		mClickNormal->Play();
	}

	// 一度だけBGMを再生
	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene_YanoHaruto::Load()
{
	// 実体化
	mCamera = new Camera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;
	mClickNormal = new SE;
	mPlayer = new PlayerActor;

	mTitleUI->Load();
	mClickNormal->LoadSound(SOUND_CLICK_HANDLE);
	mBGM->LoadMusic(BGM_HANDLE);
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(TITLE_PLAYER_SCALE);
	mPlayer->SetRotation(TITLE_PLAYER_ROTATE);
	mPlayer->SetPosition(TITLE_PLAYER_POS);
}
