#include "DxLib.h"
#include "PlayUI.h"
#include <math.h>

#define GRAVITY 9.80665f

/// <summary>
/// 初期化
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
/// 後処理
/// </summary>
PlayUI::~PlayUI()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void PlayUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;

	// Enterキーの連続入力防止
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

		// 現在の重りの位置
		auto rad = mPendulumInAngle * DX_PI_F / 180.0f;
		auto px = mPendulumInFx + cos(rad) * mPendulumLength;
		auto py = mPendulumInFy + sin(rad) * mPendulumLength;

		// 重力移動量を反映した重りの位置
		auto vx = px - mPendulumInFx;
		auto vy = py - mPendulumInFy;
		auto t = -(vy * GRAVITY) / (vx * vx + vy * vy);
		auto gx = px + t * vx;
		auto gy = py + GRAVITY + t * vy;

		// ２つの重りの位置の角度差
		auto r = atan2(gy - mPendulumInFy, gx - mPendulumInFx) * 180.0 / DX_PI_F;

		// 角度差を角速度に加算
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

		// 角度に角速度を加算
		mPendulumInAngle += mPendulumInAngleSpeed * 3 * mDeltaTime;

		// 新しい重りの位置
		rad = mPendulumInAngle * DX_PI_F / 180.0f;
		px = mPendulumInFx + cos(rad) * mPendulumLength;
		py = mPendulumInFy + sin(rad) * mPendulumLength;

		// 重りの座標
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
/// 初期化
/// </summary>
void PlayUI::Load()
{
}

/// <summary>
/// 描画
/// </summary>
void PlayUI::Draw()
{
	// デバッグ用
	SetFontSize(50);
	DrawFormatString(0, 0, GetColor(0, 255, 0), "スコア：%d", mScore);

	//------------//
	//-CircleGame-//
	//------------//
	if (mDrawCircleGame)
	{
		// 内側の円
		DrawCircle(mCircleInX, mCircleInY, mCircleInRadius, mCircleInColor, mCircleInFillFlag);
		// 外側の円
		DrawCircle(mCircleOutX, mCircleOutY, mCircleOutRadius, mCircleOutColor, mCircleOutFillFlag, mCircleOutLineThickness);
	}

	//-----------//
	//-GaugeGame-//
	//-----------//
	if (mDrawGaugeGame)
	{
		// 内側の四角
		DrawBox(mGaugeInBeginX, mGaugeInBeginY, mGaugeInEndX, mGaugeInEndY, mGaugeInColor, mGaugeInFillFlag);
		// 外側の四角
		DrawBox(mGaugeOutBeginX, mGaugeOutBeginY, mGaugeOutEndX, mGaugeOutEndY, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBox(mGaugeOutBeginX - 1, mGaugeOutBeginY - 1, mGaugeOutEndX + 1, mGaugeOutEndY + 1, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBox(mGaugeOutBeginX-2, mGaugeOutBeginY-2, mGaugeOutEndX+2, mGaugeOutEndY+2, mGaugeOutColor, mGaugeOutFillFlag);
	}

	//--------------//
	//-PendulumGame-//
	//--------------//
	if (mDrawPendulumGame)
	{
		// 内側の円
		DrawCircle(mPendulumInX, mPendulumInY, mPendulumInRadius, mPendulumInColor, mPendulumInFillFlag);
		// 外側の円
		DrawCircle(mPendulumOutX, mPendulumOutY, mPendulumOutRadius, mPendulumOutColor, mPendulumOutFillFlag, mPendulumOutLineThickness);
	}


	
}
