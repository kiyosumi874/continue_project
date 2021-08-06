#include "DxLib.h"
#include "ResultCamera.h"

// SetCameraNearFarの引数
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// 初期化
/// </summary>
ResultCamera::ResultCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -1.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// 後処理
/// </summary>
ResultCamera::~ResultCamera()
{
}

/// <summary>
/// 更新
/// </summary>
void ResultCamera::Update()
{
}

/// <summary>
/// ロード
/// </summary>
void ResultCamera::Load()
{
}

/// <summary>
/// 描画処理
/// </summary>
void ResultCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}
