#include "DxLib.h"
#include <math.h>

#include "TitleScene.h"
#include "PlayScene.h"

#include "TitleUI.h"
#include "TitleCamera.h"
#include "BGM.h"
#include "SE.h"

#include "PlayerActor_kiyosumi.h"
#include "Camera.h"



/// <summary>
/// 初期化
/// </summary>
TitleScene::TitleScene()
	/*: mTitleCamera(nullptr)*/
	: mCamera(nullptr)
	, mTitleUI(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mBGMFlag(false)
	, mBGM(nullptr)
	, mClickNormal(nullptr)
	, mClickNormalFlag(false)
	, mFadeSpeed(3)
	, mPlayer(nullptr)
{
	// キャラ表示デバッグ用
	//mHandle = MV1LoadModel("data/model/podium/podium.mv1");
	//mAttachIndex = MV1AttachAnim(mHandle, 0, -1, FALSE);
	//mTotalTime = MV1GetAttachAnimTotalTime(mHandle, mAttachIndex);
	//mPlayTime = 0.0f;
	//MV1SetScale(mHandle, VGet(0.01f, 0.01f, 0.01f));
	//MV1SetPosition(mHandle, VGet(0, 0.0f, 10));
}

/// <summary>
/// 後処理
/// </summary>
TitleScene::~TitleScene()
{
	//delete mTitleCamera;
	delete mCamera;
	delete mTitleUI;
	delete mBGM;
	delete mClickNormal;
	delete mPlayer;
	//MV1DeleteModel(mHandle);
	//MV1DetachAnim(mHandle, mAttachIndex);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* TitleScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	//// キャラ表示デバッグ用
	//mPlayTime += 50.0f * mDeltaTime;
	//// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	//if (mPlayTime >= mTotalTime)
	//{
	//	mPlayTime = 0.0f;
	//}
	//// 再生時間をセットする
	//MV1SetAttachAnimTime(mHandle, mAttachIndex, mPlayTime);
	//x += 150.0f * mDeltaTime;
	//z += 150.0f * mDeltaTime;
	//MV1SetPosition(mHandle, VGet(0.0f + 5.0f * sin(x * DX_PI_F / 180.0f), 0.0f, 10.0f + 5.0f * cos(z * DX_PI_F / 180.0f)));

	// タイトルカメラの更新
	//mTitleCamera->Update();
	mCamera->Update(VGet(0,0,-1), mPlayer->GetPosition());

	mPlayer->UpdateActor(mDeltaTime);
	mPlayer->Update(mDeltaTime);

	// タイトルUIの更新
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	if (0 <= mAlphaPal && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mAlphaPal += mFadeSpeed;
	}

	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new PlayScene();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void TitleScene::Draw()
{
#ifdef _DEBUG
	clsDx();
	printfDx("%f\n", mCamera->GetPositionX());
	printfDx("%f\n", mCamera->GetPositionY());
	printfDx("%f\n",mCamera->GetPositionZ());
#endif
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	// タイトルカメラの描画
	//mTitleCamera->Draw();

	mPlayer->Draw();
	// キャラ表示デバッグ用
	/*MV1DrawModel(mHandle);*/

	// タイトルUIの描画
	mTitleUI->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);




	//DrawFormatString(0, 0, GetColor(0, 255, 0), "delta:%f", mDeltaTime);
}

/// <summary>
/// 音楽
/// </summary>
void TitleScene::Sound()
{
	if (mStartButtonFlag && mAlphaPalFlag)
	{
		mBGM->FadeOutMusic(500, mDeltaTime);
	}
	else
	{
		mBGM->FadeInMusic(250, mDeltaTime);
	}

	if (mStartButtonFlag && mAlphaPalFlag && !mClickNormalFlag)
	{
		mClickNormalFlag = true;
		mClickNormal->Play();
	}

	if (!mBGMFlag)
	{
		mBGM->Play();
		mBGMFlag = true;
	}
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene::Load()
{
	//mTitleCamera = new TitleCamera;
	mCamera = new Camera;
	mTitleUI = new TitleUI;
	mBGM = new BGM;
	mClickNormal = new SE;
	mPlayer = new PlayerActor_kiyosumi;


	// タイトルカメラの初期化
	//mTitleCamera->Load();
	
	// タイトルUIの初期化
	mTitleUI->Load();
	mClickNormal->LoadSound("data/sound/click_normal.mp3");
	mBGM->LoadMusic("data/sound/サイクリング_3.mp3");

	mPlayer->LoadModel("data/model/player5/waterboy.pmx");
	mPlayer->SetScale(VGet(0.05f, 0.05f, 0.05f));
	mPlayer->SetRotation(VGet(0.0f, /*90.0f * DX_PI_F / 180.0f*/0.0f, 0.0f));
	mPlayer->SetPosition(VGet(0.0f, -1.0f, 1.0f));
}
