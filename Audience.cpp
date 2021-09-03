//--------------------------------------------------------
//8/30�A�N�^�[���p��by���
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
//�_�E���t���O�̃`�F�b�N
void Audience::UpdateActor(float _deltaTime)
{
	//�n�ʂ�艺�ɂ���Ȃ�
	if (mPosition.y < mGroundHeight)
	{
		mDownFlag = false;
	}
	//�ō��W�����v���x����Ȃ�
	if (mPosition.y > mHighestJump)
	{
		mDownFlag = true;
	}
}
