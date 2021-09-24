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
	: mHandle(0)
	, mHandle2(0)
	, mHandle3(0)
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
	, mSizeX(0)
	, mSizeY(0)
	, mSize2X(0)
	, mSize2Y(0)
	, mAlphaPal(0)
	, mAlphaCount(0)
{
	////                                     作成するフォント名,     フォントのサイズ,  フォントの太さ,                  フォントのタイプ, 文字セット, 縁の太さ, イタリック体にするかどうか
	//mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", mStartButtonFontSize,              -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4,         -1,        5,                       TRUE);
	mHandle = LoadGraph("data/img/TitleUI3.png");
	mHandle2 = LoadGraph("data/img/TitleUI4.png");
	mHandle3 = LoadGraph("data/img/VirtualDive.png");
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
	mAlphaPal = sin(mAlphaCount)+4;

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mStartButtonBeginX += 15;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mStartButtonBeginX += -15;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mStartButtonBeginY += -15;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mStartButtonBeginY += 15;
	}
	mAlphaCount += 0.07;
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
	GetGraphSize(mHandle, &mSizeX, &mSizeY);
	GetGraphSize(mHandle2, &mSize2X, &mSize2Y);
}

/// <summary>
/// 描画
/// </summary>
void TitleUI::Draw()
{
	//----------------//
	// スタートボタン //
    //----------------//
	//DrawExtendGraph(1920/4+200,1080/4+150, 1920 / 4+533+200, 1080 / 4+351+150, mHandle3, TRUE);
	DrawExtendGraph(120, 120, 120+533, 120+351, mHandle3, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 51*mAlphaPal);
	DrawExtendGraph(mStartButtonBeginX, mStartButtonBeginY, mStartButtonBeginX + mSizeX * 2 / 3, mStartButtonBeginY + mSizeY * 2 / 3, mHandle, TRUE);
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
	clsDx();
	printfDx("mStartButtonBeginX:%d\n", mStartButtonBeginX);
	printfDx("mStartButtonBeginY:%d\n", mStartButtonBeginY);

}
 