//----------------------------------------------------------------------------------//
// @file         ResultScene_kiyosumi.h
// @brief        ResultScene_kiyosumiクラス
// @note         継承元:SceneBaseクラス              
// @author       椎原 清澄 (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    新規作成
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_kiyosumi : public SceneBase
{
public:
    ResultScene_kiyosumi();    // コンストラクタ
    ~ResultScene_kiyosumi();    // デストラクタ

    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound()                 override;    // 音楽
    void       Load()                  override;    // 初期化
private:
    float mDeltaTime;         // デルタタイム
    bool  mInputReturnFlag;   // Enterキーの連続入力防止
};

