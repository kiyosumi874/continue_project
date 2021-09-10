//----------------------------------------------------------------------------------//
// @file         SceneManager_kiyosumi.h
// @brief        SceneManager_kiyosumiクラス
// @note         シーンの管理クラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class SceneManager_kiyosumi
{
public:
	 SceneManager_kiyosumi();	// コンストラクタ
	~SceneManager_kiyosumi();    // デストラクタ

	void Update(float _deltaTime, int& _hiScore);    // 更新
	void Draw();		              // 描画
	void Sound(float _deltaTime);		              // 音楽

	void SetScene(class SceneBase* _scene);    // Set関数 (初期化の時にしか使わない) (引数に名前をつけるときは最初にアンダーバーを入れる) (要調査)				

private:
	class SceneBase* mScene;    // シーンベースへのポインタメンバ変数 (要調査)
	
};
