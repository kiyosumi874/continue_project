#include"Audience.h"
/// <summary>
/// �����o�ϐ��̏�����
/// </summary>
/// <returns></returns>
Audience::Audience()
{
	//���f���̓ǂݍ���

	mGoldModelHandle = MV1LoadModel("data/model/audience/Gold.mv1");
	mHatModelHandle = MV1LoadModel("data/model/audience/Hat.mv1");
	mManModelHandle = MV1LoadModel("data/model/audience/Man.mv1");
	mSilverModelHandle = MV1LoadModel("data/model/audience/Silver.mv1");
	mWomanModelHandle = MV1LoadModel("data/model/audience/Woman.mv1");
	// ���f���f�[�^�ǂݍ��ݎ��s
	if (mGoldModelHandle == -1)
	{
		printf("Error::Temp::Not Found GoldModel Data\n");
	}
	// ���f���f�[�^�ǂݍ��ݎ��s
	if (mHatModelHandle == -1)
	{
		printf("Error::Temp::Not Found HatModel Data\n");
	}
	// ���f���f�[�^�ǂݍ��ݎ��s
	if (mManModelHandle == -1)
	{
		printf("Error::Temp::Not Found ManModel Data\n");
	}
	// ���f���f�[�^�ǂݍ��ݎ��s
	if (mWomanModelHandle == -1)
	{
		printf("Error::Temp::Not Found WomanModel Data\n");
	}
	// ���f���f�[�^�ǂݍ��ݎ��s
	if (mSilverModelHandle == -1)
	{
		printf("Error::Temp::Not Found SilverModel Data\n");
	}

	mAudienceBetween = 5.0f;	//�ϋq���m�̋���
	mDownFlag = false;         	//�����t���O
	mDownInterval = 0.0;        //�����܂ŏ����҂�
	mGroundHight = 10.0f;	    //�n�ʂ̍���
	mHighestJumpLine = 12.0f;	//�ō��W�����v���x
	mNowState = Idol;	        //�ϋq�̏��
	mStartPosZ = -35.0f;     	//�ϋq�̏������ʒu

	mPos = VGet(-45.5f, 12.0f, -35.0f);  //�����ʒu
	mRote = VGet(0.0f, 0.0f, 0.0f);      //��]�l
	mScale = VGet(1.0f, 1.0f, 1.0f);     //�e��n

	mExcitementJump = 0.2f;	//�������̃W�����v���x
	mIdolJump = 0.05f;	    //�ҋ@���̃W�����v���x
	mQuietJump = 0.02f;	    //���炯���W�����v���x
}
/// <summary>
/// ���f���̍폜
/// </summary>
/// <returns></returns>
Audience::~Audience()
{
	MV1DeleteModel(mGoldModelHandle);
	MV1DeleteModel(mHatModelHandle);
	MV1DeleteModel(mManModelHandle);
	MV1DeleteModel(mSilverModelHandle);
	MV1DeleteModel(mWomanModelHandle);
}
/// <summary>
/// �����o�ϐ��̏�����
/// </summary>
void Audience::Init()
{
	mNowState = Idol;
}
/// <summary>
/// �ϋq�̓���
/// </summary>
void Audience::Update()
{
	//�ҋ@��ԂȂ�
	if (mNowState == Idol)
	{
		if (mDownFlag)
		{
			mPos.y -= mIdolJump;
		}
		else
		{
			mPos.y += mIdolJump;
		}
		//�n�ʂɂ����Ȃ�
		if (mGroundHight > mPos.y)
		{
			mDownFlag = false;
			mNowState = Excitement;
		}
		//�ō��W�����v���x����Ȃ�
		if (mHighestJumpLine < mPos.y)
		{
			mDownFlag = true;
		}
	}
	//������ԂȂ�
	if (mNowState == Excitement)
	{
		if (mDownFlag)
		{
			mPos.y -= mExcitementJump;
		}
		else
		{
			mPos.y += mExcitementJump;
		}
		//�ō��W�����v���x����Ȃ�
		if (mHighestJumpLine < mPos.y)
		{
			
			mDownFlag = true;
		}
		//�n�ʂɂ����Ȃ�
		if (mPos.y < mGroundHight)
		{
			mDownFlag = false;
			mNowState = Quiet;
		}
	}
	//���炯�Ă�Ȃ�
	if (mNowState == Quiet)
	{
		if (mDownFlag)
		{
			mPos.y -= mQuietJump;
		}
		else
		{
			mPos.y += mQuietJump;
		}
		//�ō��W�����v���x����Ȃ�
		if (mHighestJumpLine < mPos.y)
		{
			mDownFlag = true;
		}
		//�n�ʂɂ����Ȃ�
		if (mPos.y < mGroundHight)
		{
			mDownFlag = false;
			mNowState = Idol;
		}
	}
}
/// <summary>
/// �ϋq�̕`��
/// </summary>
void Audience::Draw()
{
	mPos.z = mStartPosZ;
	//�����ϋq�̃Z�b�g
	MV1SetPosition(mGoldModelHandle, mPos);
	MV1SetScale(mGoldModelHandle, mScale);
	MV1SetRotationXYZ(mGoldModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //�ϋq�̈ʒu����
	//�X�q�ϋq�̃Z�b�g
	MV1SetPosition(mHatModelHandle, mPos);
	MV1SetScale(mHatModelHandle, mScale);
	MV1SetRotationXYZ(mHatModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //�ϋq�̈ʒu����
	//�j���ϋq�̃Z�b�g
	MV1SetPosition(mManModelHandle, mPos);
	MV1SetScale(mHatModelHandle, mScale);
	MV1SetRotationXYZ(mManModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //�ϋq�̈ʒu����
	//�����ϋq�̃Z�b�g
	MV1SetPosition(mWomanModelHandle, mPos);
	MV1SetScale(mWomanModelHandle, mScale);
	MV1SetRotationXYZ(mWomanModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //�ϋq�̈ʒu����
	//�┯�ϋq�̃Z�b�g
	MV1SetPosition(mSilverModelHandle, mPos);
	MV1SetScale(mSilverModelHandle, mScale);
	MV1SetRotationXYZ(mSilverModelHandle, mRote);
	
	//�ϋq�̕`��
	MV1DrawModel(mGoldModelHandle);			  
	MV1DrawModel(mHatModelHandle);	
	MV1DrawModel(mManModelHandle);	
	MV1DrawModel(mWomanModelHandle);
	MV1DrawModel(mSilverModelHandle);
}
