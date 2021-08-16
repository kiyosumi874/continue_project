#include "Pool.h"
/// <summary>
/// 
/// </summary>
/// <returns></returns>
Pool::Pool()
{
	mModelHandle = MV1LoadModel("data/model/pool/pool.mv1");
    
    // モデルデータ読み込み失敗
    if (mModelHandle == -1)
    {
        printf("Error::Temp::Not Found Model Data\n");
    }
	mPos = VGet(0.0f, 0.0f, 0.0f);//初期位置
	mRote = VGet(0, 0, 0); //回転値
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
Pool::~Pool()
{
	MV1DeleteModel(mModelHandle);
}
/// <summary>
/// 
/// </summary>
void Pool::Init()
{
}
/// <summary>
/// 
/// </summary>
void Pool::Update()
{
}
/// <summary>
/// プールの描画
/// </summary>
void Pool::Draw()
{
	MV1SetPosition(mModelHandle, mPos);
	MV1SetRotationXYZ(mModelHandle, mRote);
	MV1DrawModel(mModelHandle);
}
