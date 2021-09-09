#include "Camera.h"
#include "MathHelper.h"

//------------------------------------------------------------------------------------//
// íËêî
const VECTOR  CAMERA_POS = VGet(0.0f, 0.0f, 0.0f);
const VECTOR  CAMERA_AIM_TARGET_POS = VGet(0.0f, 0.0f, 0.0f);
const float  CAMERA_NEAR = 1.0f;
const float  CAMERA_FAR = 1200.0f;
//------------------------------------------------------------------------------------//

Camera::Camera()
{
    //ÉJÉÅÉâÇÃï`âÊîÕàÕÇê›íË
    SetCameraNearFar(CAMERA_NEAR, CAMERA_FAR);
    SetupCamera_Perspective(60 * DX_PI_F / 180.0f);

    mNowPos = CAMERA_POS;
    mAimTargetPos = CAMERA_AIM_TARGET_POS;
    mFuturePos = CAMERA_POS;
    mFutureTarget = CAMERA_AIM_TARGET_POS;
    mSpeed = 5.0f;
}

Camera::~Camera()
{
}

void Camera::Update(const VECTOR& _inPosition, const VECTOR& _inTarget, float _deltaTime)
{
    //mNowPos = _inPosition;
    //mAimTargetPos = _inTarget;

    mFuturePos = VAdd(mFuturePos, VScale(VSub(mNowPos, mFuturePos), mSpeed * _deltaTime));
    mFutureTarget = VAdd(mFutureTarget, VScale(VSub(mAimTargetPos, mFutureTarget), mSpeed * _deltaTime));

    SetCameraPositionAndTarget_UpVecY(mFuturePos, mFutureTarget);
}


