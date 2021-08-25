//----------------------------------------------------------------------------------//
// @file         ResultScene.h
// @brief        ResultSceneクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene : public SceneBase
{
public:
    ResultScene(int _score);    // コンストラクタ
    ~ResultScene();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    class ResultCamera* mResultCamera;    // リザルトカメラクラスへのポインタメンバ変数
    class ResultUI* mResultUI;        // リザルトUIクラスへのポインタメンバ変数
    class Player* mPlayer;
    float mDeltaTime;         // デルタタイム
    bool  mInputReturnFlag;   // Enterキーの連続入力防止
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

};

