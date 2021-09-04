#pragma once
#include "Actor.h"


class WaterObject : public Actor
{
public:

	WaterObject();
	~WaterObject();

	void UpdateActor(float _deltaTime) override;

	void UpdateWaterShader(float _deltaTime);

	void DrawWater();

private:


	int mNowTime, mOldTime;          // 現在時間、古い時間
	FLOAT4 mFGameTimes;              // 時間格納・シェーダ―送信用float(x4)アレイ


	int mDiffuseHandle;              // ディフューズマップ
	int mNormalHandle;               // ノーマルマップ
	int mHeightHandle;               // ハイトマップ (※未使用)


	int mPsHandle;                   // ピクセルシェーダーハンドル
	int mVsHandle;                   // 頂点シェーダーハンドル

};