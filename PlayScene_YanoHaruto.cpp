//------------------------------------------+
//8/30スタティックオブジェクトを使ったプールのモデル追加
//８/30アクターを使った観客の追加
//8/30インクルードしたaudience.h移動
//by 矢野
//------------------------------------------+

#include "PlayScene_YanoHaruto.h"
#include "ResultScene_YanoHaruto.h"
#include "TitleScene.h"
#include "PlayUI.h"
#include "Camera.h"
#include "BGM.h"
#include "StaticObjectActor.h"
#include "PlayerActor.h"

const VECTOR   PLAY_CAMERA_POS = VGet(0.0f, 1.0f, -2.0f);
const VECTOR   PLAY_PLAYER_SCALE = VGet(0.05f, 0.05f, 0.05f);
const VECTOR   PLAY_PLAYER_ROTATE = VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f);
const VECTOR   PLAY_PLAYER_POS = VGet(0.0f, 0.0f, 0.0f);

//プールのモデル
const char* POOL_MODEL = "data/model/pool/pool.mv1";

/// <summary>
/// 初期化
/// </summary>
PlayScene_YanoHaruto::PlayScene_YanoHaruto()
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
	//-------------------------------------------------------------------
	//8/30追加分矢野
	, mAudiencePos(VGet(-45.5f, 10.0f, -30.0f))
	, mAudienceGroundHeight(10.0f)  //最初に実体化させた観客の高さ
	, mAudienceHighestJumpLine(5.0f)
	, mAudienceJumpPower(0.1f)
	, mAudienceDownFlag(false)
	, mPool(nullptr)
	, mAudience()
	//-------------------------------------------------------------------
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGM(nullptr)
	, mBGMFlag(false)
	, mTargetPos(VGet(0.0f, 0.0f, 0.0f))
	, mPlayer(nullptr)
	, mFadeSpeed(3)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayScene_YanoHaruto::~PlayScene_YanoHaruto()
{
	//delete mPlayCamera;
	delete mCamera;
	delete mPlayUI;
	delete mBGM;
	delete mPool;
	//観客の消去
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			delete mAudience[i][j];
		}
	}
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
SceneBase* PlayScene_YanoHaruto::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	//観客の更新
	//8/30矢野------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudienceDownFlag = mAudience[i][j]->GetDownFlag();
			mAudience[i][j]->Update(_deltaTime);
			if (mAudienceDownFlag)
			{
				mAudiencePos.y -= mAudienceJumpPower;
			}
			else
			{
				mAudiencePos.y += mAudienceJumpPower;
			}
		}
	}
	//-------------------------------------------------------------
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
		return new ResultScene_YanoHaruto(mScore);
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void PlayScene_YanoHaruto::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	//観客の描画 8/30
	//---------------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudience[i][j]->Draw();
		}
	}
	//---------------------------------------------------------
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
void PlayScene_YanoHaruto::Sound()
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
void PlayScene_YanoHaruto::Load()
{
	mCamera = new Camera;
	mPlayUI = new PlayUI;
	mBGM = new BGM;
	mPool = new StaticObjectActor;

	//観客の実体化 8/30
	//-------------------------------------------------------------------------------------------------
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mAudience[i][j] = new Audience(mAudienceGroundHeight,mAudienceHighestJumpLine);
		}
	}
	//-------------------------------------------------------------------------------------------------
	
	mPlayer = new PlayerActor;

	//プールの実体化　8/30
	//-------------------------------------------------------------------------------------------------
	mPool->LoadModel(POOL_MODEL);
	mPool->SetScale(VGet(0.005f, 0.005f, 0.005f));
	mPool->SetRotation(VGet(0.0f, 0.0f, 0.0f));
	mPool->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	//-------------------------------------------------------------------------------------------------
	
	mPlayer->LoadModel(PLAYER_MODEL_HANDLE);
	mPlayer->SetScale(PLAY_PLAYER_SCALE);
	mPlayer->SetRotation(PLAY_PLAYER_ROTATE);
	mPlayer->SetPosition(PLAY_PLAYER_POS);

	
	mTargetPos = mAudience[0][0]->GetPosition();

	// プレイUIの初期化
	mPlayUI->Load();
	mBGM->LoadMusic("data/sound/迅雷のユーロビート.mp3");
}
