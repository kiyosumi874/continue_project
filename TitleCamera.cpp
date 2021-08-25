#include "DxLib.h"
#include "TitleCamera.h"

//---------------------------------------------
// 定数
const float CAMERA_NEAR = 1.0f;
const float CAMERA_FAR  = 150.0f;
const VECTOR CAMERA_POSITION = VGet(0.0f, 0.0f, -1.0f);
const VECTOR CAMERA_TARGET = VGet(0.0f, 0.0f, 0.0f);
const VECTOR CAMERA_UP = VGet(0.0f, 1.0f, 0.0f);
//---------------------------------------------

/// <summary>
/// 初期化
/// </summary>
TitleCamera::TitleCamera()
	: mCameraPosition(CAMERA_POSITION)
	, mCameraTarget(CAMERA_TARGET)
	, mCameraUp(CAMERA_UP)
{
	SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
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
