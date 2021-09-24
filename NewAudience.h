#pragma once
#include "DxLib.h"
#include "Actor.h"
/// <summary>
/// 9/10矢野
/// </summary>
class NewAudience :
    public Actor
{
public:
    NewAudience();
    ~NewAudience();
    void UpdateActor(float _deltaTime);//ジャンプ処理
    float SetHigestJump(float _HighestJump) { return mHighestJump = _HighestJump; }
    float SetGroundHeight(float _GroundHight) { return mGroundHight = _GroundHight; }
    float SetRad(float _Rad) { return mRad = _Rad; }
private:
    float mHighestJump;                 //ジャンプ最高高度
    float mGroundHight;                //地面最高高度
    float mJumpPower;                   //ジャンプ力
    bool  mJumpFlag;                     //trueなら上がるfalseなら下がる
    float mRad;												  //角度ラジアン
 };

