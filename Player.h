//----------------------------------------------------------------------------------//
// @file         Player.h
// @brief        Playerクラス
// @note                       
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
class Player
{
public:

	 Player();    // コンストラクタ
	~Player();    // デストラクタ

	void Update(float _deltaTime);    // 更新
	void Draw()                  ;    // 描画
	void Load()                  ;    // 初期化

	const VECTOR& PlayerGetPosition() const{return mPlayerPos;}

private:
	float mDeltaTime;    // デルタタイム
	// キャラ表示
	VECTOR mPlayerPos;
	VECTOR mScale;   // モデルの拡大値
	int mModelHandle;
	int mAttachIndex;
	float mTotalTime;
	float mPlayTime;
	bool mJumpFlag;
};