#include "DxLib.h"
#include "ResultUI.h"
#include "PlayUI.h"


/// <summary>
/// ������
/// </summary>
ResultUI::ResultUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
	, mScore(0)
	, mAlphaPal(0)
	, mAlphaCount(1)
	, mAlphaPal2(0)
	, mAlphaCount2(1)
	, mScalePressEnter(0.6)
{
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle2 = CreateFontToHandle("data/Fonts/meiryob.tcc", 130, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, TRUE);
	mFontHandle2ex = CreateFontToHandle("data/Fonts/meiryob.tcc", 130, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle3 = CreateFontToHandle("data/Fonts/meiryob.tcc", 120, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, TRUE);
	mFontHandle3ex = CreateFontToHandle("data/Fonts/meiryob.tcc", 120, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle4 = CreateFontToHandle("data/Fonts/BIZ-UDGothicB.tcc", 210, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 2, FALSE);
	mFontHandle4ex = CreateFontToHandle("data/Fonts/BIZ-UDGothicR.tcc", 200, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 2, FALSE);
	
	// ��ʃT�C�Y�̎擾
	GetWindowSize(&mScreenSizeW, &mScreenSizeH);

	// �X�R�A�E�B���h�E�̃��[�h
	mHandleScoreWindow = LoadGraph("data/img/ResultUI.png");
	GetGraphSize(mHandleScoreWindow, &mSizeScoreWindowW, &mSizeScoreWindowH);
	mScaleScoreWindow = 1.0;
	mPosScoreWindowX = mScreenSizeW - (mScreenSizeW / 4);
	mPosScoreWindowY = mScreenSizeH / 2;

	mHandlePressEnter = LoadGraph("data/img/ResultUI2.png");
	GetGraphSize(mHandlePressEnter, &mSizePressEnterW, &mSizePressEnterH);
	mPosPressEnterX = 1425;
	mPosPressEnterY = 992;

	// �X�R�A�摜(���l)�̃��[�h
	mHandle0   = LoadGraph("data/img/0pt.png");
	mHandle100 = LoadGraph("data/img/100pt.png");
	mHandle200 = LoadGraph("data/img/200pt.png");
	mHandle300 = LoadGraph("data/img/300pt.png");
	mHandle400 = LoadGraph("data/img/400pt.png");
	mHandle500 = LoadGraph("data/img/500pt.png");
	mHandle600 = LoadGraph("data/img/600pt.png");
	// �X�R�A�摜(���l)�̏c���T�C�Y�擾(600�_�̃T�C�Y�����)
	// (�摜�T�C�Y���ꂵ�Ȃ���...)
	GetGraphSize(mHandle600, &mSizeScoreW, &mSizeScoreH);

	mHandleResultFailed = LoadGraph("data/img/Failed.png");
	mHandleResultDeficient = LoadGraph("data/img/Deficient.png");
	mHandleResultGood = LoadGraph("data/img/Good!.png");
	mHandleResultVGood = LoadGraph("data/img/VeryGood!.png");
	mHandleResultExcellent = LoadGraph("data/img/Excellent!!.png");

	//----------------------------------------------------------------+
	// �e�]�����ڃe�N�X�`���̕\���ʒu(�I�t�Z�b�g:�X�R�A�E�B���h�E)
	//----------------------------------------------------------------+
	// �n�C�X�R�A���W�̃Z�b�g(���S)
	int highScoreAdjustY = -220.0f;
	mHighScorePosX = mPosScoreWindowX;
	mHighScorePosY = mPosScoreWindowY + highScoreAdjustY;
	// ����̃X�R�A���W�̃Z�b�g(���S)
	int thisTimeScoreAdjustY = 110.0f;
	mThisTimeScorePosX = mPosScoreWindowX;
	mThisTimeScorePosY = mPosScoreWindowY + thisTimeScoreAdjustY;
	// �]���e�N�X�`���̍��W�Z�b�g((0, 0) = ����)
	int resultAdjustY = 340.0f;
	mResultPosX = mPosScoreWindowX;
	mResultPosY = mPosScoreWindowY + resultAdjustY;
}

/// <summary>
/// �㏈��
/// </summary>
ResultUI::~ResultUI()
{
	DeleteFontToHandle(mFontHandle);
	DeleteFontToHandle(mFontHandle2);
	DeleteFontToHandle(mFontHandle2ex);
	DeleteFontToHandle(mFontHandle3);
	DeleteFontToHandle(mFontHandle3ex);
	DeleteFontToHandle(mFontHandle4);
	DeleteFontToHandle(mFontHandle4ex);
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void ResultUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	
}

void ResultUI::Update(float _deltaTime, int& _hiScore)
{
	mDeltaTime = _deltaTime;
	if (mScore > _hiScore)
	{
		_hiScore = mScore;
	}
	mHiScore = _hiScore;

	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPosPressEnterX += 15;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPosPressEnterX += -15;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mPosPressEnterY += -15;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPosPressEnterY += 15;
	}*/

	// �A���t�@�l�X�V
	AlphaCount(_deltaTime);
	AlphaCount2(_deltaTime);
}

/// <summary>
/// ������
/// </summary>
void ResultUI::Load()
{
}

/// <summary>
/// �`��
/// </summary>
void ResultUI::Draw()
{

	// �X�R�A�E�B���h�E�̕`��
	DrawExtendGraph(mPosScoreWindowX - ((mSizeScoreWindowW * mScaleScoreWindow) / 2),
		            mPosScoreWindowY - ((mSizeScoreWindowH * mScaleScoreWindow) / 2),
		            mPosScoreWindowX + ((mSizeScoreWindowW * mScaleScoreWindow) / 2),
		            mPosScoreWindowY + ((mSizeScoreWindowH * mScaleScoreWindow) / 2),
		            mHandleScoreWindow, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal2);

	DrawExtendGraph(mPosPressEnterX, mPosPressEnterY,
		mPosPressEnterX + (mSizePressEnterW * mScalePressEnter),
		mPosPressEnterY + (mSizePressEnterH * mScalePressEnter),
		mHandlePressEnter, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 100, 1920 - 50, 1080 - 100, GetColor(255, 255, 255), TRUE, 1.0);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	//DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 100, 1920 - 375, 140, GetColor(0, 0, 0), TRUE, 2.0);
	//DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 450, 1920 - 500, 490, GetColor(0, 0, 0), TRUE, 2.0);
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	//
	//DrawBoxAA(1920 / 2 + 1920 / 2 / 6+50, 100, 1920 - 50, 1080 - 100, GetColor(255, 255, 255), FALSE, 2.0);
	//DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 50, 100, "���Ȃ��̃n�C�X�R�A", GetColor(0, 255, 0), mFontHandle);
	//DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 200, GetColor(0, 0, 0), mFontHandle4, "%dPt", mHiScore);
	//DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 200, GetColor(255, 255, 255), mFontHandle4ex, "%dPt", mHiScore);
	//DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 200, GetColor(255, 255, 255), mFontHandle4, "%dPt", mHiScore);
	//DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 50, 450, "����̃X�R�A", GetColor(0, 255, 0), mFontHandle);
	//DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200+10, 550, GetColor(0, 0, 0), mFontHandle4, "%3dPt", mScore);
	//DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 550, GetColor(255, 255, 255), mFontHandle4, "%3dPt", mScore);
	
	// �n�C�X�R�A(���l)
	if (mHiScore == 0)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle0, TRUE);
	}
	else if (mHiScore == 100)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle100, TRUE);
	}
	else if (mHiScore == 200)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle200, TRUE);
	}
	else if (mHiScore == 300)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle300, TRUE);
	}
	else if (mHiScore == 400)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle400, TRUE);
	}
	else if (mHiScore == 500)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle500, TRUE);
	}
	else if (mHiScore == 600)
	{
		DrawRotaGraph(mHighScorePosX, mHighScorePosY, 1.0, 0.0, mHandle600, TRUE);
	}

	//---------------------------------------------------+
	// �X�R�A(���l)
	// �킩��₷���悤�ɓ_��
	//---------------------------------------------------+
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);
	if (mScore == 0)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle0, TRUE);
	}
	else if (mScore == 100)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle100, TRUE);
	}
	else if (mScore == 200)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle200, TRUE);
	}
	else if (mScore == 300)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle300, TRUE);
	}
	else if (mScore == 400)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle400, TRUE);
	}
	else if (mScore == 500)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle500, TRUE);
	}
	else if (mScore == 600)
	{
		DrawRotaGraph(mThisTimeScorePosX, mThisTimeScorePosY, 1.0, 0.0, mHandle600, TRUE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	// �]��
	if (mScore == 0)
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 180+5, 800+5, "Failed", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 180, 800, "Failed", GetColor(0, 255, 0), mFontHandle2);*/
		DrawRotaGraph(mResultPosX, mResultPosY, 1.0, 0.0, mHandleResultFailed, TRUE);
	}
	else if (mScore < 200)
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 100+5, 800+5, "Deficient", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 100, 800, "Deficient", GetColor(0, 255, 0), mFontHandle2);*/
		DrawRotaGraph(mResultPosX, mResultPosY, 1.0, 0.0, mHandleResultDeficient, TRUE);
	}
	else if (mScore < 400)
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 220+5, 800+5, "Good!", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 220, 800, "Good!", GetColor(0, 255, 0), mFontHandle2);*/
		DrawRotaGraph(mResultPosX, mResultPosY, 1.0, 0.0, mHandleResultGood, TRUE);
	}
	else if (mScore < 600)
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 90+5, 800+5, "VeryGood!", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 90, 800, "VeryGood!", GetColor(0, 255, 0), mFontHandle2);*/
		DrawRotaGraph(mResultPosX, mResultPosY, 1.0, 0.0, mHandleResultVGood, TRUE);
	}
	else
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 0, 0), mFontHandle3);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 255, 0), mFontHandle3ex);*/
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70+5, 800+5, "Excellent!!", GetColor(0, 0, 0), mFontHandle3);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 255, 0), mFontHandle3);*/
		DrawRotaGraph(mResultPosX, mResultPosY, 1.0, 0.0, mHandleResultExcellent, TRUE);
	}
	/*clsDx();
	printfDx("mStartButtonBeginX:%d\n", mPosPressEnterX);
	printfDx("mStartButtonBeginY:%d\n", mPosPressEnterY);*/
}

/// <summary>
/// �X�R�A�����炤�֐�
/// </summary>
/// <param name="_score">�X�R�A</param>
void ResultUI::LoadScore(int _score)
{
	mScore = _score;
	
}

void ResultUI::AlphaCount(float _deltaTime)
{
	const float addVal = 400.0f * _deltaTime;
	const double maxAlpha = 255.0 + 35.0;
	const double minAlpha = 0.0 + 55.0;

	if (mAlphaPal > maxAlpha)
	{
		mAlphaCount = -1;
	}

	if (mAlphaPal < minAlpha)
	{
		mAlphaCount = 1;
	}

	mAlphaPal += addVal * mAlphaCount;
}

void ResultUI::AlphaCount2(float _deltaTime)
{
	const float addVal = 150.0f * _deltaTime;
	const double maxAlpha = 255.0 + 35.0;
	const double minAlpha = 0.0 + 85.0f;

	if (mAlphaPal2 > maxAlpha)
	{
		mAlphaCount2 = -1;
	}

	if (mAlphaPal2 < minAlpha)
	{
		mAlphaCount2 = 1;
	}

	mAlphaPal2 += addVal * mAlphaCount2;

}
