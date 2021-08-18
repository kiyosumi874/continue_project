#include"Audience.h"
/// <summary>
/// �����o�ϐ��̏�����
/// </summary>
/// <returns></returns>
Audience::Audience()
{
	mAudienceBetweenX = 7.0f;	     //�ϋq���m��X����
	mAudienceBetweenY = 1.5f;	     //�ϋq���m��Y����
	mAudienceBetweenZ = 5.0f;	     //�ϋq���m��Z����
	mDownInterval = 0.0;             //�����܂ŏ����҂�
								     
	mNowState  = Normal;	             //�ϋq�̏��
	mStartPosX = -45.5f;             //�ϋq�̏���x�ʒu
	mStartPosY = 10.0f;              //�ϋq�̏���y�ʒu
	mStartPosZ = -17.0f;     	     //�ϋq�̏������ʒu
	mSideAudienceState = mNowState;	 //�ׂ̊ϋq�̏��

	mExcitementJump = 0.2f;	         //�������̃W�����v���x
	mNormalJump     = 0.03f;	     //�ʏ�̃W�����v���x
	mQuietJump      = 0.02f;	     //���炯���W�����v���x

	//���f���̓ǂݍ���
	for (int i = 0; i < AudienceLine; i++)
	{	
		mGroundHight[i] = mStartPosY + i * mAudienceBetweenY;	    //�񂲂Ƃ̒n�ʂ̍���
		mHighestJumpLine[i] = mGroundHight[i] + 1.0f;	            //�ō��W�����v���x
		for (int j = 0; j < AudienceNum; j++)
		{
			mRand = rand() % 5;

			if (mRand == 0)
			{
				mAudienceModelHandle[i][j] = MV1LoadModel("data/model/audience/Gold.mv1");
			}
			if (mRand == 1)
			{
				mAudienceModelHandle[i][j] = MV1LoadModel("data/model/audience/Hat.mv1");
			}
			if (mRand == 2)
			{
				mAudienceModelHandle[i][j] = MV1LoadModel("data/model/audience/Man.mv1");
			}
			if (mRand == 3)
			{
				mAudienceModelHandle[i][j] = MV1LoadModel("data/model/audience/Silver.mv1");
			}
			if (mRand == 4)
			{
				mAudienceModelHandle[i][j] = MV1LoadModel("data/model/audience/Woman.mv1");
			}
			// ���f���f�[�^�ǂݍ��ݎ��s
			if (mAudienceModelHandle[i][j] == -1)
			{
				printf("Error::Temp::Not Found GoldModel Data\n");
			}
			
			mPos[i][j] = VGet(mStartPosX, mGroundHight[i], mStartPosZ);  //�����ʒu
			mRote = VGet(0.0f, 0.0f, 0.0f);                              //��]�l
			mScale = VGet(1.0f, 1.0f, 1.0f);                             //�e��n
			mDownFlag[i][j] = false;         	                         //�����t���O
		}
	}
}
/// <summary>
/// ���f���̍폜
/// </summary>
/// <returns></returns>
Audience::~Audience()
{
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			MV1DeleteModel(mAudienceModelHandle[i][j]);
		}
	}
}
/// <summary>
/// �����o�ϐ��̏�����
/// </summary>
void Audience::Init()
{
	mNowState = Normal;
}
/// <summary>
/// �ϋq�̓���
/// </summary>
void Audience::Update()
{
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			if (mSideAudienceState == Idol)
			{
				mNowState = Normal;
			}
			else if (!mSideAudienceState == Idol)
			{
				mNowState = Idol;
			}
			//�ʏ��ԂȂ�
			if (mNowState == Normal)
			{
				if (mDownFlag[i][j])
				{
					mPos[i][j].y -= mNormalJump;
				}
				else
				{
					mPos[i][j].y += mNormalJump;
				}
				//�n�ʂɂ����Ȃ�
				if (mGroundHight[i] > mPos[i][j].y)
				{
					mDownFlag[i][j] = false;
					//�ׂ̊ϋq�̏�Ԃ��ҋ@�Ȃ�
					if (mSideAudienceState == Idol)
					{
						//���̊ϋq�̏�Ԃ�ҋ@�ɂ���
						mNowState = Idol;
					}
				}
				//�ō��W�����v���x����Ȃ�
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
				}
			}
			//������ԂȂ�
			if (mNowState == Excitement)
			{
				if (mDownFlag[i][j])
				{
					mPos[i][j].y -= mExcitementJump;
				}
				else
				{
					mPos[i][j].y += mExcitementJump;
				}
				//�ō��W�����v���x����Ȃ�
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
				}
				//�n�ʂɂ����Ȃ�
				if (mGroundHight[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = false;

					//�ׂ̊ϋq�̏�Ԃ��ҋ@�Ȃ�
					if (mSideAudienceState == Idol)
					{
						//���̊ϋq�̏�Ԃ�ҋ@�ɂ���
						mNowState = Idol;
					}
				}
			}
			//���炯�Ă�Ȃ�
			if (mNowState == Quiet)
			{
				if (mDownFlag[i][j])
				{
					mPos[i][j].y -= mQuietJump;
				}
				else
				{
					mPos[i][j].y += mQuietJump;
				}
				//�ō��W�����v���x����Ȃ�
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
				}
				//�n�ʂɂ����Ȃ�
				if (mGroundHight[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = false;

					//�ׂ̊ϋq�̏�Ԃ��ҋ@�Ȃ�
					if (mSideAudienceState == Idol)
					{
						//���̊ϋq�̏�Ԃ�ҋ@�ɂ���
						mNowState = Idol;
					}
				}
			}
			//���̊ϋq�̏�Ԃ����̊ϋq�ɓn��
			mSideAudienceState = mNowState;
		}//j�������Ă���̂͂����܂�

	}//i�������Ă���̂͂����܂�
}
/// <summary>
/// �ϋq�̕`��
/// </summary>
void Audience::Draw()
{
	
	//�ϋq�̈ʒu�w��
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mPos[i][j].x = mStartPosX - mAudienceBetweenX * i;
			mPos[i][j].z = mStartPosZ - mAudienceBetweenZ * j;
			mPos[i][j].z  -= mAudienceBetweenZ * i;
		}
	}
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			//�ϋq�̃Z�b�g
			MV1SetPosition(mAudienceModelHandle[i][j], mPos[i][j]);
			MV1SetScale(mAudienceModelHandle[i][j], mScale);
			MV1SetRotationXYZ(mAudienceModelHandle[i][j], mRote);

			//�ϋq�̕`��
			MV1DrawModel(mAudienceModelHandle[i][j]);
		}
	}
}
