//----------------------------------------------------------------------------------//
// @file         PlayerActor.h
// @brief        PlayerActor�N���X
// @note         �p����:Actor�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/24    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "Actor.h"

class PlayerActor : public Actor
{
public:

	// 255��`�ł��܂�
	enum class PLAYER_STATE : unsigned char
	{
		STATE_TITLE_IDLE,

		STATE_PLAY_IDLE,
		STATE_PLAY_RUN,
		STATE_PLAY_GAME1,
		STATE_PLAY_GAME2,
		STATE_PLAY_GAME3,
		STATE_PLAY_JUMP,
		STATE_PLAY_JUMP2,
		STATE_PLAY_FLOAT,

		STATE_RESULT_IDLE,

		STATE_NUM  // �X�e�[�^�X�̌�
	};

	PlayerActor();
	~PlayerActor();

	void UpdateActor(float _deltaTime)override;

	// �Z�b�^�[/�Q�b�^�[
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
	void PlayJump2Behavior(float _deltaTime);
	void PlayFloatBehavior(float _deltaTime);

	void ResultIdleBehavior(float _deltaTime);

	int   mAttachIndex;
	float mTotalTime;
	float mPlayTime;

	PLAYER_STATE mPrevState;

	class Effect* mAura;
	class Effect* mWind;

	

};