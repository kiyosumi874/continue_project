//----------------------------------------------------------------------------------//
// @file         PlayUI.h
// @brief        PlayUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

enum class DRAW_GAME_STATE : unsigned char
{
	DRAW_CIRCLE_GAME,
	DRAW_GAUGE_GAME,
	DRAW_PENDULUM_GAME,
	DRAW_NULL
};


class PlayUI : public UIBase
{
public:
	PlayUI();    // �R���X�g���N�^
	~PlayUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��
	void Sound(class SE* _metoronome, class SE* _clickNormal, class SE* _clickClitical);


	bool GetPlayCircleGameFlag() { return mPlayCircleGameFlag; }
	bool GetPlayGaugeGameFlag() { return mPlayGaugeGameFlag; }
	bool GetPlayPendulumGameFlag() { return mPlayPendulumGameFlag; }

	void SetDrawGameState(DRAW_GAME_STATE _drawGameState) { mDrawGameState = _drawGameState; }

	// �X�R�A�̃Q�b�^�[
	int GetScore() { return mScore; }


	void CircleGameBehavior(float _deltaTime);
	void GaugeGameBehavior(float _deltaTime);
	void PendulumGameBehavior(float _deltaTime);

private:


	DRAW_GAME_STATE mDrawGameState;

	int   mScore;        // �X�R�A
	bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
	int   mFontHandle;
	bool mClickNormalFlag;
	bool mClickCriticalFlag;
	bool mMetoronomeFlag;

	//------------//
	//-CircleGame-//
	//------------//
	float mCircleSpeed;
	float mCircleOutX;                 // �`���~�̒��S���WX
	float mCircleOutY;                 // �`���~�̒��S���WY
	float mCircleOutRadius;            // �`���~�̔��a
	unsigned int mCircleOutColor;    // �~�̐F
	int mCircleOutFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�
	int mCircleOutLineThickness;     // �`���~�̐��̑���

	float mCircleInX;                 // �`���~�̒��S���WX
	float mCircleInY;                 // �`���~�̒��S���WY
	float mCircleInRadius;            // �`���~�̔��a
	unsigned int mCircleInColor;    // �~�̐F
	int mCircleInFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�

	bool mPlayCircleGameFlag;           // �T�[�N���Q�[�������Ă��邩���Ă��Ȃ�����Flag

	//-----------//
	//-GaugeGame-//
	//-----------//
	float mGaugeSpeed;
	float mGaugeOutBeginX;    // �`�悷��l�p�`�̍����X
	float mGaugeOutBeginY;    // �`�悷��l�p�`�̍����Y
	float mGaugeOutEndX;      // �`�悷��l�p�`�̉E��+1��X
	float mGaugeOutEndY;      // �`�悷��l�p�`�̉E��+1��Y
	unsigned int mGaugeOutColor;    // �`�悷��l�p�`�̐F
	int mGaugeOutFillFlag;          // �l�p�̒��g��h��Ԃ����A�̃t���O�BTRUE�œh��Ԃ��AFALSE�œh��Ԃ��Ȃ�

	float mGaugeInBeginX;    // �`�悷��l�p�`�̍����X
	float mGaugeInBeginY;    // �`�悷��l�p�`�̍����Y
	float mGaugeInEndX;      // �`�悷��l�p�`�̉E��+1��X
	float mGaugeInEndY;      // �`�悷��l�p�`�̉E��+1��Y
	unsigned int mGaugeInColor;    // �`�悷��l�p�`�̐F
	int mGaugeInFillFlag;          // �l�p�̒��g��h��Ԃ����A�̃t���O�BTRUE�œh��Ԃ��AFALSE�œh��Ԃ��Ȃ�

	bool mPlayGaugeGameFlag;    // �Q�[�W�Q�[�������Ă��邩���Ă��Ȃ�����Flag

	//--------------//
	//-PendulumGame-//
	//--------------//
	float mPendulumSpeed;
	float mPendulumOutX;                 // �`���~�̒��S���WX
	float mPendulumOutY;                 // �`���~�̒��S���WY
	float mPendulumOutRadius;            // �`���~�̔��a
	unsigned int mPendulumOutColor;    // �~�̐F
	int mPendulumOutFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�
	int mPendulumOutLineThickness;     // �`���~�̐��̑���

	float mPendulumInX;                 // �`���~�̒��S���WX
	float mPendulumInFx;                 // �x�_X
	float mPendulumInY;                 // �`���~�̒��S���WY
	float mPendulumInFy;                 // �x�_Y
	float mPendulumInAngle;            // �p�x
	float mPendulumInAngleSpeed;        // �p���x
	float mPendulumLength;                // �R�̒���
	float mPendulumInRadius;            // �`���~�̔��a
	unsigned int mPendulumInColor;    // �~�̐F
	int mPendulumInFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�
	
	bool mPlayPendulumGameFlag;           // �U��q�Q�[�������Ă��邩���Ă��Ȃ�����Flag

};