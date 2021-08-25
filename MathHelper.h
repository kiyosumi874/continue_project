#pragma once
#include "DxLib.h"
class MathHelper
{
public:
    // �x�N�g���̉�]
    static void RotateXZ(VECTOR& _inSelf, VECTOR& _inAim, float _inRotateSpeed);

    // _inT�̊�����target�x�N�g���ɋ߂Â���
    static void Leap(VECTOR* _inSelf, const VECTOR& _inTarget, const float& _inT);
    // _inT�̊�����target�ɋ߂Â���
    static void Leap(float* _inSelf, const float& _inTarget, const float& _inT);
    // _inT�̊�����target�ɋ߂Â���
    static void Leap(int* _inSelf, const int& _inTarget, const float& _inT);

    // _inT�̊�����target�x�N�g���ɋ߂Â����l�������ŕԂ�
    static VECTOR Leap(VECTOR _inSelf, const VECTOR& _inTarget, const float& _inT);
    // _inT�̊�����target�ɋ߂Â��l�������ŕԂ�
    static float  Leap(float _inSelf, const float& _inTarget, const float& _inT);
    // _inT�̊�����target�ɋ߂Â��l�������ŕԂ�
    static int    Leap(int _inSelf, const int& _inTarget, const float& _inT);

    // �����x�N�g���ɑ΂��Ẵ��W�A����Ԃ�
    static float GetRadianXZ(const VECTOR& _inDirction);
    // �����x�N�g���ɑ΂��Ẵ��W�A����Ԃ�
    static float GetRadianXY(const VECTOR& _inDirction);
    // �����x�N�g���̕�����Y����]
    static void RotateTagetDirectoinY(VECTOR* _inRotatePosition, const VECTOR& _inTargetDirction);
    static void RotateTagetDirectoinYRevers(VECTOR* _inRotatePosition, const VECTOR& _inTargetDirction);
    // �x�N�g���̐����\��
    static void PrintVector(const VECTOR& _inVector);
    // 3D�x�N�g���������Ƒ傫�����w�肵�Ĉʒu������������
    static void MoveVector3(VECTOR* _inPosition, const VECTOR& _inDirection, const float& _inSpeed);
    // _inTarget�̕�����_inSpeed���ړ�����
    static void MoveTargetPosition(VECTOR* _inPosition, const VECTOR& _inTargetPosition, const float& _inSpeed);
    // inposition����_inTarget�ւ̌�����Ԃ�
    static VECTOR Get2PointDirection(const VECTOR& _inPosition, const VECTOR& _inTargetPosition);
    // ��`�����蔻��
    static bool ColijonRectangle(const int& _inSelfX, const int& _inSelfY, const int& _inSelfWidth, const int& _inSelfHeight, const int& _inTargetX, const int& _inTargetY, const int& _inTargetWidth, const int& _inTargetHeight);
    static float GetLength(VECTOR& _inSelf, VECTOR& _inTarget);
    // ���������߂�(����)
    static int GetNumLength(const int& _inNum);
    // ����������߂Ēl���I�[�o�[�����ꍇ���΂̌��E�l��Ԃ�
    static int WrapAround(const int& _inNum, const int& _inLowLimit, const int& _inHighLimit);
    // �w��̒l�ɋ߂Â���
    static void CloseNaturalNum(int* _inNum, const int& _inTarget, const int& _inSpeed);

};