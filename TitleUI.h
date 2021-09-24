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

	void AlphaCount(float _deltaTime);

	// スタートボタンのフラグのゲッター
	const bool& GetStartButtonFlag() const { return mStartButtonFlag; }
private:
	float mDeltaTime;    // デルタタイム

	// "Enterキーを押してください"UI用変数
	int   mHandlePressEnter;
	int mPosPressEnterX;
	int mPosPressEnterY;
	int mSizePressEnterW;
	int mSizePressEnterH;
	double mScalePressEnter;

	int   mHandle2;       // ハンドル格納変数
	int mSize2X;
	int mSize2Y;

	// タイトルロゴUI用変数
	int   mHandleTitleLogo;
	int mPosTitleLogoX;           // 描画の始点となるX座標
	int mPosTitleLogoY;           // 描画の始点となるY座標
	int mSizeTitleLogoW;          // タイトルロゴ画像の横サイズ
	int mSizeTitleLogoH;          // タイトルロゴ画像の縦サイズ
	double mScaleTitleLogo;       // 描画時に使用するスケール
	float mFloatingCounter;         // ロゴ上下に動かす

	double mAlphaPal;
	int mAlphaCount;

	// スクリーンサイズ(ウィンドウの縦と横)
	int mScreenSizeW;
	int mScreenSizeH;

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