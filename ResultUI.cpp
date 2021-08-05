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
}

/// <summary>
/// 後処理
/// </summary>
ResultUI::~ResultUI()
{
}

/// <summary>
/// 更新
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void ResultUI::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
	
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
	DrawFormatString(700, 540, GetColor(0, 255, 0), "スコア：%d", mScore);
}

/// <summary>
/// スコアをもらう関数
/// </summary>
/// <param name="_score">スコア</param>
void ResultUI::LoadScore(int _score)
{
	mScore = _score;
}
