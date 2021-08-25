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
    float   GetPositionZ() const { return mNowPos.z; }                       // 値を返す                     // 値を返す
    void    Update(const VECTOR& _inPosition,          // 制御
                   const VECTOR& _inTarget);

private:
    VECTOR mAimTargetPos;
    VECTOR mNowPos;

};