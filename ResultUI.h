//----------------------------------------------------------------------------------//
// @file         ResultUI.h
// @brief        ResultUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class ResultUI : public UIBase
{
public:
	ResultUI();    // �R���X�g���N�^
	~ResultUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Update(float _deltaTime, int& _hiScore);
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	void LoadScore(int _score);

	void AlphaCount(float _deltaTime);
	void AlphaCount2(float _deltaTime);


private:

	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
	int   mScore;        // �X�R�A
	int   mHiScore;        // �X�R�A

	// �E�B���h�E�T�C�Y(UI�z�u�̊)
	int mScreenSizeW;
	int mScreenSizeH;

	// �X�R�A�E�B���h�E�֘A
	int mHandleScoreWindow;
	int mSizeScoreWindowW;
	int mSizeScoreWindowH;
	int mPosScoreWindowX;
	int mPosScoreWindowY;
	double mScaleScoreWindow;

	// "Enter�L�[�������Ă�������"UI�p�ϐ�
	int   mHandlePressEnter;
	int mPosPressEnterX;
	int mPosPressEnterY;
	int mSizePressEnterW;
	int mSizePressEnterH;
	double mScalePressEnter;


	// �A���t�@����p
	int mAlphaPal;
	int mAlphaCount;
	int mAlphaPal2;
	int mAlphaCount2;

	int mFontHandle;
	int mFontHandle2;
	int mFontHandle2ex;
	int mFontHandle3;
	int mFontHandle3ex;
	int mFontHandle4;
	int mFontHandle4ex;
	
	int mHighScorePosX;
	int mHighScorePosY;
	int mThisTimeScorePosX;
	int mThisTimeScorePosY;
	int mSizeScoreW;
	int mSizeScoreH;
	int mHandle0;
	int mHandle100;
	int mHandle200;
	int mHandle300;
	int mHandle400;
	int mHandle500;
	int mHandle600;

	int mResultPosX;
	int mResultPosY;
	int mHandleResultFailed;
	int mHandleResultDeficient;
	int mHandleResultGood;
	int mHandleResultVGood;
	int mHandleResultExcellent;
};