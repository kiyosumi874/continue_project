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

class PlayUI : public UIBase
{
public:
	PlayUI();    // �R���X�g���N�^
	~PlayUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��
	void Sound();

	// GameCountFlag3�̃t���O�̃Q�b�^�[
	const bool& GetGameCountFlag3() const { return mGameCountFlag3; }
	// �X�R�A�̃Q�b�^�[
	const int& GetScore() const { return mScore; }


private:
	class SE* mMetoronome;
	class SE* mClickNormal;
	class SE* mClickClitical;

	float mDeltaTime;    // �f���^�^�C��
	int   mScore;        // �X�R�A
	bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
	float mGameTransitionCount;// �~�߂�J�E���g
	int   mGameCount;          // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���
	bool  mGameCountFlag1;     // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���Flag
	bool  mGameCountFlag2;     // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���Flag
	bool  mGameCountFlag3;     // �Ō�̃~�j�Q�[�����I��������ǂ�����Flag
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
	bool mDrawCircleGameFlag;           // �T�[�N���Q�[����`�悵�Ă��邩���Ă��Ȃ�����Flag

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
	bool mDrawGaugeGameFlag;    // �Q�[�W�Q�[����`�悵�Ă��邩���Ă��Ȃ�����Flag

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
	bool mDrawPendulumGameFlag;           // �U��q�Q�[����`�悵�Ă��邩���Ă��Ȃ�����Flag

};