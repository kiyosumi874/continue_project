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

enum class DRAW_GAME_STATE : unsigned char
{
	DRAW_CIRCLE_GAME,
	DRAW_GAUGE_GAME,
	DRAW_PENDULUM_GAME,
	DRAW_NULL
};


class PlayUI : public UIBase
{
public:
	PlayUI();    // コンストラクタ
	~PlayUI();    // デストラクタ

	void Update(float _deltaTime)override;    // 更新
	void Load()                  override;    // ロード
	void Draw()                  override;    // 描画
	void Sound(class SE* _metoronome, class SE* _clickNormal, class SE* _clickClitical);


	bool GetPlayCircleGameFlag() { return mPlayCircleGameFlag; }
	bool GetPlayGaugeGameFlag() { return mPlayGaugeGameFlag; }
	bool GetPlayPendulumGameFlag() { return mPlayPendulumGameFlag; }

	void SetDrawGameState(DRAW_GAME_STATE _drawGameState) { mDrawGameState = _drawGameState; }

	// スコアのゲッター
	int GetScore() { return mScore; }


	void CircleGameBehavior(float _deltaTime);
	void GaugeGameBehavior(float _deltaTime);
	void PendulumGameBehavior(float _deltaTime);

private:


	DRAW_GAME_STATE mDrawGameState;

	int   mScore;        // スコア
	bool  mInputReturnFlag;    // Enterキーの連続入力防止
	int   mFontHandle;
	bool mClickNormalFlag;
	bool mClickCriticalFlag;
	bool mMetoronomeFlag;

	//------------//
	//-CircleGame-//
	//------------//
	float mCircleSpeed;
	float mCircleOutX;                 // 描く円の中心座標X
	float mCircleOutY;                 // 描く円の中心座標Y
	float mCircleOutRadius;            // 描く円の半径
	unsigned int mCircleOutColor;    // 円の色
	int mCircleOutFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ
	int mCircleOutLineThickness;     // 描く円の線の太さ

	float mCircleInX;                 // 描く円の中心座標X
	float mCircleInY;                 // 描く円の中心座標Y
	float mCircleInRadius;            // 描く円の半径
	unsigned int mCircleInColor;    // 円の色
	int mCircleInFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ

	bool mPlayCircleGameFlag;           // サークルゲームをしているかしていないかのFlag

	//-----------//
	//-GaugeGame-//
	//-----------//
	float mGaugeSpeed;
	float mGaugeOutBeginX;    // 描画する四角形の左上のX
	float mGaugeOutBeginY;    // 描画する四角形の左上のY
	float mGaugeOutEndX;      // 描画する四角形の右下+1のX
	float mGaugeOutEndY;      // 描画する四角形の右下+1のY
	unsigned int mGaugeOutColor;    // 描画する四角形の色
	int mGaugeOutFillFlag;          // 四角の中身を塗りつぶすか、のフラグ。TRUEで塗りつぶし、FALSEで塗りつぶさない

	float mGaugeInBeginX;    // 描画する四角形の左上のX
	float mGaugeInBeginY;    // 描画する四角形の左上のY
	float mGaugeInEndX;      // 描画する四角形の右下+1のX
	float mGaugeInEndY;      // 描画する四角形の右下+1のY
	unsigned int mGaugeInColor;    // 描画する四角形の色
	int mGaugeInFillFlag;          // 四角の中身を塗りつぶすか、のフラグ。TRUEで塗りつぶし、FALSEで塗りつぶさない

	bool mPlayGaugeGameFlag;    // ゲージゲームをしているかしていないかのFlag

	//--------------//
	//-PendulumGame-//
	//--------------//
	float mPendulumSpeed;
	float mPendulumOutX;                 // 描く円の中心座標X
	float mPendulumOutY;                 // 描く円の中心座標Y
	float mPendulumOutRadius;            // 描く円の半径
	unsigned int mPendulumOutColor;    // 円の色
	int mPendulumOutFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ
	int mPendulumOutLineThickness;     // 描く円の線の太さ

	float mPendulumInX;                 // 描く円の中心座標X
	float mPendulumInFx;                 // 支点X
	float mPendulumInY;                 // 描く円の中心座標Y
	float mPendulumInFy;                 // 支点Y
	float mPendulumInAngle;            // 角度
	float mPendulumInAngleSpeed;        // 角速度
	float mPendulumLength;                // 紐の長さ
	float mPendulumInRadius;            // 描く円の半径
	unsigned int mPendulumInColor;    // 円の色
	int mPendulumInFillFlag;          // TRUE(1の意)で円の中身も塗りつぶし、FALSE(0の意)で輪郭のみ
	
	bool mPlayPendulumGameFlag;           // 振り子ゲームをしているかしていないかのFlag

};