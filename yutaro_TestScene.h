#pragma once
#include "SceneBase.h"


class Yutaro_TestScene : public SceneBase
{
public:

    Yutaro_TestScene();
    ~Yutaro_TestScene();


    SceneBase* Update(float _deltaTime)override;    // 更新
    void       Draw()                  override;    // 描画
    void       Sound(float _deltaTime) override;    // 音楽
    void       Load()                  override;    // 初期化


private:

    class Camera* mCamera;

    class WaterObject* mWater;

    class StaticObjectActor* mPool;

};