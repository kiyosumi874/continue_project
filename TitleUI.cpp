#include "DxLib.h"
#include "TitleUI.h"
#include <math.h>

#define RED   GetColor(255, 0, 0)
#define GREEN GetColor(0, 255, 0)
#define BLUE  GetColor(0, 0, 255)
#define BLACK  GetColor(0, 0, 0)
#define WHITE  GetColor(255, 255, 255)
/// <summary>
/// 初期化
/// </summary>
TitleUI::TitleUI()
	: mHandlePressEnter(0)
	, mHandle2(0)
	, mHandleTitleLogo(0)
	, mDeltaTime(0.000001f)
	, mStartButtonBeginX(480-51)
	, mStartButtonBeginY(675+150+60)
	, mStartButtonEndX(1440)
	, mStartButtonEndY(945+150)
	, mStartButtonFontSize(150 /** 2 / 3*/)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
	, mTmpTime(0)
	, mTmpTimeFlag(false)
	, mScalePressEnter(0.7)
	, mSize2X(0)
	, mSize2Y(0)
	, mAlphaPal(0)
	, mAlphaCount(1)
	, mScaleTitleLogo(0.5)
	, mFloatingCounter(0.0f)
{
	////                                     作成するフォント名,     フォントのサイズ,  フォントの太さ,                  フォントのタイプ, 文字セット, 縁の太さ, イタリック体にするかどうか
	//mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", mStartButtonFontSize,              -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4,         -1,        5,                       TRUE);
	mHandlePressEnter = LoadGraph("data/img/TitleUI3.png");
	mHandle2 = LoadGraph("data/img/TitleUI4.png");
	mHandleTitleLogo = LoadGraph("data/img/VirtualDive2.png");
	// 各画像サイズ取得
	GetGraphSize(mHandlePressEnter, &mSizePressEnterW, &mSizePressEnterH);
	GetGraphSize(mHandle2, &mSize2X, &mSize2Y);
	GetGraphSize(mHandleTitleLogo, &mSizeTitleLogoW, &mSizeTitleLogoH);

	// スクリーンサイズ取得
	GetWindowSize(&mScreenSizeW, &mScreenSizeH);

	// 始点座標のセット
	int adjustPosEnterX = -70;
	int adjustPosEnterY = -50;
	mPosPressEnterX = mScreenSizeW - (mSizePressEnterW * mScalePressEnter) + adjustPosEnterX;
	mPosPressEnterY = mScreenSizeH - (mSizePressEnterH * mScalePressEnter) + adjustPosEnterY;
	mPosTitleLogoX = 50;
	mPosTitleLogoY = -50;

}

/// <summary>
/// 後処理
/// </summary>
TitleUI::~TitleUI()
{
	DeleteFontToHandle(mFontHandle);
}

/// <summary>
/// 更新
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void TitleUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	mTmpTime += _deltaTime;
	// Enterキーの連続入力防止
	if (!CheckHitKey(KEY_INPUT_RETURN))
	{
		mInputReturnFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_RETURN) && mInputReturnFlag)
	{
		mInputReturnFlag = false;
		mStartButtonFlag = true;
	}

	if (mTmpTime >= 1.0f)
	{
		if (mTmpTimeFlag)
		{
			mTmpTimeFlag = false;
		}
		else 
		{
			mTmpTimeFlag = true;
		}
		mTmpTime = 0;
	}

	/*if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mPosTitleLogoX += 10;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mPosTitleLogoX += -10;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mPosTitleLogoY += -10;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mPosTitleLogoY += 10;
	}*/

	// アルファのカウント更新処理
	AlphaCount(_deltaTime);

	// タイトルロゴの浮遊演出
	mFloatingCounter += 3.0f * _deltaTime;
	if (mFloatingCounter > 360.0f)
	{
		mFloatingCounter = 0;
	}
	//mPosTitleLogoY = 65 + (15 * sin(mFloatingCounter));

}

/// <summary>
/// 初期化
/// </summary>
void TitleUI::Load()
{
	mStartButtonFlag = false;
	mDeltaTime = 0.000001f;
	mStartButtonBeginX = 710;
	mStartButtonBeginY = 745;
	mStartButtonEndX = 1440;
	mStartButtonEndY = 945+100;
	mStartButtonFontSize = 200;
	mStartButtonFlag = false;
	mInputReturnFlag = false;

}

/// <summary>
/// 描画
/// </summary>
void TitleUI::Draw()
{
	//----------------//
	// スタートボタン //
    //----------------//
	//DrawExtendGraph(1920/4+200,1080/4+150, 1920 / 4+533+200, 1080 / 4+351+150, mHandleTitleLogo, TRUE);

	//------------------+
	// タイトルロゴ描画
	//------------------+
	DrawExtendGraph(mPosTitleLogoX, mPosTitleLogoY, 
		            mPosTitleLogoX + (mSizeTitleLogoW * mScaleTitleLogo), 
		            mPosTitleLogoY + (mSizeTitleLogoH * mScaleTitleLogo), 
		            mHandleTitleLogo, TRUE);

	//--------------------------------------+
	// "Enterでスタート" ※点滅エフェクト
	//--------------------------------------+
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAlphaPal);

	DrawExtendGraph(mPosPressEnterX, mPosPressEnterY, 
		            mPosPressEnterX + (mSizePressEnterW * mScalePressEnter),
		            mPosPressEnterY + (mSizePressEnterH * mScalePressEnter), 
		            mHandlePressEnter, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);

	//if (!mStartButtonFlag)
	//{
	//	if (!mTmpTimeFlag)
	//	{
	//		DrawExtendGraph(mStartButtonBeginX, mStartButtonBeginY,mStartButtonBeginX + mSizeX*2/3, mStartButtonBeginY + mSizeY*2/3, mHandle, TRUE);
	//	}
	//	else
	//	{
	//		DrawExtendGraph(mStartButtonBeginX, mStartButtonBeginY, mStartButtonBeginX + mSize2X*2/3, mStartButtonBeginY + mSize2Y*2/3, mHandle2, TRUE);
	//	}
	//	//DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "でスタート！", WHITE, mFontHandle, BLACK);

	//}
	//else
	//{
	//	DrawExtendGraph(mStartButtonBeginX, mStartButtonBeginY, mStartButtonBeginX + mSize2X*2/3, mStartButtonBeginY + mSize2Y*2/3, mHandle2, TRUE);
	//	/*DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "でスタート！", WHITE, mFontHandle, BLACK);*/
	//}
	/*clsDx();
	printfDx("X:%d\n", mPosTitleLogoX);
	printfDx("Y:%d\n", mPosTitleLogoY);*/

}

void TitleUI::AlphaCount(float _deltaTime)
{
	const float addVal = 150.0f * _deltaTime;
	const double maxAlpha = 255.0 + 35.0;
	const double minAlpha = 0.0 + 85.0f;

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
 