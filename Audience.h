#pragma once
#include "DxLib.h"
#define AudienceNum  14
#define AudienceLine 5
#define AudienceKind 5

class Audience
{
	enum
	{
		Idol,         //待機
		Excitement,   //興奮
		Quiet,        //鎮静
		Normal,       //通常状態
	};
public:
	Audience();
	~Audience();
	void Init();
	void Update(int _score);
	void Draw();
	const VECTOR& mGetAudiencePos()const { return mPos[NULL][NULL]; };
private:
	int   mAudienceModelHandle[AudienceLine][AudienceNum];		  //観客のモデルハンドル
	VECTOR mPos[AudienceLine][AudienceNum];	                      //観客の位置
	VECTOR mRote;		                                          //回転
	VECTOR mScale;                                                //観客の大きさ
	float mAudienceBetweenX;                                      //観客同士のX距離
	float mAudienceBetweenY;                                      //観客同士のY距離
	float mAudienceBetweenZ;                                      //観客同士のZ距離

	int   mClickCount;                                            //クリック回数カウント
	bool  mDownFlag[AudienceLine][AudienceNum];		              //落下flag
	float mExcitementJump;                                        //興奮時の  跳ね方
	float mGroundHight[AudienceLine];                             //観客の立つ地面の高さ
	float mHighestJumpLine[AudienceLine];                         //最高ジャンプ高度
	float mNormalJump;		                                      //待機時の  跳ね方
	float mNowState;		                                      //観客の状態
	float mQuietJump;		                                      //鎮静時の  跳ね方
	int   mRand;                                                  //乱数
	int   mSideAudienceState;				                      //隣の観客の状態
	float mStartPosX;				                              //観客の初期X位置
	float mStartPosY;				                              //観客の初期Y位置
	float mStartPosZ;		                                      //観客の初期Z位置

};