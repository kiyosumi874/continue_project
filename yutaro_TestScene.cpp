#include "yutaro_TestScene.h"
#include "Camera.h"
#include "WaterObject.h"
#include "StaticObjectActor.h"

Yutaro_TestScene::Yutaro_TestScene()
    :mCamera(nullptr)
    ,mWater(nullptr)
    ,mPool(nullptr)
{
    // �J����(���ʃV�F�[�_�[�̏��ɕK�v)
    mCamera = new Camera;
    // ���ʃI�u�W�F�N�g(���f���̓y���C�`�̐����`)
    mWater = new WaterObject;
    mWater->SetScale(VGet(150.0f, 1.0f, 225.0f));
    mWater->SetPosition(VGet(0.0f, -5.25f, -55.0f));

    // �v�[����
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
    // �J�����̍X�V
    mCamera->Update(VGet(50.0f, 30.0f, -80.0f), VGet(0.0f, -1.0f, -50.0f));
    // �v�[����̍X�V
    mPool->Update(_deltaTime);

    // ���ʃV�F�[�_�[�̍X�V
    mWater->Update(_deltaTime);
    mWater->UpdateWaterShader(_deltaTime);     // ���ʗp�V�F�[�_�[�֏����Z�b�g����

    return this;
}

void Yutaro_TestScene::Draw()
{
    mPool->Draw();

    // ���ʂ̕`��
    mWater->DrawWater();
}

void Yutaro_TestScene::Sound(float _deltaTime)
{
}

void Yutaro_TestScene::Load()
{
}
