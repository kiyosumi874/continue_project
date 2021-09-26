#include "NewAudience.h"
#define _USE_MATH_DEFINES
#include <math.h>
NewAudience::NewAudience()
	:mHighestJump()
	,mGroundHight()
	,mJumpPower(0.1f)
	,mJumpFlag(true)
{
}

NewAudience::~NewAudience()
{
}
void NewAudience::UpdateActor(float _deltaTime)
{
	/*if (mJumpFlag)
	{
		mPosition.y += mJumpPower;
	}
	else
	{
		mPosition.y -= mJumpPower;
	}*/
	////最高ジャンプ高度より上に来たら
	//if (mHighestJump < mPosition.y)
	//{
	//	mJumpFlag = false;
	//}
	////地面にめり込んだら
	//if (mGroundHight > mPosition.y)
	//{
	//	mJumpFlag = true;
	//}
	mRad+=static_cast<float>((DX_PI_F/180)*5);
	mPosition.y = 1.0f + sinf(mRad) + mGroundHight;
	SetPosition(mPosition);
}