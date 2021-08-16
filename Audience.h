#pragma once
#include "DxLib.h"
#define AudienceNum 5
class Audience
{
	enum
	{
		Excitement,//興奮
		Quiet,     //鎮静
		Idol       //待機
	};
public:
	Audience();
	~Audience();
	void Init();
	void Update();
	void Draw();
	const VECTOR& mGetAudiencePos()const { return mPos; };
private:
	VECTOR mPos;		      //観客の位置
	VECTOR mRote;		      //回転
	VECTOR mScale;           //観客の大きさ
	float mAudienceBetween;               //観客同士の距離
	bool mDownFlag;		                  //落下flag
	float mDownInterval;				  //落下まで少し待つ
	float mExcitementJump;   //興奮時の  跳ね方
	int mGoldModelHandle;                 //金髪の　　モデル
	float mGroundHight;                   //観客の立つ地面の高さ
	int mHatModelHandle;                  //帽子の人　モデル
	float mHighestJumpLine;               //最高ジャンプ高度
	float mIdolJump;		  //待機時の  跳ね方
	int mManModelHandle;                  //男性の　　モデル
	float mNowState;		              //観客の状態
	float mQuietJump;		  //鎮静時の  跳ね方
	int mSilverModelHandle;               //銀髪の　　モデル
	float mStartPosZ;		              //観客の初期Z位置
	int mWomanModelHandle;                //女性の　　モデル

};