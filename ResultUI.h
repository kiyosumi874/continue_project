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

	void AlphaCount(float _deltaTime);
	void AlphaCount2(float _deltaTime);


private:

	float mDeltaTime;    // デルタタイム
	int   mHandle;       // ハンドル格納変数
	int   mScore;        // スコア
	int   mHiScore;        // スコア

	// ウィンドウサイズ(UI配置の基準)
	int mScreenSizeW;
	int mScreenSizeH;

	// スコアウィンドウ関連
	int mHandleScoreWindow;
	int mSizeScoreWindowW;
	int mSizeScoreWindowH;
	int mPosScoreWindowX;
	int mPosScoreWindowY;
	double mScaleScoreWindow;

	// "Enterキーを押してください"UI用変数
	int   mHandlePressEnter;
	int mPosPressEnterX;
	int mPosPressEnterY;
	int mSizePressEnterW;
	int mSizePressEnterH;
	double mScalePressEnter;


	// アルファ制御用
	int mAlphaPal;
	int mAlphaCount;
	int mAlphaPal2;
	int mAlphaCount2;

	int mFontHandle;
	int mFontHandle2;
	int mFontHandle2ex;
	int mFontHandle3;
	int mFontHandle3ex;
	int mFontHandle4;
	int mFontHandle4ex;
	
	int mHighScorePosX;
	int mHighScorePosY;
	int mThisTimeScorePosX;
	int mThisTimeScorePosY;
	int mSizeScoreW;
	int mSizeScoreH;
	int mHandle0;
	int mHandle100;
	int mHandle200;
	int mHandle300;
	int mHandle400;
	int mHandle500;
	int mHandle600;

	int mResultPosX;
	int mResultPosY;
	int mHandleResultFailed;
	int mHandleResultDeficient;
	int mHandleResultGood;
	int mHandleResultVGood;
	int mHandleResultExcellent;
};