//----------------------------------------------------------------------------------//
// @file         PlayerActor.h
// @brief        PlayerActorクラス
// @note         継承元:Actorクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/24    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "Actor.h"

class PlayerActor : public Actor
{
public:

	// 255個定義できます
	enum class PLAYER_STATE : unsigned char
	{
		STATE_TITLE_IDLE,
		STATE_TITLE_JUMP,

		STATE_PLAY_IDLE,

		STATE_RESULT_IDLE,

		STATE_NUM  // ステータスの個数
	};

	PlayerActor();
	~PlayerActor();

	void UpdateActor(float _deltaTime)override;
	void SetPlayerState(PLAYER_STATE _nowState) { mNowState = _nowState; }

private:
	void TitleIdleBehavior(float _deltaTime);
	void TitleJumpBehavior(float _deltaTime);

	void PlayIdleBehavior(float _deltaTime);

	void ResultIdleBehavior(float _deltaTime);

	int   mAttachIndex;
	float mTotalTime;
	float mPlayTime;
	bool  mJumpFlag;

	PLAYER_STATE mNowState;
	PLAYER_STATE mPrevState;

};