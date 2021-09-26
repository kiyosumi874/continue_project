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
	, mHandle2(0)
	, mHandle3(0)
	, mDeltaTime(0.000001f)
	, mStartButtonBeginX(480)
	, mStartButtonBeginY(675+150)
	, mStartButtonEndX(1440)
	, mStartButtonEndY(945+150)
	, mStartButtonFontSize(150 /** 2 / 3*/)
	, mStartButtonFlag(false)
	, mInputReturnFlag(false)
	, mTmpTime(0)
	, mTmpTimeFlag(false)
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
}

/// <summary>
/// 初期化
/// </summary>
void TitleUI::Load()
{
	mStartButtonFlag = false;
	mDeltaTime = 0.000001f;
	mStartButtonBeginX = 480;
	mStartButtonBeginY = 675+100;
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
	//if (!mStartButtonFlag)
	//{
	//	DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, GREEN, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", RED);
	//	DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	//}
	//else
	//{
	//	DrawBoxAA(mStartButtonBeginX, mStartButtonBeginY, mStartButtonEndX, mStartButtonEndY, RED, FALSE);
	//	//SetFontSize(mStartButtonFontSize);
	//	//DrawString(mStartButtonBeginX + 45, mStartButtonBeginY + 30, "Enterキー", GREEN);
	//	DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "Enterキー", WHITE, mFontHandle, BLACK);
	//}

	//DrawGraph(1920/3, 1080/3, mHandle3, TRUE);
	DrawExtendGraph(1920/4+200,1080/4+150, 1920 / 4+533+200, 1080 / 4+351+150, mHandle3, TRUE);
	if (!mStartButtonFlag)
	{
		if (!mTmpTimeFlag)
		{
			DrawGraph(mStartButtonBeginX + 45 - 96, mStartButtonBeginY + 60, mHandle, TRUE);
		}
		else
		{
			DrawGraph(mStartButtonBeginX + 45 - 96, mStartButtonBeginY + 60, mHandle2, TRUE);
		}
		//DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "でスタート！", WHITE, mFontHandle, BLACK);

	}
	else
	{
		DrawGraph(mStartButtonBeginX + 45 - 96, mStartButtonBeginY+60, mHandle2, TRUE);
		/*DrawStringToHandle(mStartButtonBeginX + 45, mStartButtonBeginY + 35, "でスタート！", WHITE, mFontHandle, BLACK);*/
	}
}
 