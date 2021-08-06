//----------------------------------------------------------------------------------//
// @file         PlayScene_kiyosumi.h
// @brief        PlayScene_kiyosumiクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class PlayScene_kiyosumi : public SceneBase
{
public:
     PlayScene_kiyosumi();    // コンストラクタ
    ~PlayScene_kiyosumi();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class PlayCamera* mPlayCamera;    // プレイカメラクラスへのポインタメンバ変数
    class PlayUI*         mPlayUI;    // プレイUIクラスへのポインタメンバ変数
    float mDeltaTime;          // デルタタイム
    bool  mInputReturnFlag;    // Enterキーの連続入力防止
    bool  mGameCountFlag3;     // 最後のミニゲームが終わったかどうかのFlag
    int   mScore;
};