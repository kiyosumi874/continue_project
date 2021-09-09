#include "WaterObject.h"

//----------------------------------------------------------------------------------------------//
//
// ！※！ DxLib_Init()の前にこれを忘れずに → SetUseDirect3DVersion( DX_DIRECT3D_9EX );
//
//---------------------------------------------------------------------------------------------//
WaterObject::WaterObject()
	:mNowTime(GetNowCount())
	,mOldTime(GetNowCount())
{
	mFGameTimes = { 0.0f, 0.0f, 0.0f, 0.0f };

	// モデル読み込み
	mMHandle = MV1LoadModel("data/Shaders/Water.mv1");

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

	// マテリアル読み込み
	mDiffuseHandle = LoadGraph("data/Shaders/Water_002_COLOR.jpg");
	mNormalHandle = LoadGraph("data/Shaders/Water_002_NORM.jpg");
	mHeightHandle = LoadGraph("data/Shaders/Water_002_ROUGH.jpg");

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

/// <summary>
/// 水面用シェーダー用の情報更新と送信処理
/// </summary>
/// <param name="_deltaTime"> 波長算出の時に使用する </param>
void WaterObject::UpdateWaterShader(float _deltaTime)
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
	mFGameTimes.x += (float)mNowTime / 250.0f * _deltaTime;
	//--------------------------------------------------------//
    // カメラの視線ベクトルとライトの方向ベクトルの送信
    //カメラの位置
	VECTOR C_Pos = GetCameraPosition();
	//描画するモデルハンドルのワールド変換行列（Model_Handle部分を対応するものにする）
	MATRIX WorldMat = MV1GetLocalWorldMatrix(mMHandle);
	//逆行列
	MATRIX InvWorldMat = MInverse(WorldMat);

	//視線ベクトル（ワールド→ローカル）
	C_Pos = VTransform(C_Pos, InvWorldMat);
	FLOAT4 cp = { C_Pos.x,C_Pos.y,C_Pos.z,1.0f };

	//ライトの方向ベクトル（ワールド→ローカル）
	VECTOR V_ld = GetLightDirection();
	V_ld = VTransformSR(V_ld, InvWorldMat);
	V_ld = VNorm(V_ld);
	FLOAT4 ld = { V_ld.x,V_ld.y,V_ld.z,1.0f };
	//--------------------------------------------------------//
	// シェーダーへ情報を送信
	// シェーダー有効化
	MV1SetUseOrigShader(TRUE);
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);
	//---------------------------------------------------------//
	// 頂点シェーダー
	//--------------------------------------------------------//
	SetVSConstF(0, mFGameTimes);
	SetVSConstF(43, cp);
	SetVSConstF(15, ld);
	//--------------------------------------------------------//
	// ピクセルシェーダー
	//-------------------------------------------------------//
	// 波制御用
	SetPSConstF(0, mFGameTimes);
	// マテリアル
	SetUseTextureToShader(0, mDiffuseHandle);
	SetUseTextureToShader(1, mNormalHandle);
	// エミッシブカラー
	FLOAT4 emissiveColor = { 0.1f, 0.1f, 0.1f, 1.2f };
	SetPSConstF(1, emissiveColor);
	// 透明情報             r     g     b     a = 透明度
	FLOAT4 factorColor = { 0.0f, 0.0f, 0.0f, 0.95f };
	SetPSConstF(5, factorColor);

	// シェーダーの無効化
	MV1SetUseOrigShader(FALSE);
}

/// <summary>
/// 水面シェーダー固有の描画処理
/// </summary>
void WaterObject::DrawWater()
{
	// オリジナルシェーダー仕様の有効化
	MV1SetUseOrigShader(TRUE);
	// 使用するシェーダーのセット
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);

	// 描画
	// タイル状に設置(現段階では非推奨)
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//MV1SetPosition(mMHandle, VGet((-35.0f) + 8.0f * j, -6.5f, (-12.0f) + -9.0f * i));
			//MV1DrawModel(mMHandle);
		}
	}

	// 一個だけ
	MV1DrawModel(mMHandle);

	// オリジナルシェーダーの無効化
	MV1SetUseOrigShader(FALSE);
}
