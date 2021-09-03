///8/27 エフェクト追加
///by 矢野陽大
///8/30　staticObjectを使ってプール追加　by 矢野陽大
///----------------------------------------
#include "DxLib.h"
#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene_YanoHaruto.h"
#include "PlayEffect.h"
#include "DxLib.h"
#include "Camera.h"
#include "ResultUI.h"
#include "ResultCamera.h"
#include "PlayerActor.h"
#include "StaticObjectActor.h"

//            ↓はTitleSceneで定義しているので書かなくていい
//const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
//const float    FIRST_DELTA_TIME = 0.000001f;
//const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
//const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const char* PODIUM_MODEL = "data/model/podium/podium.mv1";
const VECTOR   RESULT_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   RESULT_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   RESULT_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   RESULT_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);



// SetGraphModeのパラメータ
#define WINDOW_SCREEN_WIDTH  1920/**2/3*/
#define WINDOW_SCREEN_HEIGHT 1080/**2/3*/
#define COLOR_BIT_NUM 16

/// <summary>
/// 初期化
/// </summary>
ResultScene_YanoHaruto::ResultScene_YanoHaruto(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(-1)
	, mCheckHitFlag(false)
	, mConfetti()
	, mPool(nullptr)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mFireWork()
	, mStaticObjectActor(nullptr)
	, mCamera(nullptr)
	, mResultCamera(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene_YanoHaruto::~ResultScene_YanoHaruto()
{
	delete mResultCamera;
	delete mResultUI;
	delete mPlayer;
	delete mCamera;
	delete mStaticObjectActor;
	delete mPool;
	for (int i = 0; i < FIREWORKS; i++)
	{
		mFireWork[i]->StopEffect();
		mFireWork[i]->Delete();
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		mConfetti[i]->StopEffect();
		mConfetti[i]->Delete();
	}
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
	mDeltaTime = _deltaTime / 1000000.0f;

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE);
	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// リザルトUIの更新
	mResultUI->Update(mDeltaTime);
	// リザルトUIにスコアを渡す
	mResultUI->LoadScore(mScore);

	mCamera->Update(RESULT_CAMERA_POS, mPlayer->GetPosition());

	mStaticObjectActor->UpdateActor(mDeltaTime);
	mStaticObjectActor->Update(mDeltaTime);
	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}


	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag && mAlphaPalFlag)
	{
		mCheckHitFlag = true;
		mInputReturnFlag = false;
	}
	if (mCheckHitFlag)
	{
		mAlphaPal += mFadeSpeed;
	}
	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
		//エフェクト消去------------------------------------------------------------------------------
		for (int i = 0; i < FIREWORKS; i++)
		{
			mFireWork[i]->StopEffect();
			mFireWork[i]->Delete();
		}
		for (int i = 0; i < CONFETTIES; i++)
		{
			mConfetti[i]->StopEffect();
			mConfetti[i]->Delete();
		}
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
	mPlayer->Draw();

	mPool->Draw();
	mStaticObjectActor->Draw();

	// リザルトUIの描画
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
	//エフェクト再生--------------------------------------------------------------------------------------------
	for (int i = 0; i < FIREWORKS; i++)
	{
		//エフェクトが再生し終わったら再生再開
		if (mFireWork[i]->GetNowPlaying3D())
		{
			int j = -2 + i;
			mFireWork[i]->PlayEffekseer(VGet(j, 0, 0));
		}
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		if (mConfetti[i]->GetNowPlaying3D())
		{
			int j = -1 + i;
			mConfetti[i]->PlayEffekseer(VGet(j, 0, 0));
		}
	}
	//----------------------------------------------------------------------------------------------------------
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
	//エフェクト追加-----------------------------------------------------------------------------------------------
	for (int i = 0; i < FIREWORKS; i++)
	{
		mFireWork[i] = new PlayEffect("data/effect/hanabi.efk", 0.1f);
	}
	for (int i = 0; i < CONFETTIES; i++)
	{
		mConfetti[i] = new PlayEffect("data/effect/confetti.efk", 0.1f);
	}//------------------------------------------------------------------------------------------------------------

	mCamera = new Camera;
	mResultUI = new ResultUI;
	mPlayer = new PlayerActor;
	mPool = new StaticObjectActor;
	mStaticObjectActor = new StaticObjectActor;
	mResultCamera = new ResultCamera;

	// リザルトUIの初期化
	mResultUI->Load();
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);

	//プール追加8/30-----------------------------------------------------------------------------------------------
	mPool->LoadModel("data/model/pool/pool.mv1");
	mPool->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mPool->SetRotation(VGet(0.0f, 0.0f, 0.0f));
	mPool->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	//--------------------------------------------------------------------------------------------------------------

	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(RESULT_PLAYER_SCALE);
	mPlayer->SetRotation(RESULT_PLAYER_ROTATE);
	mPlayer->SetPosition(RESULT_PLAYER_POS);

	mStaticObjectActor->LoadModel(PODIUM_MODEL);
	mStaticObjectActor->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mStaticObjectActor->SetRotation(VGet(0.0f, 90.0f * DX_PI_F / 180.0f, 0.0f));
	mStaticObjectActor->SetPosition(VGet(0.0f, -2.5f, 2.0f));
}