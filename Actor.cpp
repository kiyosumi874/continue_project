#include "Actor.h"
/// <summary>
/// ������
/// </summary>
Actor::Actor()
    : mMHandle(-1)
    , mIsDrawable(true)
    , mState(State::Active)
    , mPosition(VGet(0.0f, 0.0f, 0.0f))
    , mRotate  (VGet(0.0f, 0.0f, 0.0f))
    , mScale(VGet(1.0f, 1.0f, 1.0f))
    , mRecomputeWorldTransform(true)
{
}
/// <summary>
/// ���f���f�[�^���w��ł���R���X�g���N�^
/// </summary>
/// <param name="_modelFile"></param>
Actor::Actor(const TCHAR* _modelFile)
    : mIsDrawable(true)
    , mState(State::Active)
    , mPosition(VGet(0.0f, 0.0f, 0.0f))
    , mRotate(VGet(0.0f, 0.0f, 0.0f))
    , mScale(VGet(1.0f, 1.0f, 1.0f))
    , mRecomputeWorldTransform(true)
{
    mMHandle = MV1LoadModel(_modelFile);
}
/// <summary>
/// �㏈��
/// </summary>
Actor::~Actor()
{
    if (mMHandle != -1)
    {
       MV1DeleteModel(mMHandle);
    }
}

void Actor::Update(float _deltaTime)
{
    ComputeWorldTransform();
}

void Actor::Draw()
{
    if (mIsDrawable)
    {
       MV1DrawModel(mMHandle);
    }
}

void Actor::ComputeWorldTransform()
{
    if (mRecomputeWorldTransform)
    {
        mRecomputeWorldTransform = false;
        // �X�P�[�����O����]�����s�ړ��ƂȂ�悤�ɂ���
        MV1SetScale(mMHandle, mScale);
        MV1SetRotationXYZ(mMHandle, mRotate);
        MV1SetPosition(mMHandle, mPosition);
    }
   
}

void Actor::LoadModel(const TCHAR* _modelFile)
{
    mMHandle = MV1LoadModel(_modelFile);
}