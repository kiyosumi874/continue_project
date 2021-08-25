#pragma once
#include "Actor.h"

class PlayerActor_kiyosumi : public Actor
{
public:

	// 255個定義できます
	enum class PLAYER_STATE : unsigned char
	{
		STATE_IDLE,
		STATE_JUMP,

		STATE_NUM  // ステータスの個数
	};

	PlayerActor_kiyosumi();
	~PlayerActor_kiyosumi();

	void UpdateActor(float _deltaTime)override;

private:
	void IdleBehavior(float _deltaTime);
	void JumpBehavior(float _deltaTime);

	int   mAttachIndex;
	float mTotalTime;
	float mPlayTime;
	bool  mJumpFlag;

	PLAYER_STATE mNowState;
	PLAYER_STATE mPrevState;

};