#include "DxLib.h"
#include "ResultScene_shougo.h"
#include "TitleScene_shougo.h"
#include "ResultCamera_shougo.h"
#include "ResultUI.h"

/// <summary>
/// 初期化
/// </summary>
ResultScene_shougo::ResultScene_shougo(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultCamera(nullptr)
	, mResultUI(nullptr)
	, mScore(_score)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene_shougo::~ResultScene_shougo()
{
	delete mResultCamera;
	delete mResultUI;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
/// <returns>
/// Enterを押したときに次のシーンのInstanceのポインタを返す
/// それ以外は自分のポインタを返す
/// </returns>
SceneBase* ResultScene_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	// リザルトカメラの更新
	mResultCamera->Update();
	// リザルトUIの更新
	mResultUI->Update(mDeltaTime);
	// リザルトUIにスコアを渡す
	mResultUI->LoadScore(mScore);

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}



	// シーン遷移条件
	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new TitleScene_shougo();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void ResultScene_shougo::Draw()
{
	// リザルトカメラの描画
	mResultCamera->Draw();
	// リザルトUIの描画
	mResultUI->Draw();
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene_shougo::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene_shougo::Load()
{
	mResultCamera = new ResultCamera_shougo;
	mResultUI = new ResultUI;

	// リザルトカメラの初期化
	mResultCamera->Load();
	// リザルトUIの初期化
	mResultUI->Load();
}
