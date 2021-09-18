#include "Actor.h"


/// <summary>
/// ������
/// </summary>
Actor::Actor()
    : mMHandle(-1)
    , mTexHandle(-1)
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
/// <summary>
/// Update
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void Actor::Update(float _deltaTime)
{
    ComputeWorldTransform();
}
/// <summary>
/// ���f���̕`��
/// </summary>
void Actor::Draw()
{

    if (mIsDrawable)
    {
       MV1DrawModel(mMHandle);
    }
}
/// <summary>
/// ���[���h���W�ɕϊ�
/// �o�J�d�v��
/// Actor��Scale,Rotate,Position��������������
/// mRecomputeWorldTransform = true�ɂ���
/// </summary>
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
/// <summary>
/// ���f���f�[�^�����[�h����
/// </summary>
/// <param name="_modelFile">"�t�@�C���l�[��"</param>
void Actor::LoadModel(const TCHAR* _modelFile)
{
    mMHandle = MV1LoadModel(_modelFile);
}

void Actor::LoadModelTex(const TCHAR* _modelFile, const TCHAR* _texFile)
{
    mMHandle = MV1LoadModel(_modelFile);
    mTexHandle = LoadGraph(_texFile);
    MV1SetTextureGraphHandle(mMHandle, 0, mTexHandle, TRUE);
}
