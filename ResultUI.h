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
	void Update(float _deltaTime, int& _hiScore);
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

	void LoadScore(int _score);

private:
	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
	int   mScore;        // スコア
	int   mHiScore;        // スコア
	int mFontHandle;
	int mFontHandle2;
	int mFontHandle2ex;
	int mFontHandle3;
	int mFontHandle3ex;
	int mFontHandle4;
	int mFontHandle4ex;
	
	int mHandle0;
	int mHandle100;
	int mHandle200;
	int mHandle300;
	int mHandle400;
	int mHandle500;
	int mHandle600;

	int mHandleA;
	int mHandleB;
	int mHandleC;
	int mHandleD;
	int mHandleE;
};