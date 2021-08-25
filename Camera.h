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
    float   GetPositionZ() const { return mNowPos.z; }                       // �l��Ԃ�                     // �l��Ԃ�
    void    Update(const VECTOR& _inPosition,          // ����
                   const VECTOR& _inTarget);

private:
    VECTOR mAimTargetPos;
    VECTOR mNowPos;

};