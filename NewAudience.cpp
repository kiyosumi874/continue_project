#include "NewAudience.h"
#include "Actor.h"
#define _USE_MATH_DEFINES
#include <math.h>
NewAudience::NewAudience()
	:mHighestJump()
	,mGroundHight()
	,mJumpPower(0.1f)
	,mJumpFlag(true)
	,mState(NULL)
	,mRad(NULL)
{
}

NewAudience::~NewAudience()
{
}
void NewAudience::UpdateActor(float _deltaTime)
{
	mRad += static_cast<float>((DX_PI_F / 180) * 5);
	if (mState == sin)
	{
		mPosition.y = 2.0f + sinf(mRad) + mGroundHight;
	}
	if (mState == cos)
	{
		mPosition.y = 2.0f + cosf(mRad) + mGroundHight;
	}
	if (mState == tan)
	{
		mRad += static_cast<float>((DX_PI_F / 180));
		mPosition.y = 2.0f + 1.3f * cosf(mRad) + mGroundHight;
	}
	SetPosition(mPosition);
}