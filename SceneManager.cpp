#include "SceneManager.h"
#include "PlayScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

/// <summary>
/// 初期化
/// </summary>
SceneManager::SceneManager()
	: mScene(nullptr)
{
}

/// <summary>
/// 後処理
/// </summary>
SceneManager::~SceneManager()
{
	delete mScene;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void SceneManager::Update(float _deltaTime, int& _hiScore)
{
	SceneBase* tmpScene = mScene->Update(_deltaTime, _hiScore);    // 現在のシーンを保存(publicの関数・変数を呼び出すときはアロー演算子(->)　要調査)
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
void SceneManager::Draw()
{
	mScene->Draw();     // シーンを描画
}

/// <summary>
/// 音楽
/// </summary>
void SceneManager::Sound(float _deltaTime)
{
	mScene->Sound(_deltaTime);    // BGMを流す
}

/// <summary>
/// Set関数
/// </summary>
/// <param name="_scene">シーン</param>
void SceneManager::SetScene(SceneBase* _scene)
{
	if (mScene != nullptr)    // m_Sceneが空ではない場合
	{
		delete mScene;        // m_Sceneを消去
	}
	mScene = _scene;          // シーンの更新
	mScene->Load();          // シーンの初期化
}
