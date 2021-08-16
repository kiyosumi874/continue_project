#include"Audience.h"
/// <summary>
/// メンバ変数の初期化
/// </summary>
/// <returns></returns>
Audience::Audience()
{
	//モデルの読み込み

	mGoldModelHandle = MV1LoadModel("data/model/audience/Gold.mv1");
	mHatModelHandle = MV1LoadModel("data/model/audience/Hat.mv1");
	mManModelHandle = MV1LoadModel("data/model/audience/Man.mv1");
	mSilverModelHandle = MV1LoadModel("data/model/audience/Silver.mv1");
	mWomanModelHandle = MV1LoadModel("data/model/audience/Woman.mv1");
	// モデルデータ読み込み失敗
	if (mGoldModelHandle == -1)
	{
		printf("Error::Temp::Not Found GoldModel Data\n");
	}
	// モデルデータ読み込み失敗
	if (mHatModelHandle == -1)
	{
		printf("Error::Temp::Not Found HatModel Data\n");
	}
	// モデルデータ読み込み失敗
	if (mManModelHandle == -1)
	{
		printf("Error::Temp::Not Found ManModel Data\n");
	}
	// モデルデータ読み込み失敗
	if (mWomanModelHandle == -1)
	{
		printf("Error::Temp::Not Found WomanModel Data\n");
	}
	// モデルデータ読み込み失敗
	if (mSilverModelHandle == -1)
	{
		printf("Error::Temp::Not Found SilverModel Data\n");
	}

	mAudienceBetween = 5.0f;	//観客同士の距離
	mDownFlag = false;         	//落下フラグ
	mDownInterval = 0.0;        //落下まで少し待つ
	mGroundHight = 10.0f;	    //地面の高さ
	mHighestJumpLine = 12.0f;	//最高ジャンプ高度
	mNowState = Idol;	        //観客の状態
	mStartPosZ = -35.0f;     	//観客の初期ｚ位置

	mPos = VGet(-45.5f, 12.0f, -35.0f);  //初期位置
	mRote = VGet(0.0f, 0.0f, 0.0f);      //回転値
	mScale = VGet(1.0f, 1.0f, 1.0f);     //各台地

	mExcitementJump = 0.2f;	//興奮時のジャンプ速度
	mIdolJump = 0.05f;	    //待機時のジャンプ速度
	mQuietJump = 0.02f;	    //しらけたジャンプ速度
}
/// <summary>
/// モデルの削除
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
/// メンバ変数の初期化
/// </summary>
void Audience::Init()
{
	mNowState = Idol;
}
/// <summary>
/// 観客の動き
/// </summary>
void Audience::Update()
{
	//待機状態なら
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
		//地面についたなら
		if (mGroundHight > mPos.y)
		{
			mDownFlag = false;
			mNowState = Excitement;
		}
		//最高ジャンプ高度より上なら
		if (mHighestJumpLine < mPos.y)
		{
			mDownFlag = true;
		}
	}
	//興奮状態なら
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
		//最高ジャンプ高度より上なら
		if (mHighestJumpLine < mPos.y)
		{
			
			mDownFlag = true;
		}
		//地面についたなら
		if (mPos.y < mGroundHight)
		{
			mDownFlag = false;
			mNowState = Quiet;
		}
	}
	//しらけてるなら
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
		//最高ジャンプ高度より上なら
		if (mHighestJumpLine < mPos.y)
		{
			mDownFlag = true;
		}
		//地面についたなら
		if (mPos.y < mGroundHight)
		{
			mDownFlag = false;
			mNowState = Idol;
		}
	}
}
/// <summary>
/// 観客の描画
/// </summary>
void Audience::Draw()
{
	mPos.z = mStartPosZ;
	//金髪観客のセット
	MV1SetPosition(mGoldModelHandle, mPos);
	MV1SetScale(mGoldModelHandle, mScale);
	MV1SetRotationXYZ(mGoldModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //観客の位置調整
	//帽子観客のセット
	MV1SetPosition(mHatModelHandle, mPos);
	MV1SetScale(mHatModelHandle, mScale);
	MV1SetRotationXYZ(mHatModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //観客の位置調整
	//男性観客のセット
	MV1SetPosition(mManModelHandle, mPos);
	MV1SetScale(mHatModelHandle, mScale);
	MV1SetRotationXYZ(mManModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //観客の位置調整
	//女性観客のセット
	MV1SetPosition(mWomanModelHandle, mPos);
	MV1SetScale(mWomanModelHandle, mScale);
	MV1SetRotationXYZ(mWomanModelHandle, mRote);
	mPos.z -= mAudienceBetween;				  //観客の位置調整
	//銀髪観客のセット
	MV1SetPosition(mSilverModelHandle, mPos);
	MV1SetScale(mSilverModelHandle, mScale);
	MV1SetRotationXYZ(mSilverModelHandle, mRote);
	
	//観客の描画
	MV1DrawModel(mGoldModelHandle);			  
	MV1DrawModel(mHatModelHandle);	
	MV1DrawModel(mManModelHandle);	
	MV1DrawModel(mWomanModelHandle);
	MV1DrawModel(mSilverModelHandle);
}
