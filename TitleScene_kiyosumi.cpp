#include "DxLib.h"

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
	, mRotate(0.0f)
{
	// キャラ表示デバッグ用
	mHandle = MV1LoadModel("data/model/player/Alicia_solid.pmx");
	MV1SetScale(mHandle, VGet(0.5f, 0.5f, 0.5f));
	MV1SetPosition(mHandle, VGet(0, -5, 10));

}

/// <summary>
/// 後処理
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mTitleCamera;
	delete mTitleUI;
	MV1DeleteModel(mHandle);
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
	// タイトルカメラの更新
	mTitleCamera->Update();


	// キャラ表示デバッグ用
	mRotate += 5.0f * mDeltaTime;
	MV1SetRotationXYZ(mHandle, VGet(0.0f, mRotate, 0.0f));

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
