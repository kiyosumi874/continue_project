#pragma once
#include "CameraBase.h"
#include "Pool.h"
class PlayCamera_YanoHaruto : public CameraBase
{
	Pool* mPool;
public:
	PlayCamera_YanoHaruto();    // コンストラクタ
	~PlayCamera_YanoHaruto();    // デストラクタ

	void Update()                override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画
	VECTOR mSetTargetPos(const VECTOR& _Pos) {return mCameraTarget = _Pos; };
private:
	VECTOR mCameraPosition;    // カメラの位置
	VECTOR mCameraTarget;      // カメラの注視点( 見ている座標 )
	VECTOR mCameraUp;          // カメラの上方向
};