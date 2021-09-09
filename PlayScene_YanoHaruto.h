//----------------------------------------------------------------------------------//
// @file         PlayScene_YanoHaruto.h
// @brief        PlayScene_YanoHarutoクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成 
// 9/3           清澄君のプレイシーンコピー&effect追加
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"

enum class GAME_MODE_STATE : unsigned char
{
    FADE_IN,
    CAMERA_MOVE,
    WAIT,
    CIRCLE_GAME,
    GAUGE_GAME,
    PENDULUM_GAME,
    FADE_OUT
};

class PlayScene_YanoHaruto : public SceneBase
{
public:
    PlayScene_YanoHaruto();    // コンストラクタ
    ~PlayScene_YanoHaruto();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound(float _deltaTime) override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    void GameModeFadeInBehavior(float _deltaTime);
    void GameModeCameraMoveBehavior(float _deltaTime);
    void GameModeWaitBehavior(float _deltaTime);
    void GameModeCircleGameBehavior(float _deltaTime);
    void GameModeGaugeGameBehavior(float _deltaTime);
    void GameModePendulumGameBehavior(float _deltaTime);
    void GameModeFadeOutBehavior(float _deltaTime);

    GAME_MODE_STATE mGameMode;

    //class PlayCamera* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class Camera* mCamera;
    class PlayUI_YanoHaruto* mPlayUI;    // プレイUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class Audience* mAudience;       //観客へのポインタ
    class StaticObjectActor* mPool;
    class PlayerActor_YanoHaruto* mPlayer;
    class SE* mMetoronome;
    class SE* mClickNormal;
    class SE* mClickClitical;
    class Effect* mSmalleSplash;
    class Effect* mNormalSplash;
    class Effect* mBigSplash;
    class Effect* mFeather;

    VECTOR       mTargetPos;        //カメラの見ている座標

    bool  mInputReturnFlag;    // Enterキーの連続入力防止

    int   mScore;

    int mStopCount;
    int mEnterCount;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    int mFadeSpeed;

    bool mBGMFlag;

    int mGameWaitCount;

    float mJumpPower;
};
