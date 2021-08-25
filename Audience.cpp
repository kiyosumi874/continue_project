#include"Audience.h"
/// <summary>
/// メンバ変数の初期化
/// </summary>
/// <returns></returns>
Audience::Audience()
{
	mAudienceBetweenX = 6.0f;	     //観客同士のX距離
	mAudienceBetweenY = 2.3f;	     //観客同士のY距離
	mAudienceBetweenZ = 5.0f;	     //観客同士のZ距離
								     
	mClickCount = 0;                 //Enterを押した回数

	mStartPosX = -45.5f;             //観客の初期x位置
	mStartPosY = 10.0f;              //観客の初期y位置
	mStartPosZ = -30.0f;     	     //観客の初期ｚ位置
	mNowState  = Normal;	         //観客の状態
	mSideAudienceState = mNowState;	 //隣の観客の状態

	mExcitementJump = 0.6f;	         //興奮時のジャンプ速度
	mNormalJump     = 0.1f;	         //通常のジャンプ速度
	mQuietJump      = 0.05f;	     //しらけたジャンプ速度

	//モデルの読み込み
	for (int i = 0; i < AudienceLine; i++)
	{	
		mGroundHight[i] = mStartPosY + i * mAudienceBetweenY;	    //列ごとの地面の高さ
		mHighestJumpLine[i] = mGroundHight[i] + 5.0f;	            //最高ジャンプ高度
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
			// モデルデータ読み込み失敗
			if (mAudienceModelHandle[i][j] == -1)
			{
				printf("Error::Temp::Not Found GoldModel Data\n");
			}
			
			mPos[i][j] = VGet(mStartPosX, mGroundHight[i], mStartPosZ);  //初期位置
			mRote = VGet(0.0f, 0.0f, 0.0f);                              //回転値
			mScale = VGet(1.0f, 1.0f, 1.0f);                             //各台地
			mDownFlag[i][j] = false;         	                         //落下フラグ
		}
	}
}
/// <summary>
/// モデルの削除
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
/// メンバ変数の初期化
/// </summary>
void Audience::Init()
{
	mNowState = Normal;
	mSideAudienceState = Normal;
	mClickCount = 0;
}
/// <summary>
/// 観客の動き
/// </summary>
void Audience::Update(int _score)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		mClickCount++;
	}
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			if (mSideAudienceState == Idol)
			{
				mNowState = Normal;
			}
			else if ((!mSideAudienceState == Idol))
			{
				mNowState = Idol;
			}
			//通常状態なら
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
				//地面についたなら
				if (mGroundHight[i] > mPos[i][j].y)
				{
					mDownFlag[i][j] = false;
					//隣の観客の状態が待機なら
					if (mSideAudienceState == Idol)
					{
						//この観客の状態を待機にする
						mNowState = Idol;
					}
				}
				//最高ジャンプ高度より上なら
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
					//隣の観客の状態が待機なら
					if (mSideAudienceState == Idol)
					{
						//この観客の状態を待機にする
						mNowState = Idol;
					}
				}
			}
			//興奮状態なら
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
				//最高ジャンプ高度より上なら
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
				}
				//地面についたなら
				if (mGroundHight[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = false;

					//隣の観客の状態が待機なら
					if (mSideAudienceState == Idol)
					{
						//この観客の状態を待機にする
						mNowState = Idol;
					}
				}
			}
			//しらけてるなら
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
				//最高ジャンプ高度より上なら
				if (mHighestJumpLine[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = true;
				}
				//地面についたなら
				if (mGroundHight[i] < mPos[i][j].y)
				{
					mDownFlag[i][j] = false;

					//隣の観客の状態が待機なら
					if (mSideAudienceState == Idol)
					{
						//この観客の状態を待機にする
						mNowState = Idol;
					}
				}
			}
			//この観客の状態を次の観客に渡す
			mSideAudienceState = mNowState;
		}//jが生きているのはここまで

	}//iが生きているのはここまで
}
/// <summary>
/// 観客の描画
/// </summary>
void Audience::Draw()
{
	
	//観客の位置指定
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			mPos[i][j].x = mStartPosX - mAudienceBetweenX * i;
			mPos[i][j].z = mStartPosZ - mAudienceBetweenZ * j;
			if (i % 2)
			{
				mPos[i][j].z += mAudienceBetweenZ;
			}
		}
	}
	for (int i = 0; i < AudienceLine; i++)
	{
		for (int j = 0; j < AudienceNum; j++)
		{
			//観客のセット
			MV1SetPosition(mAudienceModelHandle[i][j], mPos[i][j]);
			MV1SetScale(mAudienceModelHandle[i][j], mScale);
			MV1SetRotationXYZ(mAudienceModelHandle[i][j], mRote);

			//観客の描画
			MV1DrawModel(mAudienceModelHandle[i][j]);
		}
	}
}
