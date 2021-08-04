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

private:
	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
	int   mScore;        // �X�R�A
	bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
	float mGameTransitionCount;// �~�߂�J�E���g
	int   mGameCount;          // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���
	bool  mGameCountFlag1;     // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���Flag
	bool  mGameCountFlag2;     // ������Ǝ��̃~�j�Q�[���ɑJ�ڂ���Flag

	//------------//
	//-CircleGame-//
	//------------//
	int mCircleOutX;                 // �`���~�̒��S���WX
	int mCircleOutY;                 // �`���~�̒��S���WY
	int mCircleOutRadius;            // �`���~�̔��a
	unsigned int mCircleOutColor;    // �~�̐F
	int mCircleOutFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�
	int mCircleOutLineThickness;     // �`���~�̐��̑���

	int mCircleInX;                 // �`���~�̒��S���WX
	int mCircleInY;                 // �`���~�̒��S���WY
	int mCircleInRadius;            // �`���~�̔��a
	unsigned int mCircleInColor;    // �~�̐F
	int mCircleInFillFlag;          // TRUE(1�̈�)�ŉ~�̒��g���h��Ԃ��AFALSE(0�̈�)�ŗ֊s�̂�

	bool mPlayCircleGame;           // �T�[�N���Q�[�������Ă��邩���Ă��Ȃ�����Flag
	bool mDrawCircleGame;           // �T�[�N���Q�[����`�悵�Ă��邩���Ă��Ȃ�����Flag

	//-----------//
	//-GaugeGame-//
	//-----------//
	int mGaugeOutBeginX;    // �`�悷��l�p�`�̍����X
	int mGaugeOutBeginY;    // �`�悷��l�p�`�̍����Y
	int mGaugeOutEndX;      // �`�悷��l�p�`�̉E��+1��X
	int mGaugeOutEndY;      // �`�悷��l�p�`�̉E��+1��Y
	unsigned int mGaugeOutColor;    // �`�悷��l�p�`�̐F
	int mGaugeOutFillFlag;          // �l�p�̒��g��h��Ԃ����A�̃t���O�BTRUE�œh��Ԃ��AFALSE�œh��Ԃ��Ȃ�

	int mGaugeInBeginX;    // �`�悷��l�p�`�̍����X
	int mGaugeInBeginY;    // �`�悷��l�p�`�̍����Y
	int mGaugeInEndX;      // �`�悷��l�p�`�̉E��+1��X
	int mGaugeInEndY;      // �`�悷��l�p�`�̉E��+1��Y
	unsigned int mGaugeInColor;    // �`�悷��l�p�`�̐F
	int mGaugeInFillFlag;          // �l�p�̒��g��h��Ԃ����A�̃t���O�BTRUE�œh��Ԃ��AFALSE�œh��Ԃ��Ȃ�

	bool mPlayGaugeGame;    // �Q�[�W�Q�[�������Ă��邩���Ă��Ȃ�����Flag
	bool mDrawGaugeGame;    // �Q�[�W�Q�[����`�悵�Ă��邩���Ă��Ȃ�����Flag


};