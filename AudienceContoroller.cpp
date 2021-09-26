#include "AudienceContoroller.h"
#include "NewAudience.h"
#include <iostream>
#include <vector>


using namespace std;
const char* GOLD_MODEL = "data/model/audience/Gold.mv1";
const char* HAT_MODEL = "data/model/audience/Hat.mv1";
const char* MAN_MODEL = "data/model/audience/Man.mv1";
const char* WOMAN_MODEL = "data/model/audience/Woman.mv1";
const char* SILVER_MODEL = "data/model/audience/Silver.mv1";
AudienceContoroller::AudienceContoroller()
	:mAudienceBetweenX(6.0f)
	,mAudienceBetweenZ(5.0f)
	,mFirstAudiencePositionX(-45.5f)
	,mFirstAudiencePositionX2(40.0f)
	,mFirstAudiencePositionZ(-30.0f)
	,mFirstAudiencePositionZ2(-20.0f)
	,mHighestJump(15.0f)
	,mHeightStairs(2.3f)
	,mGroundHeight(10.0f)
	,mFirstGroundHeight(10.0f)
	,mPosition(VGet(0,0,0))
	,mScale(VGet(1.0f,1.0f,1.0f))
	,mRotate(VGet(0.0f,2.8f,0.0f))
{
	mPosition.x = mFirstAudiencePositionX;
	mPosition.y = mGroundHeight;
	mPosition.z = mFirstAudiencePositionZ;
	
}

AudienceContoroller::~AudienceContoroller()
{

}

void AudienceContoroller::SetAudience()
{
	int i = 0;
	for (auto actors : Audiences)
	{
		i++;
		//�ϋq���Ƃ�
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

		//��񕪂̊ϋq�̃Z�b�g���I�������
		if (i % AUDIENCE_EVERY_LINE == 0)
		{
			mPosition.x -= mAudienceBetweenX;//���ɍs������
			if (i % (AUDIENCE_EVERY_LINE * 2) == 0)
			{
				//��̐擪��ݒ�
				mPosition.z = mFirstAudiencePositionZ + mAudienceBetweenZ / 2;
			}
			else
			{
				mPosition.z = mFirstAudiencePositionZ;
			}
			//�K�i�̉��i�ڂɂ��邩�ݒ肷��
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
		//�ϋq���Ƃ�
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

		//��񕪂̊ϋq�̃Z�b�g���I�������
		if (i % AUDIENCE_EVERY_LINE == 0)
		{
			mPosition.x += mAudienceBetweenX;//���ɍs������
			if (i % (AUDIENCE_EVERY_LINE * 2) == 0)
			{
				//��̐擪��ݒ�
				mPosition.z = mFirstAudiencePositionZ2 - mAudienceBetweenZ / 2;
			}
			else
			{
				mPosition.z = mFirstAudiencePositionZ2;
			}
			//�K�i�̉��i�ڂɂ��邩�ݒ肷��
			mGroundHeight += mHeightStairs;
			mPosition.y = mGroundHeight;
		}

	}
}

void AudienceContoroller::LoadAudience()
{
	//�ϋq���Ƃ�
	for (int i = 0; i < AUDIENCE_LINES * AUDIENCE_EVERY_LINE; i++)
	{
		Audiences.push_back(new NewAudience);
	}
	//���f�������[�h������
	for (auto actors : Audiences)
	{
		int i = 0;
		i = rand() % 5;
		//���f���f�[�^
		if (i == 0)
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
		}
	}
	//Audiences2
	//�ϋq���Ƃ�
	for (int i = 0; i < AUDIENCE_LINES * AUDIENCE_EVERY_LINE; i++)
	{
		Audiences2.push_back(new NewAudience);
	}
	//���f�������[�h������
	for (auto actors : Audiences2)
	{
		int i = 0;
		i = rand() % 5;
		//���f���f�[�^
		if (i == 0)
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
		}
	}
}

void AudienceContoroller::Update(float _deltaTime)
{
	//�W�����v
	for (auto actors : Audiences)
	{
		actors->UpdateActor(_deltaTime);
		actors->Update(_deltaTime);
	}
	//�W�����v
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