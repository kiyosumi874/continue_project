#include "DxLib.h"
#include "PlayUI.h"
#include "SE.h"
#include <math.h>

#define GRAVITY 9.80665f

/// <summary>
/// 初期化
/// </summary>
PlayUI::PlayUI()
	: mScore(0)
	, mDeltaTime(0.000001f)
	, mInputReturnFlag(false)
	, mGameTransitionCount(0)
	, mGameCount(0)
	, mGameCountFlag1(true)
	, mGameCountFlag2(true)
	, mGameCountFlag3(true)
	, mClickNormalFlag(false)
	, mClickCriticalFlag(false)
	, mMetoronomeFlag(false)
	// CircleGame
	, mCircleSpeed(0)
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
	, mPlayCircleGameFlag(true)
	, mDrawCircleGameFlag(true)
	// GaugeGame
	, mGaugeSpeed(0)
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
	, mPlayGaugeGameFlag(false)
	, mDrawGaugeGameFlag(false)
	// PendulumGame
	, mPendulumSpeed(0)
	, mPendulumOutX(960)
	, mPendulumOutY(700)
	, mPendulumOutRadius(30)
	, mPendulumOutColor(GetColor(0, 0, 255))
	, mPendulumOutFillFlag(false)
	, mPendulumOutLineThickness(2)
	, mPendulumInX(960+300)
	, mPendulumInFx(960)
	, mPendulumInY(700-300)
	, mPendulumInFy(400)
	, mPendulumInAngle(0.0f)
	, mPendulumInAngleSpeed(0.0f)
	, mPendulumLength(300)
	, mPendulumInRadius(30)
	, mPendulumInColor(GetColor(255, 0, 0))
	, mPendulumInFillFlag(true)
	, mPlayPendulumGameFlag(false)
	, mDrawPendulumGameFlag(false)
	, mMetoronome(nullptr)
	, mClickNormal(nullptr)
	, mClickClitical(nullptr)
	, mFontHandle(-1)
{
}

/// <summary>
/// 後処理
/// </summary>
PlayUI::~PlayUI()
{
	delete mMetoronome;
	delete mClickNormal;
	delete mClickClitical;
	DeleteFontToHandle(mFontHandle);
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
	if (mPlayCircleGameFlag)
	{
		mCircleOutRadius += -200.0f * mDeltaTime;
		if (mCircleOutRadius <= 0)
		{
			mCircleOutRadius = 200.0f;
		}

		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if (mCircleOutRadius <= 40.0f)
			{
				mScore += 200;
				mCircleOutRadius = 30.0f;
				mCircleInColor = GetColor(0, 255, 0);
				mClickCriticalFlag = true;
			}
			else if (mCircleOutRadius <= 120.0f)
			{
				mScore += 100;
				mClickNormalFlag = true;
			}
			else
			{
				mScore += 0;
				mClickNormalFlag = true;
			}
			mInputReturnFlag = false;
			mPlayCircleGameFlag = false;
		}
	}

	//-----------//
	//-GaugeGame-//
	//-----------//
	if (mPlayGaugeGameFlag)
	{
		mGaugeInBeginY += -400.0f * mDeltaTime;
		if (mGaugeInBeginY <= 360.0f)
		{
			mGaugeInBeginY = 720.0f;
		}

		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if ((mGaugeInBeginY <= 370.0f) || (710.0f <= mGaugeInBeginY && mGaugeInBeginY <= 720.0f))
			{
				mScore += 200;
				mGaugeInBeginY = 360.0f;
				mGaugeInColor = GetColor(0, 255, 0);
				mClickCriticalFlag = true;
			}
			else if (mGaugeInBeginY <= 560.0f)
			{
				mScore += 100;
				mClickNormalFlag = true;
			}
			else
			{
				mScore += 0;
				mClickNormalFlag = true;
			}
			mInputReturnFlag = false;
			mPlayGaugeGameFlag = false;
		}
	}

	//--------------//
	//-PendulumGame-//
	//--------------//
	if (mPlayPendulumGameFlag)
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
		mPendulumInAngle += mPendulumInAngleSpeed * 3.0f * mDeltaTime;

		// 新しい重りの位置
		rad = mPendulumInAngle * DX_PI_F / 180.0f;
		px = mPendulumInFx + cos(rad) * mPendulumLength;
		py = mPendulumInFy + sin(rad) * mPendulumLength;

		// 重りの座標
		mPendulumInX = px;
		mPendulumInY = py;

		
		
		if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
		{
			if (940.0f <= mPendulumInX && mPendulumInX <= 980.0f)
			{
				mPendulumInX = 960.0f;
				mPendulumInY = 700.0f;
				mScore += 200;
				mPendulumInColor = GetColor(0, 255, 0);		
				mClickCriticalFlag = true;
				
			}
			else if (820.0f <= mPendulumInX && mPendulumInX < 940.0f || 980.0f < mPendulumInX && mPendulumInX <= 1100.0f)
			{
				mScore += 100;
				mClickNormalFlag = true;
				
			}
			else
			{
				mScore += 0;
				mClickNormalFlag = true;
			}
			
			mInputReturnFlag = false;
			mPlayPendulumGameFlag = false;
		}

	}

	if (!mPlayCircleGameFlag && !mPlayGaugeGameFlag && !mPlayPendulumGameFlag)
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
		mDrawCircleGameFlag = false;
		mDrawGaugeGameFlag = true;
		mPlayGaugeGameFlag = true;
		mGameCountFlag1 = false;
		
	}
	else if (mGameCount == 2 && mGameCountFlag2)
	{
		mDrawGaugeGameFlag = false;
		mDrawPendulumGameFlag = true;
		mPlayPendulumGameFlag = true;
		mGameCountFlag2 = false;
	}
	else if (mGameCount == 3 && mGameCountFlag3)
	{
		mDrawPendulumGameFlag = false;
		mGameCountFlag3 = false;
		
	}

}

/// <summary>
/// 初期化
/// </summary>
void PlayUI::Load()
{
	mMetoronome = new SE;
	mClickNormal = new SE;
	mClickClitical = new SE;
	mMetoronome->LoadSound("data/sound/metronome_wood.wav");
	mClickNormal->LoadSound("data/sound/click_normal.mp3");
	mClickClitical->LoadSound("data/sound/click_critical.mp3");
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 170 * 2 / 3, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
}

/// <summary>
/// 描画
/// </summary>
void PlayUI::Draw()
{
	// デバッグ用
	DrawFormatStringToHandle(0, 0, GetColor(0, 255, 0), mFontHandle,"スコア：%d", mScore);
	// 1920 * 1080 * 2 / 3
	////------------//
	////-CircleGame-//
	////------------//
	//if (mDrawCircleGameFlag)
	//{
	//	// 内側の円
	//	DrawCircleAA(mCircleInX*2/3, mCircleInY * 2 / 3, mCircleInRadius * 2 / 3, 64, mCircleInColor, mCircleInFillFlag);
	//	// 外側の円
	//	DrawCircleAA(mCircleOutX * 2 / 3, mCircleOutY * 2 / 3, mCircleOutRadius * 2 / 3, 64, mCircleOutColor, mCircleOutFillFlag, mCircleOutLineThickness);
	//}

	////-----------//
	////-GaugeGame-//
	////-----------//
	//if (mDrawGaugeGameFlag)
	//{
	//	// 内側の四角
	//	DrawBox(mGaugeInBeginX * 2 / 3, mGaugeInBeginY * 2 / 3, mGaugeInEndX * 2 / 3, mGaugeInEndY * 2 / 3, mGaugeInColor, mGaugeInFillFlag);
	//	// 外側の四角
	//	DrawBox(mGaugeOutBeginX * 2 / 3, mGaugeOutBeginY * 2 / 3, mGaugeOutEndX * 2 / 3, mGaugeOutEndY * 2 / 3, mGaugeOutColor, mGaugeOutFillFlag);
	//	DrawBox(mGaugeOutBeginX * 2 / 3 - 1, mGaugeOutBeginY * 2 / 3 - 1, mGaugeOutEndX * 2 / 3 + 1, mGaugeOutEndY * 2 / 3 + 1, mGaugeOutColor, mGaugeOutFillFlag);
	//	DrawBox(mGaugeOutBeginX * 2 / 3 -2, mGaugeOutBeginY * 2 / 3 -2, mGaugeOutEndX * 2 / 3 +2, mGaugeOutEndY * 2 / 3 +2, mGaugeOutColor, mGaugeOutFillFlag);
	//}

	////--------------//
	////-PendulumGame-//
	////--------------//
	//if (mDrawPendulumGameFlag)
	//{
	//	// 内側の円
	//	DrawCircleAA(mPendulumInX * 2 / 3, mPendulumInY * 2 / 3, mPendulumInRadius * 2 / 3, 64, mPendulumInColor, mPendulumInFillFlag);
	//	// 外側の円
	//	DrawCircleAA(mPendulumOutX * 2 / 3, mPendulumOutY * 2 / 3, mPendulumOutRadius * 2 / 3, 64, mPendulumOutColor, mPendulumOutFillFlag, mPendulumOutLineThickness);
	//}

	//------------//
	//-CircleGame-//
	//------------//
	if (mDrawCircleGameFlag)
	{
		// 内側の円
		DrawCircleAA(mCircleInX, mCircleInY, mCircleInRadius,64, mCircleInColor, mCircleInFillFlag);
		// 外側の円
		DrawCircleAA(mCircleOutX, mCircleOutY, mCircleOutRadius,64, mCircleOutColor, mCircleOutFillFlag, mCircleOutLineThickness);
	}

	//-----------//
	//-GaugeGame-//
	//-----------//
	if (mDrawGaugeGameFlag)
	{
		// 内側の四角
		DrawBoxAA(mGaugeInBeginX, mGaugeInBeginY, mGaugeInEndX, mGaugeInEndY, mGaugeInColor, mGaugeInFillFlag);
		// 外側の四角
		DrawBoxAA(mGaugeOutBeginX, mGaugeOutBeginY, mGaugeOutEndX, mGaugeOutEndY, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBoxAA(mGaugeOutBeginX - 1, mGaugeOutBeginY - 1, mGaugeOutEndX + 1, mGaugeOutEndY + 1, mGaugeOutColor, mGaugeOutFillFlag);
		DrawBoxAA(mGaugeOutBeginX - 2, mGaugeOutBeginY - 2, mGaugeOutEndX + 2, mGaugeOutEndY + 2, mGaugeOutColor, mGaugeOutFillFlag);
	}

	//--------------//
	//-PendulumGame-//
	//--------------//
	if (mDrawPendulumGameFlag)
	{
		// 内側の円
		DrawCircleAA(mPendulumInX, mPendulumInY, mPendulumInRadius,64, mPendulumInColor, mPendulumInFillFlag);
		// 外側の円
		DrawCircleAA(mPendulumOutX, mPendulumOutY, mPendulumOutRadius,64, mPendulumOutColor, mPendulumOutFillFlag, mPendulumOutLineThickness);
	}


	
}

void PlayUI::Sound()
{
	
	if (mClickCriticalFlag)
	{
		mClickClitical->Play();
		mClickCriticalFlag = false;
	}
	if (mClickNormalFlag)
	{
		mClickNormal->Play();
		mClickNormalFlag = false;
	}
	if (mPlayPendulumGameFlag)
	{
		if ((940 <= mPendulumInX && mPendulumInX <= 980) && !mMetoronomeFlag)
		{
			mMetoronome->Play();
			mMetoronomeFlag = true;
		}
		if (!(940 <= mPendulumInX && mPendulumInX <= 980))
		{
			mMetoronomeFlag = false;
		}
	}
}
