//----------------------------------------------------------------------------------//
// @file         PlayScene_shougo.h
// @brief        PlayScene_shougoクラス
// @note         継承元:SceneBaseクラス              
// @author       井口 翔悟 (shougo iguchi, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class PlayScene_shougo : public SceneBase
{
public:
    PlayScene_shougo();    // コンストラクタ
    ~PlayScene_shougo();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class PlayCamera_shougo* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class PlayUI* mPlayUI;                   // プレイUIクラスへのポインタメンバ変数
    class Object_shougo* mObject;            // オブジェクトクラスへのポインタメンバ変数
    class Player* mPlayer;            // プレイヤークラスへのポインタメンバ変数
    float mDeltaTime;                        // デルタタイム
    bool  mInputReturnFlag;                  // Enterキーの連続入力防止
    bool  mGameCountFlag3;                   // 最後のミニゲームが終わったかどうかのFlag
    int   mScore;

};
