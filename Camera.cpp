#include "Camera.h"
#include "MathHelper.h"

//------------------------------------------------------------------------------------//
// íËêî
const VECTOR  CAMERA_POS = VGet(0.0f, 0.0f, 0.0f);
const VECTOR  CAMERA_AIM_TARGET_POS = VGet(0.0f, 0.0f, 0.0f);
const float  CAMERA_NEAR = 1.0f;
const float  CAMERA_FAR = 150.0f;
//------------------------------------------------------------------------------------//

Camera::Camera()
{
    //ÉJÉÅÉâÇÃï`âÊîÕàÕÇê›íË
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
    SetupCamera_Perspective(60 * DX_PI_F / 180.0f);

    mNowPos = CAMERA_POS;
    mAimTargetPos = CAMERA_AIM_TARGET_POS;
}

Camera::~Camera()
{
}

void Camera::Update(const VECTOR& _inPosition, const VECTOR& _inTarget)
{
    mNowPos = _inPosition;
    mAimTargetPos = _inTarget;

    SetCameraPositionAndTarget_UpVecY(mNowPos, mAimTargetPos);
}
