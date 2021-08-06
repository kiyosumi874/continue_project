////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main.fx
//  �쐬: ���͉��P
//  ����: �p����
//
////////////////////////////////////////////////////////////////////////////////////////////////
// �p�����[�^�錾

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// �ŏ���ւ�ɒǉ�

#include "_Main.fxsub"

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// ���@�ϊ��s��
float4x4 WorldViewProjMatrix      : WORLDVIEWPROJECTION;
float4x4 WorldMatrix              : WORLD;
float4x4 ViewMatrix               : VIEW;
float4x4 LightWorldViewProjMatrix : WORLDVIEWPROJECTION < string Object = "Light"; >;

float3   LightDirection    : DIRECTION < string Object = "Light"; >;
float3   CameraPosition    : POSITION  < string Object = "Camera"; >;

// �}�e���A���F
float4   MaterialDiffuse   : DIFFUSE  < string Object = "Geometry"; >;
float3   MaterialAmbient   : AMBIENT  < string Object = "Geometry"; >;
float3   MaterialEmmisive  : EMISSIVE < string Object = "Geometry"; >;
float3   MaterialSpecular  : SPECULAR < string Object = "Geometry"; >;
float    SpecularPower     : SPECULARPOWER < string Object = "Geometry"; >;
float3   MaterialToon      : TOONCOLOR;
float4   EdgeColor         : EDGECOLOR;
float4   GroundShadowColor : GROUNDSHADOWCOLOR;
// ���C�g�F
float3   LightDiffuse      : DIFFUSE   < string Object = "Light"; >;
float3   LightAmbient      : AMBIENT   < string Object = "Light"; >;
float3   LightSpecular     : SPECULAR  < string Object = "Light"; >;
static float4 DiffuseColor  = MaterialDiffuse  * float4(LightDiffuse, 1.0f);
static float3 AmbientColor  = MaterialAmbient  * LightAmbient + MaterialEmmisive;
static float3 SpecularColor = MaterialSpecular * LightSpecular;

// �e�N�X�`���ގ����[�t�l
float4   TextureAddValue   : ADDINGTEXTURE;
float4   TextureMulValue   : MULTIPLYINGTEXTURE;
float4   SphereAddValue    : ADDINGSPHERETEXTURE;
float4   SphereMulValue    : MULTIPLYINGSPHERETEXTURE;

// �t���O
bool use_texture;
bool use_spheremap;
bool use_toon;
bool use_subtexture;
bool parthf;
bool transp;
bool spadd;
#define SKII1    1500
#define SKII2    8000
#define Toon     3


////////////////////////////////////////////////////////////////////////////////////////////////
// �e�N�X�`��

// �I�u�W�F�N�g�̃e�N�X�`��
texture ObjectTexture: MATERIALTEXTURE;
sampler ObjTexSampler = sampler_state {
    texture = <ObjectTexture>;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
    MIPFILTER = LINEAR;
    ADDRESSU  = WRAP;
    ADDRESSV  = WRAP;
};

// �X�t�B�A�}�b�v�̃e�N�X�`��
texture ObjectSphereMap: MATERIALSPHEREMAP;
sampler ObjSphareSampler = sampler_state {
    texture = <ObjectSphereMap>;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
    MIPFILTER = LINEAR;
    ADDRESSU  = WRAP;
    ADDRESSV  = WRAP;
};

// �g�D�[���}�b�v�̃e�N�X�`��
texture ObjectToonTexture: MATERIALTOONTEXTURE;
sampler ObjToonSampler = sampler_state {
    texture = <ObjectToonTexture>;
    MINFILTER = LINEAR;
    MAGFILTER = LINEAR;
    MIPFILTER = NONE;
    ADDRESSU  = CLAMP;
    ADDRESSV  = CLAMP;
};


///////////////////////////////////////////////////////////////////////////////////////////////
// �V�F�[�_�[�i�Z���t�V���h�EOFF�j

struct VS_OUTPUT {
    float4 Pos        : POSITION;    // �ˉe�ϊ����W
    float2 Tex        : TEXCOORD1;   // �e�N�X�`��
    float3 Normal     : TEXCOORD2;   // �@��
    float3 Eye        : TEXCOORD3;   // �J�����Ƃ̑��Έʒu
    float2 SpTex      : TEXCOORD4;   // �X�t�B�A�}�b�v�e�N�X�`�����W
    float4 Color      : COLOR0;      // �f�B�t���[�Y�F
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// struct�`�̏��ɒǉ�

    EYE_STRUCT

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
};

VS_OUTPUT Basic_VS(float4 Pos : POSITION, float3 Normal : NORMAL, float2 Tex : TEXCOORD0, float2 Tex2 : TEXCOORD1)
{
    VS_OUTPUT Out = (VS_OUTPUT)0;

    // �J�������_�̃��[���h�r���[�ˉe�ϊ�
    Out.Pos = mul(Pos, WorldViewProjMatrix);
    
    // �J�����Ƃ̑��Έʒu
    Out.Eye = CameraPosition - mul(Pos, WorldMatrix);
    // ���_�@��
    Out.Normal = normalize(mul(Normal, (float3x3)WorldMatrix));
    
    // �f�B�t���[�Y�F�{�A���r�G���g�F �v�Z
    Out.Color.rgb = AmbientColor;
    Out.Color.rgb += lerp(max(0,dot( Out.Normal, -LightDirection )) * DiffuseColor.rgb, 0, use_toon);
    Out.Color.a = DiffuseColor.a;
    Out.Color = saturate( Out.Color );
    
    // �e�N�X�`�����W
    Out.Tex = Tex;
    
    float2 NormalWV = mul(Out.Normal, (float3x3)ViewMatrix);
    Out.SpTex.x = use_subtexture ? Tex2.x : NormalWV.x * 0.5f + 0.5f;
    Out.SpTex.y = use_subtexture ? Tex2.y : NormalWV.y * -0.5f + 0.5f;
    
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// return Out;�̒��O�ɒǉ�

    EYE_DRAW_VS

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
    
    return Out;
}

float4 Basic_PS(VS_OUTPUT IN) : COLOR0
{
    float4 Color = IN.Color;
    
    // �e�N�X�`���K�p
    Color *= use_texture ? tex2D(ObjTexSampler,IN.Tex) : 1;
    
    // �X�t�B�A�}�b�v�K�p
    float4 TexColor = tex2D(ObjSphareSampler,IN.SpTex);
    Color.rgb = use_spheremap ? (spadd ? Color.rgb + TexColor.rgb : Color.rgb * TexColor.rgb) : Color.rgb;
    Color.a *= use_spheremap ? TexColor.a : 1;
    
    // �g�D�[���K�p
    float comp = saturate(dot(IN.Normal,-LightDirection)*Toon);
    
#if ENABLE_TOON
    // �g�D�[����
    comp = step(0.5, comp);
#endif
    
    Color.rgb *= use_toon ? (comp ? 1 : MaterialToon) : 1;
    
    // �X�y�L�����K�p
    Color.rgb += pow( max(0,dot( normalize( normalize(IN.Eye) + -LightDirection ), IN.Normal )), SpecularPower ) * SpecularColor;
    
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// return Color;�̒��O�ɒǉ�

    EYE_DRAW_PS

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
    
    return Color;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// �V�F�[�_�[�i�Z���t�V���h�EON�j

// �V���h�E�o�b�t�@�̃T���v���B"register(s0)"�Ȃ̂�MMD��s0���g���Ă��邩��
sampler DefSampler : register(s0);

struct BufferShadow_OUTPUT {
    float4 Pos      : POSITION;     // �ˉe�ϊ����W
    float4 ZCalcTex : TEXCOORD0;    // Z�l
    float2 Tex      : TEXCOORD1;    // �e�N�X�`��
    float3 Normal   : TEXCOORD2;    // �@��
    float3 Eye      : TEXCOORD3;    // �J�����Ƃ̑��Έʒu
    float2 SpTex    : TEXCOORD4;    // �X�t�B�A�}�b�v�e�N�X�`�����W
    float4 Color    : COLOR0;       // �f�B�t���[�Y�F
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// struct�`�̏��ɒǉ�

    EYE_STRUCT

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
};

BufferShadow_OUTPUT BufferShadow_VS(float4 Pos : POSITION, float3 Normal : NORMAL, float2 Tex : TEXCOORD0, float2 Tex2 : TEXCOORD1)
{
    BufferShadow_OUTPUT Out = (BufferShadow_OUTPUT)0;

    // �J�������_�̃��[���h�r���[�ˉe�ϊ�
    Out.Pos = mul(Pos, WorldViewProjMatrix);
    
    // �J�����Ƃ̑��Έʒu
    Out.Eye = CameraPosition - mul(Pos, WorldMatrix);
    // ���_�@��
    Out.Normal = normalize(mul(Normal, (float3x3)WorldMatrix));
    
    // ���C�g���_�ɂ�郏�[���h�r���[�ˉe�ϊ�
    Out.ZCalcTex = mul(Pos, LightWorldViewProjMatrix);
    
    // �f�B�t���[�Y�F�{�A���r�G���g�F �v�Z
    Out.Color.rgb = AmbientColor;
    Out.Color.rgb += lerp(0, max(0,dot( Out.Normal, -LightDirection )) * DiffuseColor.rgb, use_toon);
    Out.Color.a = DiffuseColor.a;
    Out.Color = saturate( Out.Color );
    
    // �e�N�X�`�����W
    Out.Tex = Tex;
    
    float2 NormalWV = mul( Out.Normal, (float3x3)ViewMatrix );
    Out.SpTex.x = use_subtexture ? Tex2.x : NormalWV.x * 0.5f + 0.5f;
    Out.SpTex.y = use_subtexture ? Tex2.y : NormalWV.y * -0.5f + 0.5f;
    
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// return Out;�̒��O�ɒǉ�

    EYE_DRAW_VS

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
    
    return Out;
}

float4 BufferShadow_PS(BufferShadow_OUTPUT IN) : COLOR
{
    float4 Color = IN.Color;
    float4 ShadowColor = float4(saturate(AmbientColor), Color.a);
    
    // �e�N�X�`���K�p
    float4 TexColor = tex2D(ObjTexSampler, IN.Tex);
    TexColor.rgb = lerp(1, TexColor * TextureMulValue + TextureAddValue, TextureMulValue.a + TextureAddValue.a);
    Color *= use_texture ? TexColor : 1;
    ShadowColor *= use_texture ? TexColor : 1;
    
    // �X�t�B�A�}�b�v�K�p
    TexColor = tex2D(ObjSphareSampler,IN.SpTex);
    TexColor.rgb = lerp(spadd?0:1, TexColor * SphereMulValue + SphereAddValue, SphereMulValue.a + SphereAddValue.a);
    
    Color.rgb = use_spheremap ? (spadd ? Color.rgb + TexColor.rgb : Color.rgb * TexColor.rgb) : Color.rgb;
    ShadowColor.rgb = use_spheremap ? (spadd ? ShadowColor.rgb + TexColor.rgb : ShadowColor.rgb * TexColor.rgb) : ShadowColor.rgb;
    Color.a *= use_spheremap ? TexColor.a : 1;
    ShadowColor.a *= use_spheremap ? TexColor.a : 1;
    
    // �X�y�L�����K�p
    Color.rgb += pow( max(0,dot( normalize( normalize(IN.Eye) + -LightDirection ), IN.Normal )), SpecularPower ) * SpecularColor;
    
    // �e�N�X�`�����W�ɕϊ�
    IN.ZCalcTex /= IN.ZCalcTex.w;
    float2 TransTexCoord;
    TransTexCoord.x = (1.0f + IN.ZCalcTex.x)*0.5f;
    TransTexCoord.y = (1.0f - IN.ZCalcTex.y)*0.5f;
    
    float comp = 1.0;
    if( any( saturate(TransTexCoord) != TransTexCoord ) ) {
        // �V���h�E�o�b�t�@�O�͉������Ȃ�
    } else {
        // �Z���t�V���h�E
        comp=1-saturate(max(IN.ZCalcTex.z-tex2D(DefSampler,TransTexCoord).r, 0.0f)*(parthf ? SKII2*TransTexCoord.y : SKII1)-0.3f);
    }
    comp = use_toon ? min(saturate(dot(IN.Normal,-LightDirection)*Toon),comp) : comp;
    ShadowColor.rgb *= use_toon ? MaterialToon : 1;
    
#if ENABLE_TOON
    // �g�D�[����
    comp = step(0.5, comp);
#endif
    
    float4 ans = lerp(ShadowColor, Color, comp);
    ans.a = transp ? 0.5f : ans.a;
    
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// return ans;�̒��O�ɒǉ�

    EYE_DRAW_PS_ANS

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
    
    return ans;
}


////////////////////////////////////////////////////////////////////////////////////////////////
// �e�N�j�b�N

technique MainTec < string MMDPass = "object"; > {
    pass DrawObject {
        VertexShader = compile vs_3_0 Basic_VS();
        PixelShader  = compile ps_3_0 Basic_PS();
    }
}

technique MainTecBS  < string MMDPass = "object_ss"; > {
    pass DrawObject {
        VertexShader = compile vs_3_0 BufferShadow_VS();
        PixelShader  = compile ps_3_0 BufferShadow_PS();
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////
