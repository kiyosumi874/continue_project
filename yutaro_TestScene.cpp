#include "yutaro_TestScene.h"
#include "Camera.h"
#include "WaterObject.h"
#include "StaticObjectActor.h"

Yutaro_TestScene::Yutaro_TestScene()
    :mCamera(nullptr)
    ,mWater(nullptr)
    ,mPool(nullptr)
{
    // カメラ(水面シェーダーの情報に必要)
    mCamera = new Camera;
    // 水面オブジェクト(モデルはペライチの正方形)
    mWater = new WaterObject;
    mWater->SetScale(VGet(150.0f, 1.0f, 225.0f));
    mWater->SetPosition(VGet(0.0f, -5.25f, -55.0f));

    // プール場
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
    // カメラの更新
    mCamera->Update(VGet(50.0f, 30.0f, -80.0f), VGet(0.0f, -1.0f, -50.0f));
    // プール場の更新
    mPool->Update(_deltaTime);

    // 水面シェーダーの更新
    mWater->Update(_deltaTime);
    mWater->UpdateWaterShader(_deltaTime);     // 水面用シェーダーへ情報をセットする

    return this;
}

void Yutaro_TestScene::Draw()
{
    mPool->Draw();

    // 水面の描画
    mWater->DrawWater();
}

void Yutaro_TestScene::Sound(float _deltaTime)
{
}

void Yutaro_TestScene::Load()
{
}
