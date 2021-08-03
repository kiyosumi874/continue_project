#include "DxLib.h"
#include "PlayCamera.h"

// SetCameraNearFarの引数
#define NEAR  1.0f
#define FAR 150.0f

/// <summary>
/// 初期化
/// </summary>
PlayCamera::PlayCamera()
	: mCameraPosition(VGet(0.0f, 0.0f, -2.0f))
	, mCameraTarget(VGet(0.0f, 0.0f, 0.0f))
	, mCameraUp(VGet(0.0f, 1.0f, 0.0f))
{
	SetCameraNearFar(NEAR, FAR);
}

/// <summary>
/// 後処理
/// </summary>
PlayCamera::~PlayCamera()
{
}

/// <summary>
/// 更新
/// </summary>
void PlayCamera::Update()
{
}

/// <summary>
/// ロード
/// </summary>
void PlayCamera::Load()
{
}

/// <summary>
/// 描画処理
/// </summary>
void PlayCamera::Draw()
{
	SetCameraPositionAndTargetAndUpVec(mCameraPosition, mCameraTarget, mCameraUp);
}

