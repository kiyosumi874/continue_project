#include "DxLib.h"
#include "PlayerActor.h"

/// <summary>
/// 作成処理
/// </summary>
PlayerActor::PlayerActor()
	:mPlayerPos(VGet(0, 0, 0))
	,mVelocity(VGet(0, 0, 0))
	,mMove(VGet(0, 0, 0))
	,mModelHandle(MV1LoadModel("data/model/player/player.pmx"))
{
}

/// <summary>
/// 解放処理
/// </summary>
PlayerActor::~PlayerActor() 
{
	MV1DeleteModel(mModelHandle);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="_deltaTime">デルタタイム</param>
void PlayerActor::Update(float _deltaTime)
{

}

/// <summary>
/// 描画処理
/// </summary>
void PlayerActor::Draw()
{
	MV1SetPosition(mModelHandle, mPlayerPos);
	MV1DrawModel(mModelHandle);
}

/// <summary>
/// 初期化処理
/// </summary>
void PlayerActor::Init()
{
}
