#include "DxLib.h"
#include "PlayUI.h"

/// <summary>
/// 初期化
/// </summary>
PlayUI::PlayUI()
	: mHandle(0)
	, mDeltaTime(0.000001f)
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
	printfDx("今PlayUI");
}
