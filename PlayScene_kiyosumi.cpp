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
	, mBGM2(nullptr)
	, mBGMFlag(false)
	, mBGMFlag2(false)
	, mKansei(nullptr)
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPool(nullptr)
	, mSky(nullptr)
	, mAudience(nullptr)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mGameMode(GAME_MODE_STATE::FADE_IN)
	, mGameWaitCount(0)
	, mFlag(false)
	, mFlag2(false)
	, mFlag3(false)
	, mDeltaTime(0)
{

}

PlayScene_kiyosumi::PlayScene_kiyosumi(float _deltaTime)
	: mInputReturnFlag(false)
	, mCamera(nullptr)
	, mPlayUI(nullptr)
	, mScore(0)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGM(nullptr)
	, mBGM2(nullptr)
	, mBGMFlag(false)
	, mBGMFlag2(false)
	, mKansei(nullptr)
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPool(nullptr)
	, mSky(nullptr)
	, mAudience(nullptr)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
	, mGameMode(GAME_MODE_STATE::FADE_IN)
	, mGameWaitCount(0)
	, mFlag(false)
	, mFlag2(false)
	, mFlag3(false)
	, mDeltaTime(_deltaTime)
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
	delete mBGM2;
	delete mPool;
	delete mSky;
	delete mAudience;
	delete mPlayer;
	delete mClickClitical;
	delete mClickNormal;
	delete mMetoronome;
	delete mKansei;
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
	case GAME_MODE_STATE::GAYA:
		GameModeGayaBehavior(_deltaTime);
		break;

	default:
		break;
	}

	mSky->Update(_deltaTime);
	mPool->Update(_deltaTime);
	//観客の更新
	mAudience->Update();

	// プレイヤーの更新
	mPlayer->UpdateActor(_deltaTime);
	mPlayer->Update(_deltaTime);

	// カメラの更新

	mCamera->Update(PLAY_CAMERA_POS, mTargetPos, _deltaTime);


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
	printfDx("FuturePosX:%f\n", mCamera->GetFuturePos().x);
	printfDx("FuturePosY:%f\n", mCamera->GetFuturePos().y);
	printfDx("FuturePosZ:%f\n", mCamera->GetFuturePos().z);
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
	mSky->Draw();
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
	if (mGameMode == GAME_MODE_STATE::CIRCLE_GAME)
	{
		mBGM->FadeInMusic(250, _deltaTime);
	}
	if (!mBGMFlag && mGameMode == GAME_MODE_STATE::CIRCLE_GAME)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
	if (mGameMode == GAME_MODE_STATE::CIRCLE_GAME)
	{
		mBGM2->FadeOutMusic(500, _deltaTime);
	}
	if (mGameMode == GAME_MODE_STATE::FADE_IN)
	{
		mBGM2->FadeInMusic(250, _deltaTime);
	}
	if (!mBGMFlag2 && mGameMode == GAME_MODE_STATE::FADE_IN)
	{
		mBGM2->Play();
		mBGMFlag2 = true;
	}
	mPlayUI->Sound(mMetoronome, mClickNormal, mClickClitical);
}

/// <summary>
/// 初期化
/// </summary>
void PlayScene_kiyosumi::Load()
{
	int mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 150, -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4, -1, 5, TRUE);
	int tmp = GetNowCount();
	short tmpCount = 1;
	DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading", GetColor(255, 255, 255), mFontHandle);
	ScreenFlip();
	mCamera = new Camera;
	LoadEX(tmp, tmpCount, mFontHandle);
	/*if (GetNowCount() - tmp >= 1000)
	{
		if (tmpCount == 0)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading", GetColor(255, 255, 255), mFontHandle);
			ScreenFlip();
		}
		else if (tmpCount == 1)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading.", GetColor(255, 255, 255), mFontHandle);
			ScreenFlip();
		}
		else if (tmpCount == 2)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading..", GetColor(255, 255, 255), mFontHandle);
			ScreenFlip();
		}
		else
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading...", GetColor(255, 255, 255), mFontHandle);
			ScreenFlip();
			tmpCount = -1;
		}
		tmpCount++;
	}*/
	mPlayUI = new PlayUI;

	LoadEX(tmp, tmpCount, mFontHandle);
	mBGM = new BGM;
	LoadEX(tmp, tmpCount, mFontHandle);
	mBGM2 = new BGM;
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mPool = new StaticObjectActor;
	LoadEX(tmp, tmpCount, mFontHandle);
	mSky = new StaticObjectActor;
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mAudience = new Audience;
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayer = new PlayerActor;
	
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mMetoronome = new SE;
	LoadEX(tmp, tmpCount, mFontHandle);
	mClickNormal = new SE;
	LoadEX(tmp, tmpCount, mFontHandle);
	mClickClitical = new SE;
	LoadEX(tmp, tmpCount, mFontHandle);
	mKansei = new SE;
	
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_IDLE);
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	LoadEX(tmp, tmpCount, mFontHandle);
	
	mPlayer->SetScale(PLAY_PLAYER_SCALE);
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayer->SetPosition(PLAY_PLAYER_POS);
	
	
	//mTargetPos = mAudience->mGetAudiencePos();

	LoadEX(tmp, tmpCount, mFontHandle);
	mCamera->SetPos(VAdd(PLAY_CAMERA_POS, VGet(5.0f, 5.0f, -5.0f)));
	LoadEX(tmp, tmpCount, mFontHandle);
	mCamera->SetTarget(mPlayer->GetPosition());
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mCamera->SetFuturePos(VAdd(PLAY_CAMERA_POS, VGet(5.0f,5.0f,-5.0f)));
	LoadEX(tmp, tmpCount, mFontHandle);
	mCamera->SetFutureTarget(mPlayer->GetPosition());
	
	LoadEX(tmp, tmpCount, mFontHandle);
	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	LoadEX(tmp, tmpCount, mFontHandle);
	mPool->SetScale(PLAY_POOL_SCALE);
	LoadEX(tmp, tmpCount, mFontHandle);
	mPool->SetRotation(PLAY_POOL_ROTATE);
	LoadEX(tmp, tmpCount, mFontHandle);
	mPool->SetPosition(PLAY_POOL_POS);

	LoadEX(tmp, tmpCount, mFontHandle);
	mSky->LoadModel("data/model/Skydome_X5/Dome_X501.pmx");
	
	// プレイUIの初期化
	LoadEX(tmp, tmpCount, mFontHandle);
	mPlayUI->Load();

	
	LoadEX(tmp, tmpCount, mFontHandle);
	mMetoronome->LoadSound("data/sound/metronome_wood.wav");
	LoadEX(tmp, tmpCount, mFontHandle);
	mClickNormal->LoadSound("data/sound/click_normal.wav");
	LoadEX(tmp, tmpCount, mFontHandle);
	mClickClitical->LoadSound("data/sound/click_critical.wav");
	LoadEX(tmp, tmpCount, mFontHandle);
	mKansei->LoadSound("data/sound/kansei.mp3");
	LoadEX(tmp, tmpCount, mFontHandle);
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
	LoadEX(tmp, tmpCount, mFontHandle);
	mBGM2->LoadMusic("data/sound/gaya2.mp3");
}

void PlayScene_kiyosumi::GameModeFadeInBehavior(float _deltaTime)
{
	/*mCamera->SetPos(VGet(30.0f, 50.0f, -10.0f));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 5.0f, 0.0f)));*/
	/*mCamera->SetPos(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, -10.0f)));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, 0.0f)));*/
	mAlphaPal -= mFadeSpeed;
	if (mAlphaPal <= 0)
	{
		mGameMode = GAME_MODE_STATE::CAMERA_MOVE;
	}
	
}

void PlayScene_kiyosumi::GameModeCameraMoveBehavior(float _deltaTime)
{
	mCamera->SetSpeed(2.0f);
	mCamera->SetPos(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, -10.0f )));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, 0.0f)));
	if (mCamera->GetFuturePos().x <= mPlayer->GetPosition().x + 1.0f && mCamera->GetFuturePos().y <= mPlayer->GetPosition().y + 11.0f && mCamera->GetFuturePos().z >= mPlayer->GetPosition().z - 11.0f)
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			mGameMode = GAME_MODE_STATE::CIRCLE_GAME;
			mClickNormal->Play();
		}
	}
}

void PlayScene_kiyosumi::GameModeWaitBehavior(float _deltaTime)
{
	
	if (((!mClickClitical->IsPlaying()) && (!mClickNormal->IsPlaying())) && mGameWaitCount == 1)
	{
		mCamera->SetSpeed(5.0f);
		mCamera->SetPos(PLAY_CAMERA_POS);
		mCamera->SetTarget(VGet(-45.5f, 10.0f, -30.0f));
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
		mCamera->SetSpeed(5.0f);
		mCamera->SetPos(VAdd(PLAY_CAMERA_POS, VGet(0.0f,0.0f,-8.0f)));
		mCamera->SetTarget(VGet(-45.5f, 10.0f, -30.0f));
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
		mCamera->SetSpeed(5.0f);
		mCamera->SetPos(VAdd(mPlayer->GetPosition(), VGet(0.0f,10.0f,-20.0f)));
		mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 5.0f, 0.0f)));
		if (mPlayer->GetPlayTime() >= 45)
		{
			VECTOR tmpPos = mPlayer->GetPosition();
			tmpPos.z -= 5 * _deltaTime;
			tmpPos.y += mJumpPower * _deltaTime;
			if (tmpPos.y <= 0.0f)
			{
				mGameMode = GAME_MODE_STATE::GAYA;
			}
			mPlayUI->SetDrawGameState(DRAW_GAME_STATE::DRAW_NULL);
			mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_PLAY_JUMP);
			mJumpPower -= 12.0 * _deltaTime;
			// 更新分の座標のSet
			mPlayer->SetPosition(tmpPos);
		}
	}
}

void PlayScene_kiyosumi::GameModeCircleGameBehavior(float _deltaTime)
{
	mCamera->SetPos(VGet(10.0f, 45.0f, -10.0f - 10.0f));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, -10.0f)));
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
	mCamera->SetPos(VGet(10.0f, 45.0f, -18.0f - 10.0f));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, -10.0f)));
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
	mCamera->SetPos(VGet(10.0f, 45.0f, -26.0f - 10.0f));
	mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 10.0f, -10.0f)));
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

void PlayScene_kiyosumi::GameModeGayaBehavior(float _deltaTime)
{
	
	VECTOR tmpPos = mPlayer->GetPosition();

	if (mPlayer->GetPosition().y >= -30.0f && !mFlag)
	{
		tmpPos.y += mJumpPower * _deltaTime;
		mJumpPower -= 12.0 * _deltaTime;
	}
	else
	{
		mFlag = true;
	}
	if (mFlag && !mFlag2)
	{
		if (mPlayer->GetPosition().y <= -10.0f)
		{
			tmpPos.y += 5.0f * _deltaTime;
		}
		else
		{
			mFlag2 = true;
		}
	}
	if (mFlag2 && !mFlag3)
	{
		mKansei->Play();
		mFlag3 = true;
	}
	if (mFlag3)
	{
		if (!mKansei->IsPlaying())
		{
			mGameMode = GAME_MODE_STATE::FADE_OUT;
		}
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			mGameMode = GAME_MODE_STATE::FADE_OUT;
		}
	}
		
	mCamera->SetSpeed(5.0f);
	mCamera->SetPos(VAdd(PLAY_CAMERA_POS, VGet(0.0f, 0.0f, -8.0f)));
	mCamera->SetTarget(VGet(-45.5f, -30.0f, -30.0f));
	mPlayer->SetPosition(tmpPos);
}

void PlayScene_kiyosumi::GameModeFadeOutBehavior(float _deltaTime)
{
	mAlphaPal += mFadeSpeed;
}

void PlayScene_kiyosumi::LoadEX(int& _tmp, short& _count, int _handle)
{
	if (GetNowCount() - _tmp >= 500)
	{
		if (_count == 0)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading", GetColor(255, 255, 255), _handle);
			ScreenFlip();
		}
		else if (_count == 1)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading.", GetColor(255, 255, 255), _handle);
			ScreenFlip();
		}
		else if (_count == 2)
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading..", GetColor(255, 255, 255), _handle);
			ScreenFlip();
		}
		else
		{
			ClearDrawScreen();
			DrawStringToHandle(1920 / 3, 1080 / 2, "NowLoading...", GetColor(255, 255, 255), _handle);
			ScreenFlip();
			_count = -1;
		}
		_tmp = GetNowCount();
		_count++;
	}
}
