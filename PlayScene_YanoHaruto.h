//----------------------------------------------------------------------------------//
// @file         PlayScene_YanoHaruto.h
// @brief        PlayScene_YanoHarutoクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成 
// 8/30          プレイシーンからコピペ->プール観客追加。インクルードしたaudience.hこっちに移動
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "Audience.h"


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
    //class PlayCamera* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // プレイUIクラスへのポインタメンバ変数
    class BGM* mBGM;
    class Audience* mAudience[AudienceLine][AudienceNum];       //観客へのポインタ
    class StaticObjectActor* mPool;           //プールへのポインタ
    //class Player* mPlayer;            // プレイヤークラスへのポインタメンバ変数
    class PlayerActor* mPlayer;

    VECTOR       mTargetPos;        //プールの座標
    VECTOR       mAudiencePos;      //観客の場所

    int   mAudienceHighestJumpLine; //観客のジャンプの最高高度
    int   mAudienceGroundHeight;    //観客の立つ地面の高度
    float mAudienceJumpPower;       //観客のジャンプ力
    bool  mAudienceDownFlag;        //観客の落下フラグ
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
    int mFadeSpeed;

    bool mBGMFlag;
};
;
