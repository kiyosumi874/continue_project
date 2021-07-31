#include "SceneBase.h"

// 初期音量
const int VOLUME_PAL = 200;
// フォントサイズ
const int NORMAL_FONT_SIZE = 17;

/// <summary>
/// 初期化
/// </summary>
SceneBase::SceneBase()
	: mVolumePal     (VOLUME_PAL)
	, mNormalFontSize(NORMAL_FONT_SIZE)
{
}
