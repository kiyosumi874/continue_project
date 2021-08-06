#include "DxLib.h"
#include "PlayerActor.h"

/// <summary>
/// �쐬����
/// </summary>
PlayerActor::PlayerActor()
	:mPlayerPos(VGet(0, 0, 0))
	,mVelocity(VGet(0, 0, 0))
	,mMove(VGet(0, 0, 0))
	,mModelHandle(MV1LoadModel("data/model/player/player.pmx"))
{
}

/// <summary>
/// �������
/// </summary>
PlayerActor::~PlayerActor() 
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// �X�V����
/// </summary>
/// <param name="_deltaTime">�f���^�^�C��</param>
void PlayerActor::Update(float _deltaTime)
{

}

/// <summary>
/// �`�揈��
/// </summary>
void PlayerActor::Draw()
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// ����������
/// </summary>
void PlayerActor::Init()
{
}
