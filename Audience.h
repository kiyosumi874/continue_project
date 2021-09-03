//--------------------------------------------------------
//8/30アクターを継承by矢野
//--------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "Actor.h"

#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience:public Actor
{
	enum
	{
		Idol,
		Normal
	};
public:
	Audience(const int in_GroundHeight,const int in_HighestJump);
	~Audience();
	void UpdateActor(float _deltaTime)override; //ダウンフラグのチェックに呼んで
	bool GetDownFlag()const { return mDownFlag; }//落下フラグのゲッター
	int SetAudienceState(int in_state) { return mAudienceState = in_state; }
private:
	int mAudienceState;
	int mGroundHeight;//着地する地面の高さ
	int mHighestJump; //ジャンプの限界
	bool mDownFlag;   //落下フラグ
};