#include "DxLib.h"
#include "Object_shougo.h"



/// <summary>
/// 初期化
/// </summary>
Object_shougo::Object_shougo()
	: mModelHandle(MV1LoadModel("data/model/swim/obstruct.mv1"))
	, mDeltaTime(0.000001f)
{
	MV1SetPosition(mModelHandle, VGet(0, -50, 0));
}

/// <summary>
/// 後処理
/// </summary>
Object_shougo::~Object_shougo()
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime"></param>
void Object_shougo::Update(float _deltaTime)
{
	mDeltaTime = _deltaTime;
}

void Object_shougo::Draw()
{
	// 飛び込み台＋プールサイド
	MV1DrawModel(mModelHandle);
}

void Object_shougo::Load()
{
}
