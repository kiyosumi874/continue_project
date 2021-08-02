//----------------------------------------------------------------------------------//
// @file         PlayUI.h
// @brief        PlayUIクラス
// @note         継承元:UIBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class PlayUI : public UIBase
{
public:
	PlayUI();    // コンストラクタ
	~PlayUI();    // デストラクタ

	void Update(float _deltaTime)override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

private:
	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
};