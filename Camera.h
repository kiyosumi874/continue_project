#pragma once
#include "DxLib.h"

class Camera
{
public:
	Camera();
	~Camera();

    const VECTOR& GetPosition() const { return mNowPos; }                     // 値を返す
    float   GetPositionX() const { return mNowPos.x; }                       // 値を返す
    float   GetPositionY() const { return mNowPos.y; }                      // 値を返す
    float   GetPositionZ() const { return mNowPos.z; }                       // 値を返す
    float   GetAimTargetPositionX() const { return mAimTargetPos.x; }                       // 値を返す
    float   GetAimTargetPositionY() const { return mAimTargetPos.y; }                      // 値を返す
    float   GetAimTargetPositionZ() const { return mAimTargetPos.z; }                       // 値を返す
    void SetPos(const VECTOR& _Pos) { mNowPos = _Pos; }
    void SetFuturePos(const VECTOR& _futurePos) { mFuturePos = _futurePos; }
    const VECTOR& GetFuturePos() const { return mFuturePos; }
    const VECTOR& GetFutureTarget() const { return mFutureTarget; }
    void SetTarget(const VECTOR& _Target) { mAimTargetPos = _Target; }
    void SetFutureTarget(const VECTOR& _futureTarget) { mFutureTarget = _futureTarget; }
    void    Update(const VECTOR& _inPosition,          // 制御
                   const VECTOR& _inTarget,
                          float _deltaTime);

    void SetSpeed(float _speed) { mSpeed = _speed; }
private:
    VECTOR mAimTargetPos;
    VECTOR mNowPos;

    VECTOR mFuturePos;
    VECTOR mFutureTarget;

    float mSpeed;

};