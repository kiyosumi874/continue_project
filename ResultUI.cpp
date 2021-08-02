#include "DxLib.h"
#include "ResultUI.h"


/// <summary>
/// 初期化
/// </summary>
ResultUI::ResultUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
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
	// デバッグ用
	printfDx("今ResultUI");
}
