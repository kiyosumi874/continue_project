//----------------------------------------------------------------------------------//
// @file         PlayerActor_kiyosumi.h
// @brief        PlayerActor_kiyosumi�N���X
// @note         �p����:Actor�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 8/24    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "Actor.h"

class PlayerActor_kiyosumi : public Actor
{
public:

	// 255��`�ł��܂�
	enum class PLAYER_STATE : unsigned char
	{
		STATE_TITLE_IDLE,
		STATE_TITLE_JUMP,

		STATE_PLAY_IDLE,

		STATE_RESULT_IDLE,

		STATE_NUM  // �X�e�[�^�X�̌�
	};

	PlayerActor_kiyosumi();
	~PlayerActor_kiyosumi();

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