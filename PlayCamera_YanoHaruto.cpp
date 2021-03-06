#include "DxLib.h"
#include "PlayCamera_YanoHaruto.h"

// SetCameraNearFarの引数
#define NEAR  1.0f
#define FAR 200.0f

/// <summary>
/// 初期化
/// </summary>
PlayCamera_YanoHaruto::PlayCamera_YanoHaruto()
	: mCameraPosition(VGet(45.0f, 53.0f, -18.0f))//観客全体(-30.0f, 15.0f, -30.0f)一体(-38.5f, 12.0f, -35.0f)pool(45.0f, 53.0f, -18.0f)
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// 後処理
/// </summary>
PlayCamera_YanoHaruto::~PlayCamera_YanoHaruto()
{
}

/// <summary>
/// 更新
/// </summary>
void PlayCamera_YanoHaruto::Update()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}

/// <summary>
/// ロード
/// </summary>
void PlayCamera_YanoHaruto::Load()
{
}

/// <summary>
/// 描画処理
/// </summary>
void PlayCamera_YanoHaruto::Draw()
{
}

