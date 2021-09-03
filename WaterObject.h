#pragma once
#include "Actor.h"


class WaterObject : public Actor
{
public:

	WaterObject();
	~WaterObject();


	void UpdateActor(float _deltaTime) override;


	void ActivateWaterShader();

	void DrawWater();

private:

	int mNowTime, mOldTime;          // 現在時間、古い時間
	FLOAT4 mFGameTimes;              // 時間格納用


	int mDiffuseHandle;              // ディフューズマップ
	int mNormalHandle;               // ノーマルマップ
	int mHeightHandle;               // ハイトマップ


	int mPsHandle;                   // ピクセルシェーダーハンドル
	int mVsHandle;                   // 頂点シェーダーハンドル

};