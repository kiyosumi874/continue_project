//----------------------------------------------------------------------------------//
// @file         ResultCamera_shoguo.h
// @brief        ResultCamera_shougoクラス
// @note         継承元:CameraBaseクラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 8/ 5    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase_shougo.h"

class ResultCamera_shougo : public CameraBase_shougo
{
public:
	ResultCamera_shougo();    // コンストラクタ
	~ResultCamera_shougo();    // デストラクタ

	void Update()                override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

private:
	VECTOR mCameraPosition;    // カメラの位置
	VECTOR mCameraTarget;      // カメラの注視点( 見ている座標 )
	VECTOR mCameraUp;          // カメラの上方向

};