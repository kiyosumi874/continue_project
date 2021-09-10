#include "DxLib.h"
#include "ResultUI.h"
#include "PlayUI.h"


/// <summary>
/// 初期化
/// </summary>
ResultUI::ResultUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
	, mScore(0)
{
	mFontHandle = CreateFontToHandle("data/Fonts/meiryob.tcc", 40, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle2 = CreateFontToHandle("data/Fonts/meiryob.tcc", 130, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, TRUE);
	mFontHandle2ex = CreateFontToHandle("data/Fonts/meiryob.tcc", 130, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle3 = CreateFontToHandle("data/Fonts/meiryob.tcc", 120, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, TRUE);
	mFontHandle3ex = CreateFontToHandle("data/Fonts/meiryob.tcc", 120, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
	mFontHandle4 = CreateFontToHandle("data/Fonts/meiryob.tcc", 200, -1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4, -1, 2, FALSE);
	mFontHandle4ex = CreateFontToHandle("data/Fonts/meiryob.tcc", 200, -1, DX_FONTTYPE_ANTIALIASING_4X4, -1, 5, FALSE);
}

/// <summary>
/// 後処理
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
/// 更新
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
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
}

/// <summary>
/// 初期化
/// </summary>
void ResultUI::Load()
{
}

/// <summary>
/// 描画
/// </summary>
void ResultUI::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 100, 1920 - 50, 1080 - 100, GetColor(255, 255, 255), TRUE, 1.0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 100, 1920 - 375, 140, GetColor(0, 0, 0), TRUE, 2.0);
	DrawBoxAA(1920 / 2 + 1920 / 2 / 6 + 50, 450, 1920 - 500, 490, GetColor(0, 0, 0), TRUE, 2.0);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	
	DrawBoxAA(1920 / 2 + 1920 / 2 / 6+50, 100, 1920 - 50, 1080 - 100, GetColor(255, 255, 255), FALSE, 2.0);
	DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 50, 100, "あなたのハイスコア", GetColor(0, 255, 0), mFontHandle);
	DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 200, GetColor(0, 255, 0), mFontHandle4, "%dPt", mHiScore);
	DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 50, 450, "今回のスコア", GetColor(0, 255, 0), mFontHandle);
	DrawFormatStringToHandle(1920 / 2 + 1920 / 2 / 6 + 200, 550, GetColor(0, 255, 0), mFontHandle4, "%3dPt", mScore);
	if (mScore == 0)
	{
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 180+5, 800+5, "Failed", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 180, 800, "Failed", GetColor(0, 255, 0), mFontHandle2);
	}
	else if (mScore < 200)
	{
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 100+5, 800+5, "Deficient", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 100, 800, "Deficient", GetColor(0, 255, 0), mFontHandle2);
	}
	else if (mScore < 400)
	{
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 220+5, 800+5, "Good!", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 220, 800, "Good!", GetColor(0, 255, 0), mFontHandle2);
	}
	else if (mScore < 600)
	{
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 90+5, 800+5, "VeryGood!", GetColor(0, 0, 0), mFontHandle2);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 90, 800, "VeryGood!", GetColor(0, 255, 0), mFontHandle2);
	}
	else
	{
		/*DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 0, 0), mFontHandle3);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 255, 0), mFontHandle3ex);*/
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70+5, 800+5, "Excellent!!", GetColor(0, 0, 0), mFontHandle3);
		DrawStringToHandle(1920 / 2 + 1920 / 2 / 6 + 70, 800, "Excellent!!", GetColor(0, 255, 0), mFontHandle3);
	}

}

/// <summary>
/// スコアをもらう関数
/// </summary>
/// <param name="_score">スコア</param>
void ResultUI::LoadScore(int _score)
{
	mScore = _score;
	
}
