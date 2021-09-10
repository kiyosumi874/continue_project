#pragma once
#include "DxLib.h"
#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience
{
	enum
	{
		Idol,         //‘Ò‹@
		Excitement,   //‹»•±
		Quiet,        //’ÁÃ
		Normal,       //’Êíó‘Ô
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
	int   mAudienceModelHandle[AudienceLine][AudienceNum];		  //ŠÏ‹q‚Ìƒ‚ƒfƒ‹ƒnƒ“ƒhƒ‹
	VECTOR mPos[AudienceLine][AudienceNum];	                      //ŠÏ‹q‚ÌˆÊ’u
	VECTOR mRote;		                                          //‰ñ“]
	VECTOR mScale;                                                //ŠÏ‹q‚Ì‘å‚«‚³
	float mAudienceBetweenX;                                      //ŠÏ‹q“¯m‚ÌX‹——£
	float mAudienceBetweenY;                                      //ŠÏ‹q“¯m‚ÌY‹——£
	float mAudienceBetweenZ;                                      //ŠÏ‹q“¯m‚ÌZ‹——£

	bool  mDownFlag[AudienceLine][AudienceNum];		              //—‰ºflag
	float mDownInterval;		                                  //—‰º‚Ü‚Å­‚µ‘Ò‚Â
	float mExcitementJump;                                        //‹»•±‚Ì  ’µ‚Ë•û
	float mGroundHight[AudienceLine];                             //ŠÏ‹q‚Ì—§‚Â’n–Ê‚Ì‚‚³
	float mHighestJumpLine[AudienceLine];                         //Å‚ƒWƒƒƒ“ƒv‚“x
	float mNormalJump;		                                      //‘Ò‹@‚Ì  ’µ‚Ë•û
	float mNowState;		                                      //ŠÏ‹q‚Ìó‘Ô
	float mQuietJump;		                                      //’ÁÃ‚Ì  ’µ‚Ë•û
	int   mRand;                                                  //—”
	int   mSideAudienceState;				                      //—×‚ÌŠÏ‹q‚Ìó‘Ô
	float mStartPosX;				                              //ŠÏ‹q‚Ì‰ŠúXˆÊ’u
	float mStartPosY;				                              //ŠÏ‹q‚Ì‰ŠúYˆÊ’u
	float mStartPosZ;		                                      //ŠÏ‹q‚Ì‰ŠúZˆÊ’u
};