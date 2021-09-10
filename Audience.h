#pragma once
#include "DxLib.h"
#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience
{
	enum
	{
		Idol,         //�ҋ@
		Excitement,   //����
		Quiet,        //����
		Normal,       //�ʏ���
	};
public:
	Audience();
	~Audience();
	void Init();
	void Update();
	void Draw();
	const VECTOR& mGetAudiencePos()const { return mPos[NULL][NULL]; }
	void SetAudiencePos(const VECTOR& _pos) { mPos[0][0] = _pos; }
	void SetStartPosX(float _pos) { mStartPosX = _pos; }
	void SetStartPosY(float _pos) { mStartPosY = _pos; }
	void SetStartPosZ(float _pos) { mStartPosZ = _pos; }
	void SetRote(const VECTOR& _rote) { mRote = _rote; }
private:
	int   mAudienceModelHandle[AudienceLine][AudienceNum];		  //�ϋq�̃��f���n���h��
	VECTOR mPos[AudienceLine][AudienceNum];	                      //�ϋq�̈ʒu
	VECTOR mRote;		                                          //��]
	VECTOR mScale;                                                //�ϋq�̑傫��
	float mAudienceBetweenX;                                      //�ϋq���m��X����
	float mAudienceBetweenY;                                      //�ϋq���m��Y����
	float mAudienceBetweenZ;                                      //�ϋq���m��Z����

	bool  mDownFlag[AudienceLine][AudienceNum];		              //����flag
	float mDownInterval;		                                  //�����܂ŏ����҂�
	float mExcitementJump;                                        //��������  ���˕�
	float mGroundHight[AudienceLine];                             //�ϋq�̗��n�ʂ̍���
	float mHighestJumpLine[AudienceLine];                         //�ō��W�����v���x
	float mNormalJump;		                                      //�ҋ@����  ���˕�
	float mNowState;		                                      //�ϋq�̏��
	float mQuietJump;		                                      //���Î���  ���˕�
	int   mRand;                                                  //����
	int   mSideAudienceState;				                      //�ׂ̊ϋq�̏��
	float mStartPosX;				                              //�ϋq�̏���X�ʒu
	float mStartPosY;				                              //�ϋq�̏���Y�ʒu
	float mStartPosZ;		                                      //�ϋq�̏���Z�ʒu
};