//--------------------------------------------------------
//8/30アクターを継承by矢野
//--------------------------------------------------------

#include"Audience.h"

Audience::Audience(const int in_GroundHeight, const int in_HighestJump)
	:mAudienceState(Idol)
{
	mGroundHeight = in_GroundHeight;
	mHighestJump  = in_HighestJump;
	mDownFlag = false;
}

Audience::~Audience()
{
}
//ダウンフラグのチェック
void Audience::UpdateActor(float _deltaTime)
{
	//地面より下にいるなら
	if (mPosition.y < mGroundHeight)
	{
		mDownFlag = false;
	}
	//最高ジャンプ高度より上なら
	if (mPosition.y > mHighestJump)
	{
		mDownFlag = true;
	}
}
