#pragma once
#include "DxLib.h"

class Camera
{
public:
	Camera();
	~Camera();

    const VECTOR& GetPosition() const { return mNowPos; }                     // �l��Ԃ�
    float   GetPositionX() const { return mNowPos.x; }                       // �l��Ԃ�
    float   GetPositionY() const { return mNowPos.y; }                      // �l��Ԃ�
    float   GetPositionZ() const { return mNowPos.z; }                       // �l��Ԃ�
    float   GetAimTargetPositionX() const { return mAimTargetPos.x; }                       // �l��Ԃ�
    float   GetAimTargetPositionY() const { return mAimTargetPos.y; }                      // �l��Ԃ�
    float   GetAimTargetPositionZ() const { return mAimTargetPos.z; }                       // �l��Ԃ�
    void SetPos(const VECTOR& _Pos) { mNowPos = _Pos; }
    void SetFuturePos(const VECTOR& _futurePos) { mFuturePos = _futurePos; }
    const VECTOR& GetFuturePos() const { return mFuturePos; }
    const VECTOR& GetFutureTarget() const { return mFutureTarget; }
    void SetTarget(const VECTOR& _Target) { mAimTargetPos = _Target; }
    void SetFutureTarget(const VECTOR& _futureTarget) { mFutureTarget = _futureTarget; }
    void    Update(const VECTOR& _inPosition,          // ����
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