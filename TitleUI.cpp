#include "DxLib.h"
#include "TitleUI.h"

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
	, mDeltaTime(0.000001f)
	, mStartButtonBeginX(480)
	, mStartButtonBeginY(675)
	, mStartButtonEndX(1440)
	, mStartButtonEndY(945)
	, mStartButtonFontSize(170 /** 2 / 3*/)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
{
	//                                     作成するフォント名,     フォントのサイズ,  フォントの太さ,                  フォントのタイプ, 文字セット, 縁の太さ, イタリック体にするかどうか
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", mStartButtonFontSize,              -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4,         -1,        5,                       TRUE);
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
}

/// <summary>
/// 初期化
/// </summary>
void TitleUI::Load()
{
	mStartButtonFlag = false;
	mHandle = 0;
	mDeltaTime = 0.000001f;
	mStartButtonBeginX = 480;
	mStartButtonBeginY = 675;
	mStartButtonEndX = 1440;
	mStartButtonEndY = 945;
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
	// 1920*1080 * 2/3
	//if (!mStartButtonFlag)
	//{
	//	DrawBox(mStartButtonBeginX*2/3, mStartButtonBeginY * 2 / 3, mStartButtonEndX * 2 / 3, mStartButtonEndY * 2 / 3, GREEN, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", RED);
	//	DrawStringToHandle(mStartButtonBeginX * 2 / 3 + 45, mStartButtonBeginY * 2 / 3 + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	//}
	//else
	//{
	//	DrawBox(mStartButtonBeginX * 2 / 3, mStartButtonBeginY * 2 / 3, mStartButtonEndX * 2 / 3, mStartButtonEndY * 2 / 3, RED, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", GREEN);
	//	DrawStringToHandle(mStartButtonBeginX * 2 / 3 + 45, mStartButtonBeginY * 2 / 3 + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	//}

	// 1920*1080
	if (!mStartButtonFlag)
	{
		DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, GREEN, FALSE);
		//SetFontSize(mStartButtonFontSize);
		//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", RED);
		DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	}
	else
	{
		DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, RED, FALSE);
		//SetFontSize(mStartButtonFontSize);
		//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", GREEN);
		DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	}
}
 