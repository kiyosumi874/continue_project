#include "DxLib.h"

#include "TitleScene_kiyosumi.h"
#include "PlayScene_kiyosumi.h"

#include "TitleUI.h"



/// <summary>
/// 初期化
/// </summary>
TitleScene_kiyosumi::TitleScene_kiyosumi()
	: mTitleUI(new TitleUI)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mSceneTransitionCount(0)
	, mStartButtonFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
TitleScene_kiyosumi::~TitleScene_kiyosumi()
{
	delete mTitleUI;
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
	// タイトルUIの初期化
	/*mTitleUI->Load();
	mDeltaTime = 0.000001f;
	mInputReturnFlag = false;
	mSceneTransitionCount = 0;
	mStartButtonFlag = false;*/
}
