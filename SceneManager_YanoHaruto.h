#pragma once

class SceneManager_YanoHaruto
{
public:
	SceneManager_YanoHaruto();	// コンストラクタ
	~SceneManager_YanoHaruto();    // デストラクタ

	void Update(float _deltaTime);    // 更新
	void Draw();		              // 描画
	void Sound();		              // 音楽

	void SetScene(class SceneBase* _scene);    // Set関数 (初期化の時にしか使わない) (引数に名前をつけるときは最初にアンダーバーを入れる) (要調査)				

private:
	class SceneBase* mScene;    // シーンベースへのポインタメンバ変数 (要調査)
};