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
		STATE_PLAY_GAME1,
		STATE_PLAY_GAME2,
		STATE_PLAY_GAME3,

		STATE_RESULT_IDLE,

		STATE_NUM  // ステータスの個数
	};

	PlayerActor();
	~PlayerActor();

	void UpdateActor(float _deltaTime)override;

	void LoadGameCount(bool _gameCountFlag1, bool _gameCountFlag2, bool _gameCountFlag3);

	// セッター/ゲッター
	void SetPlayerState(PLAYER_STATE _nowState) { mNowState = _nowState; }
	PLAYER_STATE GetPlayerState() { return mNowState; }    

	PLAYER_STATE mNowState;
private:
	void TitleIdleBehavior(float _deltaTime);
	void TitleJumpBehavior(float _deltaTime);

	void PlayIdleBehavior(float _deltaTime);
	void PlayGame1Behavior(float _deltaTime);
	void PlayGame2Behavior(float _deltaTime);
	void PlayGame3Behavior(float _deltaTime);

	void ResultIdleBehavior(float _deltaTime);

	int   mAttachIndex;
	float mTotalTime;
	float mPlayTime;

	bool mGameCountFlag1;
	bool mGameCountFlag2;
	bool mGameCountFlag3;

	PLAYER_STATE mPrevState;

};