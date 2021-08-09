//----------------------------------------------------------------------------------//
// @file         Player_shougo.h
// @brief        Player_shougoクラス
// @note                       
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     新規作成
//----------------------------------------------------------------------------------//

#pragma once

class Player_shougo
{
public:

	 Player_shougo();    // コンストラクタ
	~Player_shougo();    // デストラクタ

	void Update(float _deltaTime);    // 更新
	void Draw()                  ;    // 描画
	void Load()                  ;    // 初期化

private:
	float mDeltaTime;    // デルタタイム
	// キャラ表示
	int mModelHandle;
	int mAttachIndex;
	float mTotalTime;
	float mPlayTime;
};