#include "DxLib.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "ResultCamera.h"
#include "ResultUI.h"
#include "Player.h"

/// <summary>
/// 初期化
/// </summary>
ResultScene::ResultScene(int _score)
	: mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mResultCamera(nullptr)
	, mResultUI(nullptr)
	, mScore(_score)
	, mAlphaPal(255)
	, mAlphaPalFlag(false)
	, mMoveSceneHandle(LoadGraph("data/img/MoveScene.png"))
	, mCheckHitFlag(false)
	, mPlayer(nullptr)
	, mFadeSpeed(3)
{
}

/// <summary>
/// 後処理
/// </summary>
ResultScene::~ResultScene()
{
	delete mResultCamera;
	delete mResultUI;
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
SceneBase* ResultScene::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime / 1000000.0f;
	// リザルトカメラの更新
	mResultCamera->Update();
	// リザルトUIの更新
	mResultUI->Update(mDeltaTime);
	// リザルトUIにスコアを渡す
	mResultUI->LoadScore(mScore);
	mPlayer->Update(mDeltaTime);

	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}


	if (mAlphaPal >= 0 && !mAlphaPalFlag)
	{
		mAlphaPal -= mFadeSpeed;
	}
	else
	{
		mAlphaPalFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag && mAlphaPalFlag)
	{
		mCheckHitFlag = true;
		mInputReturnFlag = false;
	}
	if (mCheckHitFlag)
	{
		mAlphaPal += mFadeSpeed;
	}
	// シーン遷移条件
	if (mAlphaPal >= 255)
	{
		// 条件を満たしていたら次のシーンを生成してそのポインタを返す
		return new TitleScene();
	}

	// シーンが変更されていなかったら自分のポインタを返す
	return this;
}

/// <summary>
/// 描画
/// </summary>
void ResultScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	mPlayer->Draw();
	// リザルトカメラの描画
	mResultCamera->Draw();
	// リザルトUIの描画
	mResultUI->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	DrawGraph(0, 0, mMoveSceneHandle, FALSE);
}

/// <summary>
/// 音楽
/// </summary>
void ResultScene::Sound()
{
}

/// <summary>
/// 初期化
/// </summary>
void ResultScene::Load()
{
	////「読み込み中」の表示
	//DrawString(0, 0, "Now Loading ...", GetColor(255, 255, 255));

	mResultCamera = new ResultCamera;
	mResultUI = new ResultUI;
	mPlayer = new Player;

	mPlayer->Load();
	// リザルトカメラの初期化
	mResultCamera->Load();
	// リザルトUIの初期化
	mResultUI->Load();

	mResultCamera->SetTargetPos(mPlayer->PlayerGetPosition());
}
