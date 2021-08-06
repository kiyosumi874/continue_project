//----------------------------------------------------------------------------------//
// @file         ResultUI.h
// @brief        ResultUIクラス
// @note         継承元:UIBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class ResultUI : public UIBase
{
public:
	ResultUI();    // コンストラクタ
	~ResultUI();    // デストラクタ

	void Update(float _deltaTime)override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

	void LoadScore(int _score);

private:
	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
	int   mScore;        // スコア
};