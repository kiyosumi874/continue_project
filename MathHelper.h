#pragma once
#include "DxLib.h"
class MathHelper
{
public:
    // ベクトルの回転
    static void RotateXZ(VECTOR& _inSelf, VECTOR& _inAim, float _inRotateSpeed);

    // _inTの割合でtargetベクトルに近づける
    static void Leap(VECTOR* _inSelf, const VECTOR& _inTarget, const float& _inT);
    // _inTの割合でtargetに近づける
    static void Leap(float* _inSelf, const float& _inTarget, const float& _inT);
    // _inTの割合でtargetに近づける
    static void Leap(int* _inSelf, const int& _inTarget, const float& _inT);

    // _inTの割合でtargetベクトルに近づけた値を引数で返す
    static VECTOR Leap(VECTOR _inSelf, const VECTOR& _inTarget, const float& _inT);
    // _inTの割合でtargetに近づけ値を引数で返す
    static float  Leap(float _inSelf, const float& _inTarget, const float& _inT);
    // _inTの割合でtargetに近づけ値を引数で返す
    static int    Leap(int _inSelf, const int& _inTarget, const float& _inT);

    // 向きベクトルに対してのラジアンを返す
    static float GetRadianXZ(const VECTOR& _inDirction);
    // 向きベクトルに対してのラジアンを返す
    static float GetRadianXY(const VECTOR& _inDirction);
    // 向きベクトルの方向にY軸回転
    static void RotateTagetDirectoinY(VECTOR* _inRotatePosition, const VECTOR& _inTargetDirction);
    static void RotateTagetDirectoinYRevers(VECTOR* _inRotatePosition, const VECTOR& _inTargetDirction);
    // ベクトルの成分表示
    static void PrintVector(const VECTOR& _inVector);
    // 3Dベクトルを向きと大きさを指定して位置を書き換える
    static void MoveVector3(VECTOR* _inPosition, const VECTOR& _inDirection, const float& _inSpeed);
    // _inTargetの方向へ_inSpeed分移動する
    static void MoveTargetPosition(VECTOR* _inPosition, const VECTOR& _inTargetPosition, const float& _inSpeed);
    // inpositionから_inTargetへの向きを返す
    static VECTOR Get2PointDirection(const VECTOR& _inPosition, const VECTOR& _inTargetPosition);
    // 矩形あたり判定
    static bool ColijonRectangle(const int& _inSelfX, const int& _inSelfY, const int& _inSelfWidth, const int& _inSelfHeight, const int& _inTargetX, const int& _inTargetY, const int& _inTargetWidth, const int& _inTargetHeight);
    static float GetLength(VECTOR& _inSelf, VECTOR& _inTarget);
    // 桁数を求める(整数)
    static int GetNumLength(const int& _inNum);
    // 上限下限を定めて値がオーバーした場合反対の限界値を返す
    static int WrapAround(const int& _inNum, const int& _inLowLimit, const int& _inHighLimit);
    // 指定の値に近づける
    static void CloseNaturalNum(int* _inNum, const int& _inTarget, const int& _inSpeed);

};