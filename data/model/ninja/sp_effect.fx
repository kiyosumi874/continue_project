
float4x4 WorldViewMatrix      : WORLDVIEW;
float4x4 ProjMatrix           : PROJECTION;
float4x4 WorldMatrix          : WORLD;

float3   LightDirection    : DIRECTION < string Object = "Light"; >;
float3   CameraPosition    : POSITION  < string Object = "Camera"; >;


float4   MaterialDiffuse   : DIFFUSE  < string Object = "Geometry"; >;
float3   MaterialAmbient   : AMBIENT  < string Object = "Geometry"; >;
float3   MaterialEmmisive  : EMISSIVE < string Object = "Geometry"; >;
float3   MaterialSpecular  : SPECULAR < string Object = "Geometry"; >;
float    SpecularPower     : SPECULARPOWER < string Object = "Geometry"; >;
float3   MaterialToon      : TOONCOLOR;

float3   LightDiffuse      : DIFFUSE   < string Object = "Light"; >;
float3   LightAmbient      : AMBIENT   < string Object = "Light"; >;
float3   LightSpecular     : SPECULAR  < string Object = "Light"; >;
static float4 DiffuseColor  = MaterialDiffuse  * float4(LightDiffuse, 1.0f);
static float3 AmbientColor  = saturate(MaterialAmbient  * LightAmbient + MaterialEmmisive);
static float3 SpecularColor = MaterialSpecular * LightSpecular;

bool use_texture;
bool use_toon;


texture ObjectTexture: MATERIALTEXTURE;
sampler ObjTexSampler = sampler_state {
    texture = <ObjectTexture>;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
};

sampler MMDSamp0 : register(s0);
sampler MMDSamp1 : register(s1);
sampler MMDSamp2 : register(s2);


struct VS_OUTPUT
{
    float4 Pos        : POSITION;    // 射影変換座標
    float2 Tex        : TEXCOORD1;   // テクスチャ
    float3 Normal     : TEXCOORD2;   // 法線
    float3 Eye        : TEXCOORD3;   // カメラとの相対位置
};


// 頂点シェーダ
VS_OUTPUT Basic_VS( float4 Pos : POSITION, float3 Normal : NORMAL, float2 Tex : TEXCOORD0)
{

    float4 Pos0 = Pos;
    
    Pos = mul( Pos, WorldViewMatrix );
    Pos = mul( Pos, ProjMatrix );
    
    float3 Eye = CameraPosition - mul( Pos0, WorldMatrix );

    Normal = normalize( mul( Normal, WorldMatrix ) );
    
    VS_OUTPUT Out = { Pos, Tex, Normal, Eye };
    return Out;
}

// ピクセルシェーダ
float4 Basic_PS( float2 Tex : TEXCOORD1, float3 Normal : TEXCOORD2, float3 Eye : TEXCOORD3 ) : COLOR0
{
    float4 Color = 0;
    
    Color.rgb = saturate( max(0,dot( Normal, -LightDirection )) * DiffuseColor.rgb + AmbientColor );
    Color.a = DiffuseColor.a;
    

    float3 HalfVector = normalize( normalize(Eye) + -LightDirection );
    float3 Specular = pow( max(0,dot( HalfVector, normalize(Normal) )), SpecularPower ) * SpecularColor;
    
    if ( use_texture ) {

        Color *= tex2D( ObjTexSampler, Tex );
    }
    if ( use_toon ) {

        float LightNormal = dot( Normal, -LightDirection );
        // if(LightNormal<0){Color.rgb*=MaterialToon;} としてもよいが、境界のドットが見えてしまうのでぼかす
        Color.rgb *= lerp(MaterialToon, float3(1,1,1), saturate(LightNormal * 16 + 0.5));
    }
	float add = (1-dot(normalize(Eye),normalize(Normal)));

////////////////////////////////////////////////////////
///これを見ている人へ以下の(add > 0.65）部分の数値をいじるとハイライトの幅が変わるよ
///float4(赤,緑,青,アルファ)だよ(1,0,0,1)だと赤くなるよ
///これでわからなかったら調べてね
////////////////////////////////////////////////////////
	if(add > 0.65){
		Color = float4(0,1,0,1);
	}
////////////////////////////////////////////////////////
    return Color;
}

// テクニック定義
technique MainTec
{
    pass DrawObject
    {
        VertexShader = compile vs_2_0 Basic_VS();
        PixelShader  = compile ps_2_0 Basic_PS();
    }
}
