//----------------------------------------------------------------------------------//
// @file         TitleUI.h
// @brief        TitleUIクラス
// @note         継承元:UIBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class TitleUI : public UIBase
{
public:
	 TitleUI();    // コンストラクタ
	~TitleUI();    // デストラクタ

	void Update(float _deltaTime)override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画

	// スタートボタンのフラグのゲッター
	const bool& GetStartButtonFlag() const { return mStartButtonFlag; }
private:
	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
	int mSizeX;
	int mSizeY;
	int   mHandle2;       // ハンドル格納変数
	int mSize2X;
	int mSize2Y;
	int   mHandle3;       // ハンドル格納変数
	double mAlphaPal;
	double mAlphaCount;

	// スタートボタンの位置を決める変数
	int mStartButtonBeginX;    // 左上のX
	int mStartButtonBeginY;    // 左上のY
	int mStartButtonEndX;      // 右下のX
	int mStartButtonEndY;	   // 右下のY
	// スタートボタンのフォントサイズ
	int mStartButtonFontSize;
	// スタートボタンのフラグ
	bool mStartButtonFlag;

	bool mInputReturnFlag;    // Enterキーの連続入力防止

	int mFontHandle;

	float mTmpTime;
	bool mTmpTimeFlag;

};