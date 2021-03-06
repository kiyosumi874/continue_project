#pragma once
#include "DxLib.h"
#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience
{
	enum
	{
		Idol,         //Ò@
		Excitement,   //»±
		Quiet,        //ÁÃ
		Normal,       //ÊíóÔ
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
	int   mAudienceModelHandle[AudienceLine][AudienceNum];		  //ÏqÌfnh
	VECTOR mPos[AudienceLine][AudienceNum];	                      //ÏqÌÊu
	VECTOR mRote;		                                          //ñ]
	VECTOR mScale;                                                //ÏqÌå«³
	float mAudienceBetweenX;                                      //Ïq¯mÌX£
	float mAudienceBetweenY;                                      //Ïq¯mÌY£
	float mAudienceBetweenZ;                                      //Ïq¯mÌZ£

	bool  mDownFlag[AudienceLine][AudienceNum];		              //ºflag
	float mDownInterval;		                                  //ºÜÅ­µÒÂ
	float mExcitementJump;                                        //»±Ì  µËû
	float mGroundHight[AudienceLine];                             //ÏqÌ§ÂnÊÌ³
	float mHighestJumpLine[AudienceLine];                         //ÅWvx
	float mNormalJump;		                                      //Ò@Ì  µËû
	float mNowState;		                                      //ÏqÌóÔ
	float mQuietJump;		                                      //ÁÃÌ  µËû
	int   mRand;                                                  //
	int   mSideAudienceState;				                      //×ÌÏqÌóÔ
	float mStartPosX;				                              //ÏqÌúXÊu
	float mStartPosY;				                              //ÏqÌúYÊu
	float mStartPosZ;		                                      //ÏqÌúZÊu
};