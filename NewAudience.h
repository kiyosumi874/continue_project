#pragma once
#include "DxLib.h"
#include "Actor.h"
/// <summary>
/// 9/10���
/// </summary>
class NewAudience :
    public Actor
{
public:
    NewAudience();
    ~NewAudience();
    void UpdateActor(float _deltaTime);//�W�����v����
    float SetHigestJump(float _HighestJump) { return mHighestJump = _HighestJump; }
    float SetGroundHeight(float _GroundHight) { return mGroundHight = _GroundHight; }
    float SetRad(float _Rad) { return mRad = _Rad; }
private:
    float mHighestJump;                 //�W�����v�ō����x
    float mGroundHight;                //�n�ʍō����x
    float mJumpPower;                   //�W�����v��
    bool  mJumpFlag;                     //true�Ȃ�オ��false�Ȃ牺����
    float mRad;												  //�p�x���W�A��
 };

