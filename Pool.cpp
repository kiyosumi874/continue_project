#include "Pool.h"
/// <summary>
/// 
/// </summary>
/// <returns></returns>
Pool::Pool()
{
	mModelHandle = MV1LoadModel("data/model/pool/pool.mv1");
    
    // ���f���f�[�^�ǂݍ��ݎ��s
    if (mModelHandle == -1)
    {
        printf("Error::Temp::Not Found Model Data\n");
    }
	mPos = VGet(0.0f, 0.0f, 0.0f);//�����ʒu
	mRote = VGet(0, 0, 0); //��]�l
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
/// �v�[���̕`��
/// </summary>
void Pool::Draw()
{
	MV1SetPosition(mModelHandle, mPos);
	MV1SetRotationXYZ(mModelHandle, mRote);
	MV1DrawModel(mModelHandle);
}
