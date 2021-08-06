#include "DxLib.h"
#include <math.h>

#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"

#include "TitleUI.h"
#include "TitleCamera.h"



/// <summary>
/// 初期化
/// </summary>
TitleScene_kiyosumi::TitleScene_kiyosumi()
	: mTitleCamera(nullptr)
	, mTitleUI(nullptr)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
{
	// キャラ表示デバッグ用
	mHandle = MV1LoadModel("data/model/player4/かれん.pmx");
	mAttachIndex = MV1AttachAnim(mHandle, 0, -1, FALSE);
	mTotalTime = MV1GetAttachAnimTotalTime(mHandle, mAttachIndex);
	mPlayTime = 0.0f; 
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -7.0, 10));
	x = 0.0f;
	z = 0.0f;
}

/// <summary>
/// 後処理
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mTitleCamera;
	delete mTitleUI;
	MV1DeleteModel(mHandle);
	MV1DetachAnim(mHandle, mAttachIndex);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* TitleScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// キャラ表示デバッグ用
	mPlayTime += 50.0f * mDeltaTime;
	// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
	if (mPlayTime >= mTotalTime)
	{
		mPlayTime = 0.0f;
	}
	// 再生時間をセットする
	MV1SetAttachAnimTime(mHandle, mAttachIndex, mPlayTime);
	x += 150.0f * mDeltaTime;
	z += 150.0f * mDeltaTime;
	MV1SetPosition(mHandle, VGet(0.0f+5*sin(x*DX_PI_F/180.0f), -7.0f, 10.0f + 5*cos(z * DX_PI_F / 180.0f)));

	// タイトルカメラの更新
	mTitleCamera->Update();


	// タイトルUIの更新
	mTitleUI->Update(mDeltaTime);
	mStartButtonFlag = mTitleUI->GetStartButtonFlag();
	
	//// Enterキーの連続入力防止
	//if (!CheckHitKey(KEY_INPUT_RETURN))
	//{
	//	mInputReturnFlag = true;
	//}

	if (mStartButtonFlag)
	{
		mSceneTransitionCount += 1.0f * mDeltaTime;
	}

	// シーン遷移条件
	if (mSceneTransitionCount >= 0.5f)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new PlayScene_kiyosumi();
	}

	//// シーン遷移条件
	//if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	//{
	//	mInputReturnFlag = false;
	//	// 条件を満たしていたら次のシーンを生成してそのポインタを返す
	//	return new PlayScene_kiyosumi();
	//}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void TitleScene_kiyosumi::Draw()
{
	// タイトルカメラの描画
	mTitleCamera->Draw();

	// キャラ表示デバッグ用
	MV1DrawModel(mHandle);

	// タイトルUIの描画
	mTitleUI->Draw();
}

/// <summary>
/// 音楽
/// </summary>
void TitleScene_kiyosumi::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void TitleScene_kiyosumi::Load()
{
	mTitleCamera = new TitleCamera;
	mTitleUI = new TitleUI;

	// タイトルカメラの初期化
	mTitleCamera->Load();
	// タイトルUIの初期化
	mTitleUI->Load();

}
