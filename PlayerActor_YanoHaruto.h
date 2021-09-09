#pragma once
#include "Actor.h"

class PlayerActor_YanoHaruto :
    public Actor
{
public:

	// 255個定義できます
	enum class PLAYER_STATE : unsigned char
	{
		STATE_TITLE_IDLE,

		STATE_PLAY_IDLE,
		STATE_PLAY_RUN,
		STATE_PLAY_GAME1,
		STATE_PLAY_GAME2,
		STATE_PLAY_GAME3,
		STATE_PLAY_JUMP,

		STATE_RESULT_IDLE,

		STATE_NUM  // ステータスの個数
	};

	PlayerActor_YanoHaruto();
	~PlayerActor_YanoHaruto();

	void UpdateActor(float _deltaTime)override;
	void Load();

	// セッター/ゲッター
	void SetPlayerState(PLAYER_STATE _nowState) { mNowState = _nowState; }
	PLAYER_STATE GetPlayerState() { return mNowState; }
	float GetPlayTime() { return mPlayTime; }
	PLAYER_STATE mNowState;
private:
	void TitleIdleBehavior(float _deltaTime);

	void PlayIdleBehavior(float _deltaTime);
	void PlayRunBehavior(float _deltaTime);
	void PlayGame1Behavior(float _deltaTime);
	void PlayGame2Behavior(float _deltaTime);
	void PlayGame3Behavior(float _deltaTime);
	void PlayJumpBehavior(float _deltaTime);

	void ResultIdleBehavior(float _deltaTime);

	int   mAttachIndex;
	class Effect* mAura;
	float mTotalTime;
	float mPlayTime;
	class Effect* mWind;

	PLAYER_STATE mPrevState;
};

