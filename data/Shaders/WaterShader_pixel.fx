// 入力項目(pixel input)
struct PS_INPUT
{
	float2 Tex      	: TEXCOORD0 ;	// テクスチャ
	float3 L     		: TEXCOORD1;	//ライト方向（接空間）
	float3 E     		: TEXCOORD2;	//視線（接空間）
} ;

// 出力項目(pixel output)
struct PS_OUTPUT
{
	float4 Color0          : COLOR0 ;
} ;

// 各種マテリアル
struct MATERIAL
{
	float4 Diffuse ;      // ディフューズカラー
	float4 Specular ;     // スペキュラカラー
	float4 Power ;        // スペキュラの強さ
} ;

// ライト
struct LIGHT
{
	float4 Position ;               // 座標( ビュー空間 )※使用しません
	float3 Direction ;              // 方向( ビュー空間 )
	float4 Diffuse ;                // ディフューズカラー
	float4 Specular ;               // スペキュラカラー
	float4 Ambient ;                // アンビエントカラーとマテリアルのアンビエントカラーを乗算したもの
	float4 Range_FallOff_AT0_AT1 ;
	float4 AT2_SpotP0_SpotP1 ;
} ;

// C++ 側で設定するテクスチャや定数の定義
sampler  DiffuseMapTexture             : register( s0 ) ;		// ディフューズマップテクスチャ
sampler  NormalMapTexture              : register( s1 ) ;		// 法線マップテクスチャ
float4   cfAmbient_Emissive            : register( c1 ) ;		// エミッシブカラー + マテリアルアンビエントカラー * グローバルアンビエントカラー
MATERIAL cfMaterial                    : register( c2 ) ;		// マテリアルパラメータ
LIGHT    cfLight	                   : register( c32 ) ;		// ライトパラメータ
float4   cfFactorColor                 : register( c5 ) ;		// 不透明度等
float4 g_fTime                 : register( c0 ) ;		// 時間

PS_OUTPUT main( PS_INPUT PSInput )
{
	PS_OUTPUT PSOutput;
	
	float	g_time  = g_fTime.x;

	//視線ベクトルを正規化
	float3 E = normalize( PSInput.E ) ;
	
	//ライト方向ベクトル
	float3 L = PSInput.L;

	// テクスチャ座標
	float2 Tex = PSInput.Tex;

    // 波打ち処理
	float WaveM;
	float2 WaveUV ,WaveMove ,DirU, DirV ,WaveDir ={ 1.0, 0.0 };
	
	WaveUV.x = dot( WaveDir, Tex );
	WaveUV.y = dot( -WaveDir.yx, Tex );
	WaveM = fmod( (g_time + WaveUV.x * 5) * 6.28, 6.28 );
	WaveMove.x = sin(WaveM) * 0.01 / 2;
	WaveM = fmod( (g_time + WaveUV.y * 5) * 6.28, 6.28 );
	WaveMove.y = sin(WaveM) * 0.01 / 2;
	
	Tex += WaveMove;
	
    //ノーマルマップの二重化
    Tex.x += 0.5;
    Tex.y += (sin(g_time*3+8)/512)+(g_time/32);
	float h = tex2D( NormalMapTexture, Tex).a;
	Tex = Tex + 0.016 * h * E.xy;
	float3 N = 2.0f * tex2D( NormalMapTexture, Tex ).xyz - 1.0f;
    
         Tex.x -= 0.5;
	Tex.y -= ((sin(g_time*3+8)/512)+(g_time/32))*2.0f;
	h = tex2D( NormalMapTexture, Tex ).a;
	Tex = Tex + 0.016 * h * E.xy;
	float3 N2 = 2.0f * tex2D( NormalMapTexture, Tex ).xyz - 1.0f;

	N = ( N + N2 ) /2 ;

	// ディフューズカラーとスペキュラカラーの蓄積値を初期化
	float4 TotalDiffuse  = float4( 0.0f, 0.0f, 0.0f, 0.0f ) ;
	float4 TotalSpecular = float4( 0.0f, 0.0f, 0.0f, 0.0f ) ;
	
	// DiffuseAngleGen = ディフューズ角度減衰率計算
	float DiffuseAngleGen = saturate( dot( N, -L ) ) ;
	
	// ディフューズカラー蓄積値 += ライトのディフューズカラー * マテリアルのディフューズカラー * ディフューズカラー角度減衰率 + ライトのアンビエントカラーとマテリアルのアンビエントカラーを乗算したもの 
	TotalDiffuse += cfLight.Diffuse * cfMaterial.Diffuse * DiffuseAngleGen + cfLight.Ambient ;
	
	// ハーフベクトルの計算
	float3 H = normalize( E - L );
	// Temp = pow( max( 0.0f, N * H ), cfMaterial.Power.x )
	float Temp = pow( max( 0.0f, dot( N, H ) ), cfMaterial.Power.x ) ;
	
	// スペキュラカラー蓄積値 += Temp * ライトのスペキュラカラー
	TotalSpecular += Temp * cfLight.Specular ;
	
	// TotalDiffuse = ライトディフューズカラー蓄積値 + ( マテリアルのアンビエントカラーとグローバルアンビエントカラーを乗算したものとマテリアルエミッシブカラーを加算したもの )
	TotalDiffuse += cfAmbient_Emissive ;
	// SpecularColor = ライトのスペキュラカラー蓄積値 * マテリアルのスペキュラカラー
	float4 SpecularColor = TotalSpecular * cfMaterial.Specular ;
	// 出力カラー = TotalDiffuse * テクスチャカラー + SpecularColor
	float4 TextureDiffuseColor = tex2D( DiffuseMapTexture, Tex ) ;

	PSOutput.Color0.rgb = TextureDiffuseColor.rgb * TotalDiffuse.rgb + SpecularColor.rgb ;
	// アルファ値 = テクスチャアルファ * マテリアルのディフューズアルファ * 不透明度
	PSOutput.Color0.a = TextureDiffuseColor.a * cfMaterial.Diffuse.a * cfFactorColor.a ;

	return PSOutput;
} 