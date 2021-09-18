#include "DxLib.h"
#include <math.h>

#include "TitleScene_YanoHaruto.h"
#include "PlayScene_YanoHaruto.h"

#include "TitleUI.h"
#include "BGM.h"
#include "SE.h"
#include "PlayerActor.h"
#include "Camera.h"
#include "StaticObjectActor.h"
#include "AudienceContoroller.h"
#include "WaterObject.h"

const char* MOVE_SCENE_IMG = "data/img/MoveScene.png";
const char* PLAYER_MODEL_HANDLE = "data/model/player5/waterboy.pmx";
const char* BGM_HANDLE = "data/sound/サイクリング_3.mp3";
const char* SOUND_CLICK_HANDLE = "data/sound/click_normal.mp3";
const VECTOR   TITLE_PLAYER_SCALE = VGet(0.5f, 0.5f, 0.5f);
const VECTOR   TITLE_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_PLAYER_POS = VGet(0.0f, 31.5f, 0.0f);
const VECTOR   TITLE_CAMERA_POS = VGet(45.0f, 53.0f, -18.0f);
const VECTOR   TITLE_POOL_SCALE = VGet(1.0f, 1.0f, 1.0f);
const VECTOR   TITLE_POOL_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   TITLE_POOL_POS = VGet(0.0f, 0.0f, 0.0f);
const int         MAX_ALPHA_PAL = 255;
const int        IMG_FADE_SPEED = 3;

/// <summary>
/// 初期化
/// </summary>
TitleScene_YanoHaruto::TitleScene_YanoHaruto()
	: mCamera(nullptr)
	, mTitleUI(nullptr)
	, mBGM(nullptr)
	, mPlayer(nullptr)
	, mClickNormal(nullptr)
	, mPool(nullptr)
	, mSky(nullptr)
	, mInputReturnFlag(false)
	, mStartButtonFlag(false)
	, mAlphaPalFlag(false)
	, mBGMFlag(false)
	, mClickNormalFlag(false)
	, mSceneTransitionCount(0)
	, mMoveSceneHandle(NULL)
	, mAlphaPal(MAX_ALPHA_PAL)
	, mFadeSpeed(IMG_FADE_SPEED)
	, mCameraType(CAMERA_TYPE::CAMERA_1)
	, mAudienceCon(nullptr)
	//, mAudienceCon2(nullptr)
{
	//mMoveCircle.mPosX = 0.0f;
	//mMoveCircle.mPosY = 31.5f;
	//mMoveCircle.mPosZ = 0.0f;
	//mMoveCircle.mAngle = 0.0f;
	//mMoveCircle.mLength = 25.0f;

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
	delete mPool;
	delete mSky;
	delete mWater;
	delete mAudienceCon;
	//delete mAudienceCon2;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* TitleScene_YanoHaruto::Update(float _deltaTime, int& _hiScore)
{
	static VECTOR cameraPos = VGet(0.0f, 40.0f, -25.0f);

	mSky->Update(_deltaTime);
	mPool->Update(_deltaTime);
	// 水面シェーダーの更新
	mWater->Update(_deltaTime);
	mWater->UpdateWaterShader(_deltaTime);     // 水面用シェーダーへ情報をセットする

	//----------------------------------------9/18(deltTime)
	mAudienceCon->Update(_deltaTime);
	//mAudienceCon2->Update();
	// プレイヤーの更新
	mPlayer->UpdateActor(_deltaTime);  // 1
	mPlayer->Update(_deltaTime);       // 2 この順番で書く
	// タイトルUIの更新
	mTitleUI->Update(_deltaTime);
	cameraPos = VAdd(cameraPos, VGet(0.0f, 0.0f, 0.0f));
	// カメラの更新
	if (mCameraType == CAMERA_TYPE::CAMERA_1)
	{
		mCamera->SetSpeed(0.2f);
		mCamera->SetPos(VAdd(TITLE_CAMERA_POS, VGet(5.0f, 5.0f, 0.0f)));
		mCamera->SetTarget(VAdd(TITLE_POOL_POS, VGet(0.0f, 20.0f, -30.0f)));
		if (mCamera->GetFuturePos().z >= -25.0f - 10.0f)
		{
			mCameraType = CAMERA_TYPE::CAMERA_2;
			mCamera->SetFuturePos(VGet(-25.0f, 50.0f, -20.0f));
			mCamera->SetFutureTarget(mPlayer->GetPosition());
		}
	}
	if (mCameraType == CAMERA_TYPE::CAMERA_2)
	{
		mCamera->SetSpeed(0.2f);
		mCamera->SetPos(VAdd(VGet(-25.0f, 50.0f, -20.0f), VGet(50.0f, 0.0f, 0.0f)));
		mCamera->SetTarget(VAdd(mPlayer->GetPosition(), VGet(0.0f, 0.0f, 0.0f)));
		if (mCamera->GetFuturePos().x >= 17.0f)
		{
			mCameraType = CAMERA_TYPE::CAMERA_3;
			mCamera->SetFuturePos(VGet(30.0f, 20.0f, 0.0f));
			mCamera->SetFutureTarget(VGet(50.0f, 20.0f, -10.0f));
		}
	}
	if (mCameraType == CAMERA_TYPE::CAMERA_3)
	{
		mCamera->SetSpeed(0.1f);
		mCamera->SetPos(VAdd(VGet(30.0f, 20.0f, 0.0f), VGet(0.0f, 0.0f, -100.0f)));
		mCamera->SetTarget(VAdd(VGet(50.0f, 20.0f, -10.0f), VGet(0.0f, 0.0f, -100.0f)));
		if (mCamera->GetFuturePos().z <= -85.0f)
		{
			mCameraType = CAMERA_TYPE::CAMERA_1;
			mCamera->SetFuturePos(VAdd(TITLE_CAMERA_POS, VGet(-30.0f, 20.0f, -130.0f)));
			mCamera->SetFutureTarget(VAdd(TITLE_POOL_POS, VGet(0.0f, 20.0f, -30.0f)));
		}

	}

	mCamera->Update(cameraPos, mPlayer->GetPosition(), _deltaTime);
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
		return new PlayScene_YanoHaruto(_deltaTime);
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
	mAudienceCon->Draw();
	//mAudienceCon2->Draw();
	// プレイヤーの描画
	mPlayer->Draw();
	mWater->DrawWater();
	// タイトルUIの描画
	mTitleUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void TitleScene_YanoHaruto::Sound(float _deltaTime)
{
	// フェードイン/フェードアウト(BGM)
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, _deltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, _deltaTime);
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
	mPool = new StaticObjectActor;
	mSky = new StaticObjectActor;
	//----------------------------------------------9/18
	mAudienceCon = new AudienceContoroller;
	mAudienceCon->LoadAudience();
	mAudienceCon->SetAudience();

	//mAudienceCon2 = new Audience;
	// 水面オブジェクト(モデルはペライチの正方形)
	mWater = new WaterObject;
	mWater->SetScale(VGet(150.0f, 1.0f, 225.0f));
	mWater->SetPosition(VGet(0.0f, -5.25f, -55.0f));
	mTitleUI->Load();
	mClickNormal->LoadSound(SOUND_CLICK_HANDLE);
	mBGM->LoadMusic(BGM_HANDLE);
	mMoveSceneHandle = LoadGraph(MOVE_SCENE_IMG);

	mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
	mPool->SetScale(TITLE_POOL_SCALE);
	mPool->SetRotation(TITLE_POOL_ROTATE);
	mPool->SetPosition(TITLE_POOL_POS);


	/*mAudienceCon2->SetStartPosX(-45.0f);
	mAudienceCon2->SetStartPosX(10.0f);
	mAudienceCon2->SetStartPosX(30.0f);*/

	mSky->LoadModel("data/model/Skydome_X5/Dome_X501.pmx");

	mCamera->SetFuturePos(VAdd(TITLE_CAMERA_POS, VGet(-30.0f, 20.0f, -130.0f)));
	mCamera->SetFutureTarget(VAdd(TITLE_POOL_POS, VGet(0.0f, 20.0f, -30.0f)));
	mCamera->SetPos(VAdd(TITLE_CAMERA_POS, VGet(5.0f, 5.0f, -5.0f)));
	mCamera->SetTarget(VGet(-45.5f, 10.0f, -30.0f));

	mPlayer->SetPlayerState(PlayerActor::PLAYER_STATE::STATE_TITLE_IDLE);
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(TITLE_PLAYER_SCALE);
	mPlayer->SetRotation(TITLE_PLAYER_ROTATE);
	mPlayer->SetPosition(TITLE_PLAYER_POS);
}

