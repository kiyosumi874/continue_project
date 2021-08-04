#include "DxLib.h"
#include "PlayUI.h"

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

	if (!mPlayCircleGame && !mPlayGaugeGame)
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
		mGameCountFlag2 = false;
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
	
}
