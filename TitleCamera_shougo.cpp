#include "DxLib.h"
#include "TitleCamera_shougo.h"

// SetCameraNearFarの引数
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// 初期化
/// </summary>
TitleCamera_shougo::TitleCamera_shougo()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// 後処理
/// </summary>
TitleCamera_shougo::~TitleCamera_shougo()
{
}

/// <summary>
/// 更新処理
/// </summary>
void TitleCamera_shougo::Update()
{
}

/// <summary>
/// ロード
/// </summary>
void TitleCamera_shougo::Load()
{
}

/// <summary>
/// 描画処理
/// </summary>
void TitleCamera_shougo::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
