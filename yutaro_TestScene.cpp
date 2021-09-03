#include "yutaro_TestScene.h"
#include "Camera.h"
#include "WaterObject.h"
#include "StaticObjectActor.h"

Yutaro_TestScene::Yutaro_TestScene()
    :mCamera(nullptr)
    ,mWater(nullptr)
    ,mPool(nullptr)
{
    mCamera = new Camera;
    mWater = new WaterObject;
    mWater->SetPosition(VGet(-10.0f, 0.0f, 0.0f));


    mPool = new StaticObjectActor;
    mPool->LoadModelTex("data/model/pool/Stadium.mv1", "data/model/pool/Pool.png");
}

Yutaro_TestScene::~Yutaro_TestScene()
{
    delete mCamera;
    delete mWater;
    delete mPool;
}

SceneBase* Yutaro_TestScene::Update(float _deltaTime)
{
    // ƒJƒƒ‰‚ÌXV
    mCamera->Update(VGet(50.0f, 30.0f, -80.0f), VGet(0.0f, -1.0f, -50.0f));

    mPool->Update(_deltaTime);
   //mWater->Update(_deltaTime);

    return this;
}

void Yutaro_TestScene::Draw()
{
    mPool->Draw();

    // …–Ê‚Ì•`‰æ
    mWater->ActivateWaterShader();
    mWater->DrawWater();
}

void Yutaro_TestScene::Sound(float _deltaTime)
{
}

void Yutaro_TestScene::Load()
{
}
