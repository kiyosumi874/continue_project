#pragma once
#include "SceneBase.h"


class Yutaro_TestScene : public SceneBase
{
public:

    Yutaro_TestScene();
    ~Yutaro_TestScene();


    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound(float _deltaTime) override;    // ���y
    void       Load()                  override;    // ������


private:

    class Camera* mCamera;

    class WaterObject* mWater;

    class StaticObjectActor* mPool;

};