#pragma once
#include "SceneBase.h"


class Yutaro_TestScene : public SceneBase
{
public:

    Yutaro_TestScene();
    ~Yutaro_TestScene();


    SceneBase* Update(float _deltaTime)override;    // XV
    void       Draw()                  override;    // •`‰æ
    void       Sound(float _deltaTime) override;    // ‰¹Šy
    void       Load()                  override;    // ‰Šú‰»


private:

    class Camera* mCamera;

    class WaterObject* mWater;

    class StaticObjectActor* mPool;

};