#include "DxLib.h"
#include "TitleUI.h"

#define RED   GetColor(255, 0, 0)
#define GREEN GetColor(0, 255, 0)
#define BLUE  GetColor(0, 0, 255)
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
	, mStartButtonFontSize(200)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
{
}

/// <summary>
/// 後処理
/// </summary>
TitleUI::~TitleUI()
{

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
	
	if (!mStartButtonFlag)
	{
		DrawBox(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, GREEN, FALSE);
		SetFontSize(mStartButtonFontSize);
		DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", RED);
	}
	else
	{
		DrawBox(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, RED, FALSE);
		SetFontSize(mStartButtonFontSize);
		DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", GREEN);
	}
	
}
 