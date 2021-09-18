#include "Actor.h"


/// <summary>
/// 初期化
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
/// モデルデータを指定できるコンストラクタ
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
/// 後処理
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
/// <param name="_deltaTime">デルタタイム</param>
void Actor::Update(float _deltaTime)
{
    ComputeWorldTransform();
}
/// <summary>
/// モデルの描画
/// </summary>
void Actor::Draw()
{

    if (mIsDrawable)
    {
       MV1DrawModel(mMHandle);
    }
}
/// <summary>
/// ワールド座標に変換
/// バカ重要↓
/// ActorのScale,Rotate,Positionをいじった時に
/// mRecomputeWorldTransform = trueにする
/// </summary>
void Actor::ComputeWorldTransform()
{
    if (mRecomputeWorldTransform)
    {
        mRecomputeWorldTransform = false;
        // スケーリング→回転→平行移動となるようにする
        MV1SetScale(mMHandle, mScale);
        MV1SetRotationXYZ(mMHandle, mRotate);
        MV1SetPosition(mMHandle, mPosition);
    }
}
/// <summary>
/// モデルデータをロードする
/// </summary>
/// <param name="_modelFile">"ファイルネーム"</param>
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
