#include "DxLib.h"
#include "Object_shougo.h"



/// <summary>
/// ������
/// </summary>
Object_shougo::Object_shougo()
	: mModelHandle(MV1LoadModel("data/model/swim/obstruct.mv1"))
	, mDeltaTime(0.000001f)
{
	MV1SetPosition(mModelHandle, VGet(0, -50, 0));
}

/// <summary>
/// �㏈��
/// </summary>
Object_shougo::~Object_shougo()
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime"></param>
void Object_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
}

void Object_shougo::Draw()
{
	// ��э��ݑ�{�v�[���T�C�h
	MV1DrawModel(mModelHandle);
}

void Object_shougo::Load()
{
}
