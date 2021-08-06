//----------------------------------------------------------------------------------//
// @file         SceneManager_shougo.h
// @brief        SceneManager_shougoクラス
// @note         シーンの管理クラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class SceneManager_shougo
{
public:
	SceneManager_shougo();	// コンストラクタ
	~SceneManager_shougo();    // デストラクタ

	void Update(float _deltaTime);    // 更新
	void Draw();		              // 描画
	void Sound();		              // 音楽

	void SetScene(class SceneBase* _scene);    // Set関数 (初期化の時にしか使わない) (引数に名前をつけるときは最初にアンダーバーを入れる) (要調査)				

private:
	class SceneBase* mScene;    // シーンベースへのポインタメンバ変数 (要調査)

};
