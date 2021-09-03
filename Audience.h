//--------------------------------------------------------
//8/30�A�N�^�[���p��by���
//--------------------------------------------------------
#pragma once
#include "DxLib.h"
#include "Actor.h"

#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience:public Actor
{
	enum
	{
		Idol,
		Normal
	};
public:
	Audience(const int in_GroundHeight,const int in_HighestJump);
	~Audience();
	void UpdateActor(float _deltaTime)override; //�_�E���t���O�̃`�F�b�N�ɌĂ��
	bool GetDownFlag()const { return mDownFlag; }//�����t���O�̃Q�b�^�[
	int SetAudienceState(int in_state) { return mAudienceState = in_state; }
private:
	int mAudienceState;
	int mGroundHeight;//���n����n�ʂ̍���
	int mHighestJump; //�W�����v�̌��E
	bool mDownFlag;   //�����t���O
};