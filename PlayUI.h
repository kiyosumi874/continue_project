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
	int   mScore;        // スコア
	bool  mInputReturnFlag;    // Enterキーの連続入力防止
	float mGameTransitionCount;// 止めるカウント
	int   mGameCount;          // 増えると次のミニゲームに遷移する
	bool  mGameCountFlag1;     // 増えると次のミニゲームに遷移するFlag
	bool  mGameCountFlag2;     // 増えると次のミニゲームに遷移するFlag

	//------------//
	//-CircleGame-//
	//------------//
	int mCircleOutX;                 // 描く円の中心座標X
	int mCircleOutY;                 // 描く円の中心座標Y
	int mCircleOutRadius;            // 描く円の半径
	unsigned int mCircleOutColor;    // 円の色
	int mCircleOutFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ
	int mCircleOutLineThickness;     // 描く円の線の太さ

	int mCircleInX;                 // 描く円の中心座標X
	int mCircleInY;                 // 描く円の中心座標Y
	int mCircleInRadius;            // 描く円の半径
	unsigned int mCircleInColor;    // 円の色
	int mCircleInFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ

	bool mPlayCircleGame;           // サークルゲームをしているかしていないかのFlag
	bool mDrawCircleGame;           // サークルゲームを描画しているかしていないかのFlag

	//-----------//
	//-GaugeGame-//
	//-----------//
	int mGaugeOutBeginX;    // 描画する四角形の左上のX
	int mGaugeOutBeginY;    // 描画する四角形の左上のY
	int mGaugeOutEndX;      // 描画する四角形の右下+1のX
	int mGaugeOutEndY;      // 描画する四角形の右下+1のY
	unsigned int mGaugeOutColor;    // 描画する四角形の色
	int mGaugeOutFillFlag;          // 四角の中身を塗りつぶすか、のフラグ。TRUEで塗りつぶし、FALSEで塗りつぶさない

	int mGaugeInBeginX;    // 描画する四角形の左上のX
	int mGaugeInBeginY;    // 描画する四角形の左上のY
	int mGaugeInEndX;      // 描画する四角形の右下+1のX
	int mGaugeInEndY;      // 描画する四角形の右下+1のY
	unsigned int mGaugeInColor;    // 描画する四角形の色
	int mGaugeInFillFlag;          // 四角の中身を塗りつぶすか、のフラグ。TRUEで塗りつぶし、FALSEで塗りつぶさない

	bool mPlayGaugeGame;    // ゲージゲームをしているかしていないかのFlag
	bool mDrawGaugeGame;    // ゲージゲームを描画しているかしていないかのFlag


};