//----------------------------------------------------------------------------------//
// @file         TitleCamera.h
// @brief        TitleCameraクラス
// @note         継承元:CameraBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/ 2    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "CameraBase.h"


class TitleCamera : public CameraBase
{
public:
	 TitleCamera();    // コンストラクタ
	~TitleCamera();    // デストラクタ

	void Update()                override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

	VECTOR SetTargetPos(const VECTOR& _pos) { return mCameraTarget = _pos; };

private:
	VECTOR mCameraPosition;    // カメラの位置
	VECTOR mCameraTarget;      // カメラの注視点( 見ている座標 )
	VECTOR mCameraUp;          // カメラの上方向


};