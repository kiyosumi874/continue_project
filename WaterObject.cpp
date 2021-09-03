#include "WaterObject.h"

// ！※！ DxLib_Init()の前にこれを忘れずに → SetUseDirect3DVersion( DX_DIRECT3D_9EX );
WaterObject::WaterObject()
	:mNowTime(GetNowCount())
	,mOldTime(GetNowCount())
{
	mFGameTimes = { 0.0f, 0.0f, 0.0f, 0.0f };
	// モデル(キューブ)
	mMHandle = MV1LoadModel("data/Shaders/Water.mv1");
	MV1SetPosition(mMHandle, VGet(0.0f, -6.5f, -55.0f));
	MV1SetScale(mMHandle, VGet(150.0f, 1.0f, 220.0f));

	// 各シェーダーの読み込み
	mPsHandle = LoadPixelShader("data/Shaders/WaterShader_pixel.pso");
	if (mPsHandle == -1)
	{
		printf("ERROR::WaterObject::PixelShader Load Failed\n");
	}
	mVsHandle = LoadVertexShader("data/Shaders/WaterShader_vertex.vso");
	if (mVsHandle == -1)
	{
		printf("ERROR::WaterObject::VertexShader Load Failed\n");
	}

	// テクスチャ読み込み
	mDiffuseHandle = LoadGraph("data/Shaders/Water_DiffuseMap.png");
	mNormalHandle = LoadGraph("data/Shaders/Water_NormalMap.png");
	mHeightHandle = LoadGraph("data/Shaders/Water_HeightMap.png");


}

WaterObject::~WaterObject()
{
	// シェーダーの削除
	DeleteShader(mPsHandle);
	DeleteShader(mVsHandle);

	// 各種テクスチャ削除
	DeleteGraph(mDiffuseHandle);
	DeleteGraph(mNormalHandle);
	DeleteGraph(mHeightHandle);
}

void WaterObject::UpdateActor(float _deltaTime)
{
}

void WaterObject::ActivateWaterShader()
{
	//---------------------------------------------------------//
	// 時間制御
	int Time;
	// 現在の時間を得る
	Time = GetNowCount();
	// 今フレームで経過した時間を得る
	mNowTime = Time - mOldTime;
	// 現在の時間を保存
	mOldTime = Time;
	mFGameTimes.x += (float)mNowTime / 12500.0f;
	//--------------------------------------------------------//
    // カメラの視線ベクトルとライトの方向ベクトルの送信
    //カメラの位置
	VECTOR C_Pos = GetCameraPosition();
	//描画するモデルハンドルのワールド変換行列（Model_Handle部分を対応するものにする）
	MATRIX MatWorld = MV1GetLocalWorldMatrix(mMHandle);
	//逆行列
	MATRIX InvMatWorld = MInverse(MatWorld);

	//視線ベクトル（ワールド→ローカル）
	C_Pos = VTransform(C_Pos, InvMatWorld);
	FLOAT4 cp = { C_Pos.x,C_Pos.y,C_Pos.z,1.0f };

	//ライトの方向ベクトル（ワールド→ローカル）
	VECTOR V_ld = GetLightDirection();
	V_ld = VTransformSR(V_ld, InvMatWorld);
	V_ld = VNorm(V_ld);
	FLOAT4 ld = { V_ld.x,V_ld.y,V_ld.z,1.0f };
	//--------------------------------------------------------//
	// シェーダーへ情報を送信
	MV1SetUseOrigShader(TRUE);
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);
	// 頂点シェーダー
	SetVSConstF(0, mFGameTimes);
	SetVSConstF(43, cp);
	SetVSConstF(15, ld);
	// ピクセルシェーダー
	SetPSConstF(0, mFGameTimes);
	SetUseTextureToShader(0, mDiffuseHandle);
	SetUseTextureToShader(1, mNormalHandle);
	SetUseTextureToShader(2, mHeightHandle);
	//SetPSConstSI(0, mDiffuseHandle);
	//SetPSConstSI(1, mNormalHandle);


	SetUsePixelShader(-1);                 // ピクセルシェーダーの割り当て解除
	SetUseVertexShader(-1);                 // ピクセルシェーダーの割り当て解除
	MV1SetUseOrigShader(FALSE);
}

void WaterObject::DrawWater()
{
	// オリジナルシェーダー仕様の有効化
	MV1SetUseOrigShader(TRUE);
	// 使用するシェーダーのセット
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);

	// 描画
	MV1DrawModel(mMHandle);

	// オリジナルシェーダーの無効化
	MV1SetUseOrigShader(FALSE);
}
