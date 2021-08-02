//----------------------------------------------------------------------------------//
// @file         PlayerActor_shougo.h
// @brief        PlayerActor_shougoクラス
// @note         PlayerActor_shougoクラス
// @author       井口 翔悟 (iguchi shougo, @2021)
// @changelog
// 2021/ 8/1    新規作成
//----------------------------------------------------------------------------------//

#pragma once

class PlayerActor
{
public:
	 PlayerActor();    // コンストラクタ
	~PlayerActor();    // デストラクタ

	void Update(float _deltaTime);    // 更新処理
	void   Draw()                ;    // 描画処理
	void   Init()                ;    // 初期化処理

private:
	VECTOR mPlayerPos;    // プレイヤーのポジション
	VECTOR mVelocity ;    // 移動加速度
	VECTOR mMove     ;    // 移動速度

	int mModelHandle ;    // モデルハンドル
};