#include "DxLib.h"
#include "TitleCamera.h"

// SetCameraNearFarの引数
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// 初期化
/// </summary>
TitleCamera::TitleCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -2.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// 後処理
/// </summary>
TitleCamera::~TitleCamera()
{
}

/// <summary>
/// 更新処理
/// </summary>
void TitleCamera::Update()
{
}

/// <summary>
/// ロード
/// </summary>
void TitleCamera::Load()
{
}

/// <summary>
/// 描画処理
/// </summary>
void TitleCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
