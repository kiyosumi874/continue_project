#include "MathHelper.h"
#include <math.h>
//------------------------------------------------------------------------------------//
// �萔
const float ROTATE_MOVE_LIMIT = 0.0165f;
//------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------
// �x�N�g���̉�](XZ�̂�)
//-----------------------------------------------------------------------------
void MathHelper::RotateXZ(VECTOR& inSelf, VECTOR& inAim, float inRotateSpeed)
{
    //direction = VNorm(VAdd(VScale(VNorm(VSub(inAim, direction)), inRotaSpeed), direction));

    VECTOR sub = VSub(inAim, inSelf);
    float xflag = 1.0f;
    float zflag = 1.0f;

    if (sub.x < 0.0f)
    {
        xflag = -1.0f;
    }
    if (sub.z < 0.0f)
    {
        zflag = -1.0f;
    }

    if (sub.x * sub.x > inRotateSpeed * inRotateSpeed)
    {
        sub.x = inRotateSpeed * xflag;
    }
    if (sub.z * sub.z > inRotateSpeed * inRotateSpeed)
    {
        sub.z = inRotateSpeed * zflag;
    }

    /////////////////////////////////////////////////
    inSelf = VAdd(inSelf, sub);

}
//----------------------------------------------------//
// lerp(VECTOR a, const VECTOR v2, const float t)��
// answer = a + ((b-a) * t)
//----------------------------------------------------//
void MathHelper::Leap(VECTOR* inSelf, const VECTOR& inTarget, const float& inT)
{
    VECTOR positionToAim = VSub(inTarget, *inSelf);
    VECTOR scaledPositionToAim = VScale(positionToAim, inT);

    *inSelf = VAdd(*inSelf, scaledPositionToAim);
}
//----------------------------------------------------//
// �l�����̊�����target�܂ŋ߂Â���
//----------------------------------------------------//
void MathHelper::Leap(float* inSelf, const float& inTarget, const float& inT)
{
    *inSelf = *inSelf + (inTarget - *inSelf) * inT;
}
//----------------------------------------------------//
// �l�����̊�����target�܂ŋ߂Â���
//----------------------------------------------------//
void MathHelper::Leap(int* inSelf, const int& inTarget, const float& inT)
{
    *inSelf = (int)((float)*inSelf + ((float)inTarget - (float)*inSelf) * inT);
}

//----------------------------------------------------//
// lerp(VECTOR a, const VECTOR v2, const float t)��
// answer = a + ((b-a) * t)
//----------------------------------------------------//
VECTOR MathHelper::Leap(VECTOR inSelf, const VECTOR& inTarget, const float& inT)
{
    VECTOR positionToAim = VSub(inTarget, inSelf);
    VECTOR scaledPositionToAim = VScale(positionToAim, inT);

    return VAdd(inSelf, scaledPositionToAim);
}
//----------------------------------------------------//
// �l�����̊�����target�܂ŋ߂Â����l�������ŕԂ�
//----------------------------------------------------//
float MathHelper::Leap(float inSelf, const float& inTarget, const float& inT)
{
    return inSelf + (inTarget - inSelf) * inT;
}
//----------------------------------------------------//
// �l�����̊�����target�܂ŋ߂Â����l�������ŕԂ�
//----------------------------------------------------//
int MathHelper::Leap(int inSelf, const int& inTarget, const float& inT)
{
    return (int)((float)inSelf + ((float)inTarget - (float)inSelf) * inT);
}

//----------------------------------------------------//
// �����x�N�g���ɑ΂��Ẵ��W�A����Ԃ�
// -atan2�g�p
//----------------------------------------------------//
float MathHelper::GetRadianXY(const VECTOR& inDirection)
{
    float radian = (float)-atan2(-inDirection.x, -inDirection.y);
    return radian;
}
//----------------------------------------------------//
// �����x�N�g���ɑ΂��Ẵ��W�A����Ԃ�
// -atan2�g�p
//----------------------------------------------------//
float MathHelper::GetRadianXZ(const VECTOR& inDirection)
{
    float radian = (float)-atan2(-inDirection.x, -inDirection.z);
    return radian;
}
//----------------------------------------------------//
// �����x�N�g���̕�����Y����]
//----------------------------------------------------//
void MathHelper::RotateTagetDirectoinY(VECTOR* inRotatePosition, const VECTOR& inTargetDirction)
{
    MATRIX mat = MGetRotY(GetRadianXZ(inTargetDirction));
    *inRotatePosition = VTransform(*inRotatePosition, mat);
}
//----------------------------------------------------//
// �����x�N�g���̕�����Y����]
//----------------------------------------------------//
void MathHelper::RotateTagetDirectoinYRevers(VECTOR* inRotatePosition, const VECTOR& inTargetDirction)
{
    VECTOR dir;
    dir.x = -inTargetDirction.x;
    dir.y = -inTargetDirction.y;
    dir.z = -inTargetDirction.z;
    MATRIX mat = MGetRotY(GetRadianXZ(dir));
    *inRotatePosition = VTransform(*inRotatePosition, mat);
}
//----------------------------------------------------//
// 3�����x�N�g���̃v�����g�\��
//----------------------------------------------------//
void MathHelper::PrintVector(const VECTOR& inVector)
{
#if DEBUG_MODE
    printfDx("x:%f\n", inVector.x);
    printfDx("y:%f\n", inVector.y);
    printfDx("z:%f\n", inVector.z);
#endif
}
//----------------------------------------------------//
// 3�����x�N�g���������Ƒ傫�����w�肵�Ĉʒu������������
//----------------------------------------------------//
void MathHelper::MoveVector3(VECTOR* inPosition, const VECTOR& inDirection, const float& inSpeed)
{
    *inPosition = VAdd(*inPosition, VScale(inDirection, inSpeed));
}
//----------------------------------------------------//
// inTarget�̕�����inSpeed���ړ�����
//----------------------------------------------------//
void MathHelper::MoveTargetPosition(VECTOR* inPosition, const VECTOR& inTargetPosition, const float& inSpeed)
{
    *inPosition = VAdd(*inPosition, VScale(VNorm(VSub(inTargetPosition, *inPosition)), inSpeed));
}
//----------------------------------------------------//
// inposition����inTarget�ւ̌�����Ԃ�
//----------------------------------------------------//
VECTOR MathHelper::Get2PointDirection(const VECTOR& inPosition, const VECTOR& inTargetPosition)
{
    return VNorm(VSub(inTargetPosition, inPosition));
}
//----------------------------------------------------//
// ��`�����蔻��
//----------------------------------------------------//
bool MathHelper::ColijonRectangle(const int& inSelfX, const int& inSelfY, const int& inSelfWidth, const int& inSelfHeight, const int& inTargetX, const int& inTargetY, const int& inTargetWidth, const int& inTargetHeight)
{
    if (inSelfX < inTargetX + inTargetWidth && inSelfX + inSelfWidth > inTargetX &&
        inSelfY < inTargetY + inTargetHeight && inSelfY + inSelfWidth > inTargetY)
    {
        return true;
    }
    return false;
}
//----------------------//
// 2�x�N�g���Ԃ̋������擾
//----------------------//
float MathHelper::GetLength(VECTOR& inSelf, VECTOR& inTarget)
{
    float  length;
    return sqrtf(length = (inTarget.x - inSelf.x) * (inTarget.x - inSelf.x) +
        (inTarget.y - inSelf.y) * (inTarget.y - inSelf.y) +
        (inTarget.z - inSelf.z) * (inTarget.z - inSelf.z));
}
//----------------------//
// ���������߂�(����)
//----------------------//
int MathHelper::GetNumLength(const int& inNum)
{
    int tempNum = inNum;
    int length = 1;
    // ���������߂�
    while (tempNum >= 10)
    {
        tempNum /= 10;
        length++;
    }
    return length;
}
//------------------------------------------------------//
// ����������߂Ēl���I�[�o�[�����ꍇ���΂̌��E�l��Ԃ�
//------------------------------------------------------//
int MathHelper::WrapAround(const int& inNum, const int& inLowLimit, const int& inHighLimit)
{
    // �l���s���Ȃ�
    if (inLowLimit > inHighLimit)
    {
        return inNum;
    }

    const int num = (inNum - inLowLimit) % (inHighLimit - inLowLimit);
    if (num >= 0)
    {
        return (num + inLowLimit);
    }
    else
    {
        return (num + inHighLimit);
    }
}
//-------------------------------//
// �w��̒l�ɋ߂Â���
//-------------------------------//
void MathHelper::CloseNaturalNum(int* inNum, const int& inTarget, const int& inSpeed)
{
    if (*inNum == inTarget)
    {
        return;
    }
    if (*inNum < inTarget)
    {
        *inNum += inSpeed;
    }
    else
    {
        *inNum -= inSpeed;
    }
}