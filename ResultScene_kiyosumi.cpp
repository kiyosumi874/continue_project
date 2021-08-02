#include "DxLib.h"
#include "ResultScene_kiyosumi.h"
#include "TitleScene_kiyosumi.h"

/// <summary>
/// 初期化
/// </summary>
ResultScene_kiyosumi::ResultScene_kiyosumi()
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultUI(new ResultUI)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene_kiyosumi::~ResultScene_kiyosumi()
{
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
SceneBase* ResultScene_kiyosumi::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// リザルトUIの更新
	mResultUI->Update(mDeltaTime);

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
	// リザルトUIの描画
	mResultUI->Draw();
	// デバッグ用
	printfDx("今ResultScene_kiyosumi\n");
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene_kiyosumi::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene_kiyosumi::Load()
{
	// リザルトUIの初期化
	mResultUI->Load();
}
