//----------------------------------------------------------------------------------//
// @file         PlayCamera_shougo.h
// @brief        PlayCamera_shougoクラス
// @note         継承元:CameraBase_shougoクラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase_shougo.h"

class PlayCamera_shougo : public CameraBase_shougo
{
public:
	PlayCamera_shougo();    // コンストラクタ
	~PlayCamera_shougo();    // デストラクタ

	void Update()                override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

	void SetTargetPosition(const VECTOR& _targetPos) { mCameraTarget = _targetPos; }

private:
	VECTOR mCameraPosition;    // カメラの位置
	VECTOR mCameraTarget;      // カメラの注視点( 見ている座標 )
	VECTOR mCameraUp;          // カメラの上方向
};
