#pragma once
/// <summary>
/// 観客の数や観客同士の距離、ジャンプするタイミングを決めるクラス
///　9・11矢野陽大
///　9.26 LoadAudience更新
/// </summary>
#include "DxLib.h"
#include <iostream>
#include <vector>
#include "SceneBase.h"

using namespace std;
class AudienceContoroller
{
	const static int AUDIENCE_LINES = 5;//観客の列
	const static int AUDIENCE_EVERY_LINE = 14;//列ごとの観客
	vector<class NewAudience*> Audiences;
	vector<class NewAudience*> Audiences2;
public:
	AudienceContoroller();
	~AudienceContoroller();
	void SetAudience();
	void SetAudienceState(int _state);        //ジャンプを高くするなら1
	void LoadAudience();
	void Draw();
	void Update(float _deltaTime);
private:
	float mAudienceBetweenX;								  //観客同士の距離
	float mAudienceBetweenZ;								  //観客同士の距離
	float mHeightStairs;									  //階段の差
	VECTOR mPosition;		          						  //観客の座標
	VECTOR mScale;
	VECTOR mRotate;
	float mFirstAudiencePositionX;                            //観客の初期X位置
	float mFirstAudiencePositionX2;                            //観客の初期X位置
	float mFirstAudiencePositionZ;                            //観客の初期Z位置
	float mFirstAudiencePositionZ2;                            //観客の初期Z位置
	float mGroundHeight;										  //観客の立っている場所
	float mFirstGroundHeight;
	float mHighestJump;										  //観客の最高ジャンプ高度

	float mRad; //light角度ラジアン	
	float mRad2;

	int  mLight;
};