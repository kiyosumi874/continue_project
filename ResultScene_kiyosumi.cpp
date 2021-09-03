#include "DxLib.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"
#include "Camera.h"
#include "ResultUI.h"
#include "PlayerActor.h"
#include "StaticObjectActor.h"
#include "Effect.h"

//            ↓はTitleSceneで定義しているので書かなくていい
//const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
//const float    FIRST_DELTA_TIME = 0.000001f;
//const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
//const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const char* PODIUM_MODEL = "data/model/podium/podium.mv1";
const VECTOR   RESULT_CAMERA_POS = VGet(2.0f, 1.0f, -3.0f);
const VECTOR   RESULT_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   RESULT_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   RESULT_PLAYER_POS = VGet(0.0f, 0.76f, 0.0f);

/// <summary>
/// 初期化
/// </summary>
ResultScene_kiyosumi::ResultScene_kiyosumi(int _score)
	: mInputReturnFlag(false)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(-1)
	, mCheckHitFlag(false)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mPodium(nullptr)
	, mCamera(nullptr)
	, mFireWorks(nullptr)
	, mPool(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene_kiyosumi::~ResultScene_kiyosumi()
{
	delete mResultCamera;
	delete mResultUI;
	delete mPlayer;
	delete mCamera;
	delete mPodium;
	delete mFireWorks;
	delete mPool;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* ResultScene_kiyosumi::Update(float _deltaTime)
{
	mPodium->Update(_deltaTime);
	mPool->Update(_deltaTime);

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE);
	mPlayer->UpdateActor(_deltaTime);
	mPlayer->Update(_deltaTime);

	// リザルトUIの更新
	mResultUI->Update(_deltaTime);
	// リザルトUIにスコアを渡す
	mResultUI->LoadScore(mScore);

	mCamera->Update(RESULT_CAMERA_POS, mPlayer->GetPosition());

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
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new TitleScene_kiyosumi();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void ResultScene_kiyosumi::Draw()
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
	switch (mPlayer->GetPlayerState())
	{
	case PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE:
		printfDx("NowState:TITLE_IDLE\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE:
		printfDx("NowState:PLAY_IDLE\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME1:
		printfDx("NowState:PLAY_GAME1\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME2:
		printfDx("NowState:PLAY_GAME2\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_PLAY_GAME3:
		printfDx("NowState:PLAY_GAME3\n");
		break;

	case PlayerActor::PLAYER_STATE::STATE_RESULT_IDLE:
		printfDx("NowState:RESULT_IDLE\n");
		break;

	default:
		break;
	}
#endif

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mPool->Draw();
	mPlayer->Draw();

	mPodium->Draw();

	if (mFireWorks->GetNowPlaying2D())
	{
		mFireWorks->PlayEffekseer2D(VGet(rand() % 1920, rand() % 1080 , 0));
	}

	// リザルトUIの描画
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene_kiyosumi::Sound(float _deltaTime)
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene_kiyosumi::Load()
{

	mCamera = new Camera;
	mResultUI = new ResultUI;
	mPlayer = new PlayerActor;
	mPodium = new StaticObjectActor;
	mPool = new StaticObjectActor;
	mFireWorks = new Effect("data/effect/hanabi.efk", 40.0f);

	// リザルトUIの初期化
	mResultUI->Load();
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);

	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(RESULT_PLAYER_SCALE);
	mPlayer->SetRotation(RESULT_PLAYER_ROTATE);
	mPlayer->SetPosition(RESULT_PLAYER_POS);

	mPodium->LoadModelTex("data/model/podium/Stand.mv1", "data/model/podium/podium.png");
	mPodium->SetScale(VGet(0.15f, 0.15f, 0.15f));
	mPodium->SetRotation(VGet(0.0f, 270.0f * DX_PI_F / 180.0f, 0.0f));
	mPodium->SetPosition(VGet(0.0f, 0.0f, 0.0f));

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	mPool->SetScale(VGet(1.0f, 1.0f,1.0f));
	mPool->SetRotation((VGet(0.0f, 0.0f, 0.0f)));
	mPool->SetPosition((VGet(0.0f, 0.0f, 0.0f)));
}
