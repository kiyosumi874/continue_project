#include "AudienceContoroller.h"
#include "NewAudience.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//const char* GOLD_MODEL = "data/model/audience/Gold.mv1";
//const char* HAT_MODEL = "data/model/audience/Hat.mv1";
//const char* MAN_MODEL = "data/model/audience/Man.mv1";
//const char* WOMAN_MODEL = "data/model/audience/Woman.mv1";
//const char* SILVER_MODEL = "data/model/audience/Silver.mv1";
const char* MAN_MODEL = "data/model/audience/Man2.mv1";
const char* WOMAN_MODEL= "data/model/audience/Woman2.mv1";
const char* MEGAPHONE_MODEL= "data/model/audience/MegaphoneMan.mv1";
AudienceContoroller::AudienceContoroller()
	:mAudienceBetweenX(6.0f)
	,mAudienceBetweenZ(6.0f)
	,mFirstAudiencePositionX(-45.5f)
	,mFirstAudiencePositionX2(40.0f)
	,mFirstAudiencePositionZ(-15.0f)
	,mFirstAudiencePositionZ2(-15.0f)
	,mHighestJump(15.0f)
	,mHeightStairs(2.3f)
	,mGroundHeight(10.0f)
	,mFirstGroundHeight(10.0f)
	,mPosition(VGet(0,0,0))
	,mScale(VGet(0.01f,0.01f,0.01f))
	,mRotate(VGet(0.0f,2.8f,0.0f))
	,mRad(NULL)
	,mLight(NULL)
{
	mPosition.x = mFirstAudiencePositionX;
	mPosition.y = mGroundHeight;
	mPosition.z = mFirstAudiencePositionZ;
	mRad = static_cast<float>((DX_PI_F / 90) * 2);
	mRad2 = static_cast<float>((DX_PI_F / 90) * 1.2);
}

AudienceContoroller::~AudienceContoroller()
{
	DeleteLightHandle(mLight);
}

void AudienceContoroller::SetAudience()
{
	//CreatePointLightHandle(          Position       , Range, Atten0, Atten1, Atten2 ) Attenは距離減衰パラメータ
	//                      最初の観客（プレイヤー側）,最後の観客
	//CreateSpotLightHandle(ライトの場所              , 向き                外角, 内角, 距離, 減衰パラメータ3  ) 
	CreateSpotLightHandle(VGet(-35.5f, 50.0f, -40.5f), VGet(-35.5, 0, -40.5), mRad, mRad2, 30.0f, 50.0f, 3.0f,2.0f);
	int i = 0;
	for (auto actors : Audiences)//最初の観客-45,10,-15。最後の観客-69.5,20,-90
	{
		i++;
		//観客ごとに
		actors->SetPosition(mPosition);
		actors->SetScale(mScale);
		actors->SetGroundHeight(mGroundHeight);
		if (i % 2 == 0)
		{
			actors->SetRad(-1);
		}
		else
		{
			actors->SetRad(1);
		}
		mPosition.z -= mAudienceBetweenZ;

		//一列分の観客のセットが終わったら
		if (i % AUDIENCE_EVERY_LINE == 0)
		{
			mPosition.x -= mAudienceBetweenX;//奥に行かせる
			if (i % (AUDIENCE_EVERY_LINE * 2) == 0)
			{
				//列の先頭を設定
				mPosition.z = mFirstAudiencePositionZ + mAudienceBetweenZ / 2;
			}
			else
			{
				mPosition.z = mFirstAudiencePositionZ;
			}
			//階段の何段目にいるか設定する
			mGroundHeight += mHeightStairs;
			mPosition.y = mGroundHeight;
		}
	}
	//Audiences2
	i = 0;
	mGroundHeight = mFirstGroundHeight;
	mPosition.x = mFirstAudiencePositionX2;
	mPosition.y = mGroundHeight;
	mPosition.z = mFirstAudiencePositionZ2;
	for (auto actors : Audiences2)
	{
		i++;
		//観客ごとに
		actors->SetPosition(mPosition);
		actors->SetScale(mScale);
		actors->SetGroundHeight(mGroundHeight);
		actors->SetRotation(mRotate);
		if (i % 2 == 0)
		{
			actors->SetRad(-1);
		}
		else
		{
			actors->SetRad(1);
		}
		mPosition.z -= mAudienceBetweenZ;

		//一列分の観客のセットが終わったら
		if (i % AUDIENCE_EVERY_LINE == 0)
		{

			mPosition.x += mAudienceBetweenX;//奥に行かせる
			if (i % (AUDIENCE_EVERY_LINE * 2) == 0)
			{	
				//列の先頭を設定
				mPosition.z = mFirstAudiencePositionZ2 - mAudienceBetweenZ / 2;
			}
			else
			{
				mPosition.z = mFirstAudiencePositionZ2;
			}
			//階段の何段目にいるか設定する
			mGroundHeight += mHeightStairs;
			mPosition.y = mGroundHeight;
		}
	}
	SetAudienceState(0);
}

void AudienceContoroller::SetAudienceState(int _state)
{
	if (_state == 1)
	{
		for (auto actors : Audiences)
		{
			actors->SetState(2);
		}
		for (auto actors : Audiences2)
		{
			actors->SetState(2);
		}
	}
	else
	{
		int i = 0;
		for (auto actors : Audiences)
		{
			i = rand() % 2;
			actors->SetState(i);
		}
		for (auto actors : Audiences2)
		{
			i = rand() % 2;
			actors->SetState(i);
		}
	}
}

void AudienceContoroller::LoadAudience()
{
	//観客ごとに
	for (int i = 0; i < AUDIENCE_LINES * AUDIENCE_EVERY_LINE; i++)
	{
		Audiences.push_back(new NewAudience);
	}
	//モデルをロードさせる
	for (auto actors : Audiences)
	{
		int i = 0;
		i = rand() % 3;
		//モデルデータ
		if (i == 0)
		{
			actors->LoadModel(MEGAPHONE_MODEL);
		}
		if (i == 1)
		{
			actors->LoadModel(WOMAN_MODEL);
		}
		if (i == 2)
		{
			actors->LoadModel(MAN_MODEL);
		}
		/*if (i == 0)
		{
			actors->LoadModel(GOLD_MODEL);
		}
		if (i == 1)
		{
			actors->LoadModel(HAT_MODEL);
		}
		if (i == 2)
		{
			actors->LoadModel(MAN_MODEL);
		}
		if (i == 3)
		{
			actors->LoadModel(SILVER_MODEL);
		}
		if (i == 4)
		{
			actors->LoadModel(WOMAN_MODEL);
		}*/
	}
	//Audiences2
	//観客ごとに
	for (int i = 0; i < AUDIENCE_LINES * AUDIENCE_EVERY_LINE; i++)
	{
		Audiences2.push_back(new NewAudience);
	}
	//モデルをロードさせる
	for (auto actors : Audiences2)
	{
		int i = 0;
		i = rand() % 3;
		//モデルデータ
		if (i == 0)
		{
			actors->LoadModel(MEGAPHONE_MODEL);
		}
		if (i == 1)
		{
			actors->LoadModel(WOMAN_MODEL);
		}
		if (i == 2)
		{
			actors->LoadModel(MAN_MODEL);
		}
		/*if (i == 0)
		{
			actors->LoadModel(GOLD_MODEL);
		}
		if (i == 1)
		{
			actors->LoadModel(HAT_MODEL);
		}
		if (i == 2)
		{
			actors->LoadModel(MAN_MODEL);
		}
		if (i == 3)
		{
			actors->LoadModel(SILVER_MODEL);
		}
		if (i == 4)
		{
			actors->LoadModel(WOMAN_MODEL);
		}*/
	}
}

void AudienceContoroller::Update(float _deltaTime)
{
	//ジャンプ
	for (auto actors : Audiences)
	{
		actors->UpdateActor(_deltaTime);
		actors->Update(_deltaTime);
	}
	//ジャンプ
	for (auto actors : Audiences2)
	{
		actors->UpdateActor(_deltaTime);
		actors->Update(_deltaTime);
	}
}

void AudienceContoroller::Draw()
{
	for (auto actors : Audiences)
	{
		actors->Draw();
	}
	for (auto actors : Audiences2)
	{
		actors->Draw();
	}
}