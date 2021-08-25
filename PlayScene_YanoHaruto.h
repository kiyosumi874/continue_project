#pragma once
//----------------------------------------------------------------------------------//
// @file         PlayScene_YanoHaruto.h
// @brief        PlayScene_YanoHarutoクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"

class PlayScene_YanoHaruto : public SceneBase
{
public:
    PlayScene_YanoHaruto();    // コンストラクタ
    ~PlayScene_YanoHaruto();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化

private:
    class PlayCamera* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class PlayUI* mPlayUI;    // プレイUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class Audience* mAudience;       //観客へのポインタ
    class Pool* mPool;           //プールへのポインタ
    class Player* mPlayer;            // プレイヤークラスへのポインタメンバ変数

    VECTOR       mTargetPos;        //プールの座標

    float mDeltaTime;          // デルタタイム
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    bool  mGameCountFlag3;     // 最後のミニゲームが終わったかどうかのFlag
    int   mScore;
    bool mPlayCircleGameFlag;
    bool mPlayGaugeGameFlag;
    bool mPlayPendulumGameFlag;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;

    bool mBGMFlag;
};
