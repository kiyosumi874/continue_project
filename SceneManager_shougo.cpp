#include "SceneManager_shougo.h"
#include "PlayScene_shougo.h"
#include "ResultScene_shougo.h"
#include "TitleScene_shougo.h"

/// <summary>
/// 初期化
/// </summary>
SceneManager_shougo::SceneManager_shougo()
	: mScene(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
SceneManager_shougo::~SceneManager_shougo()
{
	delete mScene;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void SceneManager_shougo::Update(float _deltaTime)
{
	SceneBase* tmpScene = mScene->Update(_deltaTime);    // 現在のシーンを保存(publicの関数・変数を呼び出すときはアロー演算子(->)　要調査)
	if (tmpScene != mScene)   // シーンが切り替わった時
	{
		delete mScene;    // 直前のシーンを消す
		mScene = tmpScene;    // シーンを更新する
		mScene->Load();    // シーンの初期化
	}
}

/// <summary>
/// 描画
/// </summary>
void SceneManager_shougo::Draw()
{
	mScene->Draw();     // シーンを描画
}

/// <summary>
/// 音楽
/// </summary>
void SceneManager_shougo::Sound()
{
	mScene->Sound();    // BGMを流す
}

/// <summary>
/// Set関数
/// </summary>
/// <param name="_scene">シーン</param>
void SceneManager_shougo::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Sceneが空ではない場合
	{
		delete mScene;        // m_Sceneを消去
	}
	mScene = _scene;          // シーンの更新
	mScene->Load();          // シーンの初期化
}
