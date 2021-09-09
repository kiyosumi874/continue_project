// 入力項目(vertex input)
struct VS_INPUT
{
	float4 Pos        : POSITION ;	// ローカル
	float3 Tan        : TANGENT0 ;	// ローカル
	float3 Bin        : BINORMAL0 ;	// ローカル
	float3 Normal     : NORMAL0 ;	// ローカル
	float2 Tex        : TEXCOORD0 ;	// テクスチャ座標
} ;

// 出力項目(vertex output)
struct VS_OUTPUT
{
	float4 Pos      : POSITION ;	// 射影
	float2 Tex      : TEXCOORD0 ;	// テクスチャ座標
	float3 L     	: TEXCOORD1;	// ライト方向ベクトル（接空間）
	float3 E     	: TEXCOORD2;	// 視線ベクトル（接空間）
} ;

// C++ 側で設定する定数の定義
float4x4 g_World : register( c94 ) ; 		// ローカル→ワールド
float4x4 g_View  : register( c6 ) ;			// ワールド→ビュー
float4x4 g_Proj  : register( c2 ) ;			// ビュー→射影
float4 LightDirection : register( c15 ) ;	//ライトの方向（ローカル）
float4 EyePos : register( c43 ) ;			//視線ベクトル（ローカル）
float4	g_fTime	 : register( c0 ) ;	//時間

VS_OUTPUT main( VS_INPUT VSInput )
{
	VS_OUTPUT VSOutput;

	float	g_time  = g_fTime.x;

	//頂点は座標変換前に移動
	VSInput.Pos.y = sin(VSInput.Pos.z + g_time*2)+4;
	VSInput.Pos.z += sin((g_time*8)+(VSInput.Pos.y/4))/16;

    //ローカル→ワールド→ビュー→射影変換
    VSOutput.Pos = mul(mul(mul(VSInput.Pos, g_World), g_View), g_Proj);

	// 視線ベクトルをローカル→接空間へ
	float3 E = EyePos.xyz - VSInput.Pos.xyz;
	VSOutput.E.x = dot( E, VSInput.Tan ) ;
	VSOutput.E.y = dot( E, VSInput.Bin ) ;
	VSOutput.E.z = dot( E, VSInput.Normal ) ;

	// ライト方向ベクトルを接空間へ
	float3 L = LightDirection.xyz;
	VSOutput.L.x = dot( L, VSInput.Tan ) ;
	VSOutput.L.y = dot( L, VSInput.Bin ) ;
	VSOutput.L.z = dot( L, VSInput.Normal ) ;
    
	// テクスチャ出力
    VSOutput.Tex = VSInput.Tex;
    
	return VSOutput;
}