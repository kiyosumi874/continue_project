//----------------------------------------------------------------------------------//
// @file         Object_shougo.h
// @brief        Object_shougoクラス
// @note                       
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     新規作成
//----------------------------------------------------------------------------------//

#pragma once

class Object_shougo
{
public:
	 Object_shougo();    // コンストラクタ
	~Object_shougo();    // デストラクタ

	void Update(float _deltaTime);    // 更新
	void Draw()                  ;    // 描画
	void Load()                  ;    // 初期化

private:
	float mDeltaTime;    // デルタタイム

	// モデル表示
	int mModelHandle;

};