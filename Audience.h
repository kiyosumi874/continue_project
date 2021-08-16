#pragma once
#include "DxLib.h"
#define AudienceNum 5
class Audience
{
	enum
	{
		Excitement,//����
		Quiet,     //����
		Idol       //�ҋ@
	};
public:
	Audience();
	~Audience();
	void Init();
	void Update();
	void Draw();
	const VECTOR& mGetAudiencePos()const { return mPos; };
private:
	VECTOR mPos;		      //�ϋq�̈ʒu
	VECTOR mRote;		      //��]
	VECTOR mScale;           //�ϋq�̑傫��
	float mAudienceBetween;               //�ϋq���m�̋���
	bool mDownFlag;		                  //����flag
	float mDownInterval;				  //�����܂ŏ����҂�
	float mExcitementJump;   //��������  ���˕�
	int mGoldModelHandle;                 //�����́@�@���f��
	float mGroundHight;                   //�ϋq�̗��n�ʂ̍���
	int mHatModelHandle;                  //�X�q�̐l�@���f��
	float mHighestJumpLine;               //�ō��W�����v���x
	float mIdolJump;		  //�ҋ@����  ���˕�
	int mManModelHandle;                  //�j���́@�@���f��
	float mNowState;		              //�ϋq�̏��
	float mQuietJump;		  //���Î���  ���˕�
	int mSilverModelHandle;               //�┯�́@�@���f��
	float mStartPosZ;		              //�ϋq�̏���Z�ʒu
	int mWomanModelHandle;                //�����́@�@���f��

};