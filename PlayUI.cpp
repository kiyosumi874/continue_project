#include "DxLib.h"
#include "PlayUI.h"
#include <math.h>

#define GRAVITY 9.80665f

/// <summary>
/// ������
/// </summary>
PlayUI::PlayUI()
	: mHandle(0)
	, mScore(0)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mGameTransitionCount(0)
	, mGameCount(0)
	, mGameCountFlag1(true)
	, mGameCountFlag2(true)
	, mGameCountFlag3(true)
	// CircleGame
	, mCircleOutX(960)
	, mCircleOutY(540)
	, mCircleOutRadius(200)
	, mCircleOutColor(GetColor(0, 0, 255))
	, mCircleOutFillFlag(false)
	, mCircleOutLineThickness(2)
	, mCircleInX(960)
	, mCircleInY(540)
	, mCircleInRadius(30)
	, mCircleInColor(GetColor(255, 0, 0))
	, mCircleInFillFlag(true)
	, mPlayCircleGame(true)
	, mDrawCircleGame(true)
	// GaugeGame
	, mGaugeOutBeginX(920)
	, mGaugeOutBeginY(360)
	, mGaugeOutEndX(1000)
	, mGaugeOutEndY(720)
	, mGaugeOutColor(GetColor(0, 0, 255))
	, mGaugeOutFillFlag(false)
	, mGaugeInBeginX(920)
	, mGaugeInBeginY(720)
	, mGaugeInEndX(1000)
	, mGaugeInEndY(720)
	, mGaugeInColor(GetColor(255, 0, 0))
	, mGaugeInFillFlag(true)
	, mPlayGaugeGame(false)
	, mDrawGaugeGame(false)
	// PendulumGame
	, mPendulumOutX(960)
	, mPendulumOutY(700)
	, mPendulumOutRadius(30)
	, mPendulumOutColor(GetColor(0, 0, 255))
	, mPendulumOutFillFlag(false)
	, mPendulumOutLineThickness(2)
	, mPendulumInX(960)
	, mPendulumInFx(960)
	, mPendulumInY(700)
	, mPendulumInFy(400)
	, mPendulumInAngle(0.0f)
	, mPendulumInAngleSpeed(0.0f)
	, mPendulumLength(300)
	, mPendulumInRadius(30)
	, mPendulumInColor(GetColor(255, 0, 0))
	, mPendulumInFillFlag(true)
	, mPlayPendulumGame(false)
	, mDrawPendulumGame(false)
{
}

/// <summary>
/// �㏈��
/// </summary>
PlayUI::~PlayUI()
{
}

/// <summary>
/// �X�V
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void PlayUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enter�L�[�̘A�����͖h�~
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	//------------//
	//-CircleGame-//
	//------------//
	if (mPlayCircleGame)
	{
		mCircleOutRadius += -200 * mDeltaTime;
		if (mCircleOutRadius <= 0)
		{
			mCircleOutRadius = 200;
		}

		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if (mCircleOutRadius <= 40)
			{
				mScore += 200;
				mCircleOutRadius = 30;
			}
			else if (mCircleOutRadius <= 120)
			{
				mScore += 100;
			}
			else
			{
				mScore += 0;
			}
			mInputReturnFlag = false;
			mPlayCircleGame = false;
		}
	}

	//-----------//
	//-GaugeGame-//
	//-----------//
	if (mPlayGaugeGame)
	{
		mGaugeInBeginY += -400 * mDeltaTime;
		if (mGaugeInBeginY <= 360)
		{
			mGaugeInBeginY = 720;
		}

		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if (mGaugeInBeginY <= 400)
			{
				mScore += 200;
				mGaugeInBeginY = 360;
			}
			else if (mGaugeInBeginY <= 560)
			{
				mScore += 100;
			}
			else
			{
				mScore += 0;
			}
			mInputReturnFlag = false;
			mPlayGaugeGame = false;
		}
	}

	//--------------//
	//-PendulumGame-//
	//--------------//
	if (mPlayPendulumGame)
	{

		// ���݂̏d��̈ʒu
		auto rad = mPendulumInAngle * DX_PI_F / 180.0f;
		auto px = mPendulumInFx + cos(rad) * mPendulumLength;
		auto py = mPendulumInFy + sin(rad) * mPendulumLength;

		// �d�͈ړ��ʂ𔽉f�����d��̈ʒu
		auto vx = px - mPendulumInFx;
		auto vy = py - mPendulumInFy;
		auto t = -(vy * GRAVITY) / (vx * vx + vy * vy);
		auto gx = px + t * vx;
		auto gy = py + GRAVITY + t * vy;

		// �Q�̏d��̈ʒu�̊p�x��
		auto r = atan2(gy - mPendulumInFy, gx - mPendulumInFx) * 180.0 / DX_PI_F;

		// �p�x�����p���x�ɉ��Z
		auto sub = r - mPendulumInAngle;
		sub -= floor(sub / 360.0) * 360.0;
		if (sub < -180.0)
		{
			sub += 360.0;
		}
		if (sub > 180.0)
		{
			sub -= 360.0;
		}
		mPendulumInAngleSpeed += sub;

		// �p�x�Ɋp���x�����Z
		mPendulumInAngle += mPendulumInAngleSpeed * 3 * mDeltaTime;

		// �V�����d��̈ʒu
		rad = mPendulumInAngle * DX_PI_F / 180.0f;
		px = mPendulumInFx + cos(rad) * mPendulumLength;
		py = mPendulumInFy + sin(rad) * mPendulumLength;

		// �d��̍��W
		mPendulumInX = px;
		mPendulumInY = py;

		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if (950 <= mPendulumInX && mPendulumInX <= 970)
			{
				mPendulumInX = 960;
				mPendulumInY = 700;
				mScore += 200;
			}
			else if (820 <= mPendulumInX && mPendulumInX < 950 || 970 < mPendulumInX && mPendulumInX <= 1100)
			{
				mScore += 100;
			}
			else
			{
				mScore += 0;
			}
			
			mInputReturnFlag = false;
			mPlayPendulumGame = false;
		}
	}

	if (!mPlayCircleGame && !mPlayGaugeGame && !mPlayPendulumGame)
	{
		mGameTransitionCount += 1.0f * mDeltaTime;
	}
	if (mGameTransitionCount >= 0.5f)
	{
		mGameCount++;
		mGameTransitionCount = 0;
	}
	
	if (mGameCount == 1 && mGameCountFlag1)
	{
		mDrawCircleGame = false;
		mDrawGaugeGame = true;
		mPlayGaugeGame = true;
		mGameCountFlag1 = false;
	}
	else if (mGameCount == 2 && mGameCountFlag2)
	{
		mDrawGaugeGame = false;
		mDrawPendulumGame = true;
		mPlayPendulumGame = true;
		mGameCountFlag2 = false;
	}
	else if (mGameCount == 3 && mGameCountFlag3)
	{
		mDrawPendulumGame = false;
		mGameCountFlag3 = false;
	}

}

/// <summary>
/// ������
/// </summary>
void PlayUI::Load()
{
}

/// <summary>
/// �`��
/// </summary>
void PlayUI::Draw()
{
	// �f�o�b�O�p
	SetFontSize(50);
	DrawFormatString(0, 0, GetColor(0, 255, 0), "�X�R�A�F%d", mScore);

	//------------//
	//-CircleGame-//
	//------------//
	if (mDrawCircleGame)
	{
		// �����̉~
		DrawCircle(mCircleInX, mCircleInY, mCircleInRadius, mCircleInColor, mCircleInFillFlag);
		// �O���̉~
		DrawCircle(mCircleOutX, mCircleOutY, mCircleOutRadius, mCircleOutColor, mCircleOutFillFlag, mCircleOutLineThickness);
	}

	//-----------//
	//-GaugeGame-//
	//-----------//
	if (mDrawGaugeGame)
	{
		// �����̎l�p
		DrawBox(mGaugeInBeginX, mGaugeInBeginY, mGaugeInEndX, mGaugeInEndY, mGaugeInColor, mGaugeInFillFlag);
		// �O���̎l�p
		DrawBox(mGaugeOutBeginX, mGaugeOutBeginY, mGaugeOutEndX, mGaugeOutEndY, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBox(mGaugeOutBeginX - 1, mGaugeOutBeginY - 1, mGaugeOutEndX + 1, mGaugeOutEndY + 1, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBox(mGaugeOutBeginX-2, mGaugeOutBeginY-2, mGaugeOutEndX+2, mGaugeOutEndY+2, mGaugeOutColor, mGaugeOutFillFlag);
	}

	//--------------//
	//-PendulumGame-//
	//--------------//
	if (mDrawPendulumGame)
	{
		// �����̉~
		DrawCircle(mPendulumInX, mPendulumInY, mPendulumInRadius, mPendulumInColor, mPendulumInFillFlag);
		// �O���̉~
		DrawCircle(mPendulumOutX, mPendulumOutY, mPendulumOutRadius, mPendulumOutColor, mPendulumOutFillFlag, mPendulumOutLineThickness);
	}


	
}
