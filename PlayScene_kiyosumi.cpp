#include "PlayScene_kiyosumi.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"
#include "PlayUI.h"
#include "Camera.h"
#include "BGM.h"
#include "Audience.h"
#include "StaticObjectActor.h"
#include "PlayerActor.h"
#include "SE.h"

const VECTOR   PLAY_CAMERA_POS = VGet(45.0f, 53.0f, -18.0f);
const VECTOR   PLAY_PLAYER_SCALE = VGet(0.5f, 0.5f, 0.5f);
const VECTOR   PLAY_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_PLAYER_POS = VGet(0.0f, 32.0f, 0.0f);
const VECTOR   PLAY_POOL_SCALE = VGet(1.0f, 1.0f, 1.0f);
const VECTOR   PLAY_POOL_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_POOL_POS = VGet(0.0f, 0.0f, 0.0f);

/// <summary>
/// 初期化
/// </summary>
PlayScene_kiyosumi::PlayScene_kiyosumi()
	: mInputReturnFlag(false)
	, mCamera(nullptr)
	, mPlayUI(nullptr)
	, mScore(0)
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
	, mGameMode(GAME_MODE_STATE::FADE_IN)
	, mGameWaitCount(0)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_kiyosumi::~PlayScene_kiyosumi()
{
	delete mCamera;
	delete mPlayUI;
	delete mBGM;
	delete mPool;
	delete mAudience;
	delete mPlayer;
	delete mClickClitical;
	delete mClickNormal;
	delete mMetoronome;
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
	switch (mGameMode)
	{
	case GAME_MODE_STATE::FADE_IN:
		GameModeFadeInBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::CAMERA_MOVE:
		GameModeCameraMoveBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::WAIT:
		GameModeWaitBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::CIRCLE_GAME:
		GameModeCircleGameBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::GAUGE_GAME:
		GameModeGaugeGameBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::PENDULUM_GAME:
		GameModePendulumGameBehavior(_deltaTime);
		break;
	case GAME_MODE_STATE::FADE_OUT:
		GameModeFadeOutBehavior(_deltaTime);
		break;
	default:
		break;
	}

	mPool->Update(_deltaTime);
	//観客の更新
	mAudience->Update();

	// プレイヤーの更新
	mPlayer->UpdateActor(_deltaTime);
	mPlayer->Update(_deltaTime);

	// カメラの更新
	mCamera->Update(PLAY_CAMERA_POS, mTargetPos);


	mScore = mPlayUI->GetScore();

	
	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new ResultScene_kiyosumi(mScore);
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void PlayScene_kiyosumi::Draw()
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
	printfDx("PlayTime:%f\n", mPlayer->GetPlayTime());
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
	mAudience->Draw();
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
void PlayScene_kiyosumi::Sound(float _deltaTime)
{
	if (mGameMode == GAME_MODE_STATE::FADE_OUT)
	{
		mBGM->FadeOutMusic(500, _deltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, _deltaTime);
	}
	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
	mPlayUI->Sound(mMetoronome, mClickNormal, mClickClitical);
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene_kiyosumi::Load()
{
	mCamera = new Camera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new StaticObjectActor;
	mAudience = new Audience;
	mPlayer = new PlayerActor;

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(PLAY_PLAYER_SCALE);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	mPlayer->SetPosition(PLAY_PLAYER_POS);

	mTargetPos = mAudience->mGetAudiencePos();

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	mPool->SetScale(PLAY_POOL_SCALE);
	mPool->SetRotation(PLAY_POOL_ROTATE);
	mPool->SetPosition(PLAY_POOL_POS);

	// プレイUIの初期化
	mPlayUI->Load();
	mMetoronome = new SE;
	mClickNormal = new SE;
	mClickClitical = new SE;
	mMetoronome->LoadSound("data/sound/metronome_wood.wav");
	mClickNormal->LoadSound("data/sound/click_normal.wav");
	mClickClitical->LoadSound("data/sound/click_critical.wav");
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
}

void PlayScene_kiyosumi::GameModeFadeInBehavior(float _deltaTime)
{
	mAlphaPal -= mFadeSpeed;
	if (mAlphaPal <= 0)
	{
		mGameMode = GAME_MODE_STATE::CIRCLE_GAME;
	}
	
}

void PlayScene_kiyosumi::GameModeCameraMoveBehavior(float _deltaTime)
{
}

void PlayScene_kiyosumi::GameModeWaitBehavior(float _deltaTime)
{
	if (((!mClickClitical->IsPlaying()) && (!mClickNormal->IsPlaying())) && mGameWaitCount == 1)
	{
		VECTOR tmpPos = mPlayer->GetPosition();
		tmpPos.z -= 3 * _deltaTime;
		if (tmpPos.z <= -8)
		{
			mGameMode = GAME_MODE_STATE::GAUGE_GAME;
			return;
		}
		mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_NULL);
		mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_RUN);
		mPlayer->SetPosition(tmpPos);
	}

	if (((!mClickClitical->IsPlaying()) && (!mClickNormal->IsPlaying())) && mGameWaitCount == 2)
	{
		VECTOR tmpPos = mPlayer->GetPosition();
		tmpPos.z -= 3 * _deltaTime;
		if (tmpPos.z <= -16)
		{
			mGameMode = GAME_MODE_STATE::PENDULUM_GAME;
			return;
		}
		mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_NULL);
		mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_RUN);
		mPlayer->SetPosition(tmpPos);
	}

	if (((!mClickClitical->IsPlaying()) && (!mClickNormal->IsPlaying())) && mGameWaitCount == 3)
	{
		if (mPlayer->GetPlayTime() >= 45)
		{
			VECTOR tmpPos = mPlayer->GetPosition();
			tmpPos.z -= 5 * _deltaTime;
			tmpPos.y += mJumpPower * _deltaTime;
			if (tmpPos.y <= 0.0f)
			{
				mGameMode = GAME_MODE_STATE::FADE_OUT;
			}
			mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_NULL);
			mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_JUMP);
			mJumpPower -= 9.8 * _deltaTime;
			// 更新分の座標のSet
			mPlayer->SetPosition(tmpPos);
		}
	}
}

void PlayScene_kiyosumi::GameModeCircleGameBehavior(float _deltaTime)
{
	mPlayUI->CircleGameBehavior(_deltaTime);
	mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_CIRCLE_GAME);
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_GAME1);
	if (!mPlayUI->GetPlayCircleGameFlag())
	{
		mGameMode = GAME_MODE_STATE::WAIT;
		mGameWaitCount += 1;
	}
}

void PlayScene_kiyosumi::GameModeGaugeGameBehavior(float _deltaTime)
{
	mPlayUI->GaugeGameBehavior(_deltaTime);
	mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_GAUGE_GAME);
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_GAME2);
	if (!mPlayUI->GetPlayGaugeGameFlag())
	{
		mGameMode = GAME_MODE_STATE::WAIT;
		mGameWaitCount += 1;
	}
}

void PlayScene_kiyosumi::GameModePendulumGameBehavior(float _deltaTime)
{
	mPlayUI->PendulumGameBehavior(_deltaTime);
	mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_PENDULUM_GAME);
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_GAME3);
	if (!mPlayUI->GetPlayPendulumGameFlag())
	{
		mGameMode = GAME_MODE_STATE::WAIT;
		mGameWaitCount += 1;
		mJumpPower = 10.0f;
	}
}

void PlayScene_kiyosumi::GameModeFadeOutBehavior(float _deltaTime)
{
	mAlphaPal += mFadeSpeed;
}
