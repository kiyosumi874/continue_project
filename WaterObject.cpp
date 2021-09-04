#include "WaterObject.h"

//----------------------------------------------------------------------------------------------//
//
// �I���I DxLib_Init()�̑O�ɂ����Y�ꂸ�� �� SetUseDirect3DVersion( DX_DIRECT3D_9EX );
//
//---------------------------------------------------------------------------------------------//
WaterObject::WaterObject()
	:mNowTime(GetNowCount())
	,mOldTime(GetNowCount())
{
	mFGameTimes = { 0.0f, 0.0f, 0.0f, 0.0f };

	// ���f���ǂݍ���
	mMHandle = MV1LoadModel("data/Shaders/Water.mv1");

	// �e�V�F�[�_�[�̓ǂݍ���
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

	// �}�e���A���ǂݍ���
	mDiffuseHandle = LoadGraph("data/Shaders/Water_002_COLOR.jpg");
	mNormalHandle = LoadGraph("data/Shaders/Water_002_NORM.jpg");
	mHeightHandle = LoadGraph("data/Shaders/Water_002_ROUGH.jpg");

}

WaterObject::~WaterObject()
{
	// �V�F�[�_�[�̍폜
	DeleteShader(mPsHandle);
	DeleteShader(mVsHandle);

	// �e��e�N�X�`���폜
	DeleteGraph(mDiffuseHandle);
	DeleteGraph(mNormalHandle);
	DeleteGraph(mHeightHandle);
}

void WaterObject::UpdateActor(float _deltaTime)
{
}

/// <summary>
/// ���ʗp�V�F�[�_�[�p�̏��X�V�Ƒ��M����
/// </summary>
/// <param name="_deltaTime"> �g���Z�o�̎��Ɏg�p���� </param>
void WaterObject::UpdateWaterShader(float _deltaTime)
{
	//---------------------------------------------------------//
	// ���Ԑ���
	int Time;
	// ���݂̎��Ԃ𓾂�
	Time = GetNowCount();
	// ���t���[���Ōo�߂������Ԃ𓾂�
	mNowTime = Time - mOldTime;
	// ���݂̎��Ԃ�ۑ�
	mOldTime = Time;
	mFGameTimes.x += (float)mNowTime / 250.0f * _deltaTime;
	//--------------------------------------------------------//
    // �J�����̎����x�N�g���ƃ��C�g�̕����x�N�g���̑��M
    //�J�����̈ʒu
	VECTOR C_Pos = GetCameraPosition();
	//�`�悷�郂�f���n���h���̃��[���h�ϊ��s��iModel_Handle������Ή�������̂ɂ���j
	MATRIX WorldMat = MV1GetLocalWorldMatrix(mMHandle);
	//�t�s��
	MATRIX InvWorldMat = MInverse(WorldMat);

	//�����x�N�g���i���[���h�����[�J���j
	C_Pos = VTransform(C_Pos, InvWorldMat);
	FLOAT4 cp = { C_Pos.x,C_Pos.y,C_Pos.z,1.0f };

	//���C�g�̕����x�N�g���i���[���h�����[�J���j
	VECTOR V_ld = GetLightDirection();
	V_ld = VTransformSR(V_ld, InvWorldMat);
	V_ld = VNorm(V_ld);
	FLOAT4 ld = { V_ld.x,V_ld.y,V_ld.z,1.0f };
	//--------------------------------------------------------//
	// �V�F�[�_�[�֏��𑗐M
	// �V�F�[�_�[�L����
	MV1SetUseOrigShader(TRUE);
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);
	//---------------------------------------------------------//
	// ���_�V�F�[�_�[
	//--------------------------------------------------------//
	SetVSConstF(0, mFGameTimes);
	SetVSConstF(43, cp);
	SetVSConstF(15, ld);
	//--------------------------------------------------------//
	// �s�N�Z���V�F�[�_�[
	//-------------------------------------------------------//
	// �g����p
	SetPSConstF(0, mFGameTimes);
	// �}�e���A��
	SetUseTextureToShader(0, mDiffuseHandle);
	SetUseTextureToShader(1, mNormalHandle);
	// �G�~�b�V�u�J���[
	FLOAT4 emissiveColor = { 0.1f, 0.1f, 0.1f, 1.2f };
	SetPSConstF(1, emissiveColor);
	// �������             r     g     b     a = �����x
	FLOAT4 factorColor = { 0.0f, 0.0f, 0.0f, 0.95f };
	SetPSConstF(5, factorColor);

	// �V�F�[�_�[�̖�����
	MV1SetUseOrigShader(FALSE);
}

/// <summary>
/// ���ʃV�F�[�_�[�ŗL�̕`�揈��
/// </summary>
void WaterObject::DrawWater()
{
	// �I���W�i���V�F�[�_�[�d�l�̗L����
	MV1SetUseOrigShader(TRUE);
	// �g�p����V�F�[�_�[�̃Z�b�g
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);

	// �`��
	// �^�C����ɐݒu(���i�K�ł͔񐄏�)
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//MV1SetPosition(mMHandle, VGet((-35.0f) + 8.0f * j, -6.5f, (-12.0f) + -9.0f * i));
			//MV1DrawModel(mMHandle);
		}
	}

	// �����
	MV1DrawModel(mMHandle);

	// �I���W�i���V�F�[�_�[�̖�����
	MV1SetUseOrigShader(FALSE);
}
