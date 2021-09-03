#include "WaterObject.h"

// �I���I DxLib_Init()�̑O�ɂ����Y�ꂸ�� �� SetUseDirect3DVersion( DX_DIRECT3D_9EX );
WaterObject::WaterObject()
	:mNowTime(GetNowCount())
	,mOldTime(GetNowCount())
{
	mFGameTimes = { 0.0f, 0.0f, 0.0f, 0.0f };
	// ���f��(�L���[�u)
	mMHandle = MV1LoadModel("data/Shaders/Water.mv1");
	MV1SetPosition(mMHandle, VGet(0.0f, -6.5f, -55.0f));
	MV1SetScale(mMHandle, VGet(150.0f, 1.0f, 220.0f));

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

	// �e�N�X�`���ǂݍ���
	mDiffuseHandle = LoadGraph("data/Shaders/Water_DiffuseMap.png");
	mNormalHandle = LoadGraph("data/Shaders/Water_NormalMap.png");
	mHeightHandle = LoadGraph("data/Shaders/Water_HeightMap.png");


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

void WaterObject::ActivateWaterShader()
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
	mFGameTimes.x += (float)mNowTime / 12500.0f;
	//--------------------------------------------------------//
    // �J�����̎����x�N�g���ƃ��C�g�̕����x�N�g���̑��M
    //�J�����̈ʒu
	VECTOR C_Pos = GetCameraPosition();
	//�`�悷�郂�f���n���h���̃��[���h�ϊ��s��iModel_Handle������Ή�������̂ɂ���j
	MATRIX MatWorld = MV1GetLocalWorldMatrix(mMHandle);
	//�t�s��
	MATRIX InvMatWorld = MInverse(MatWorld);

	//�����x�N�g���i���[���h�����[�J���j
	C_Pos = VTransform(C_Pos, InvMatWorld);
	FLOAT4 cp = { C_Pos.x,C_Pos.y,C_Pos.z,1.0f };

	//���C�g�̕����x�N�g���i���[���h�����[�J���j
	VECTOR V_ld = GetLightDirection();
	V_ld = VTransformSR(V_ld, InvMatWorld);
	V_ld = VNorm(V_ld);
	FLOAT4 ld = { V_ld.x,V_ld.y,V_ld.z,1.0f };
	//--------------------------------------------------------//
	// �V�F�[�_�[�֏��𑗐M
	MV1SetUseOrigShader(TRUE);
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);
	// ���_�V�F�[�_�[
	SetVSConstF(0, mFGameTimes);
	SetVSConstF(43, cp);
	SetVSConstF(15, ld);
	// �s�N�Z���V�F�[�_�[
	SetPSConstF(0, mFGameTimes);
	SetUseTextureToShader(0, mDiffuseHandle);
	SetUseTextureToShader(1, mNormalHandle);
	SetUseTextureToShader(2, mHeightHandle);
	//SetPSConstSI(0, mDiffuseHandle);
	//SetPSConstSI(1, mNormalHandle);


	SetUsePixelShader(-1);                 // �s�N�Z���V�F�[�_�[�̊��蓖�ĉ���
	SetUseVertexShader(-1);                 // �s�N�Z���V�F�[�_�[�̊��蓖�ĉ���
	MV1SetUseOrigShader(FALSE);
}

void WaterObject::DrawWater()
{
	// �I���W�i���V�F�[�_�[�d�l�̗L����
	MV1SetUseOrigShader(TRUE);
	// �g�p����V�F�[�_�[�̃Z�b�g
	SetUseVertexShader(mVsHandle);
	SetUsePixelShader(mPsHandle);

	// �`��
	MV1DrawModel(mMHandle);

	// �I���W�i���V�F�[�_�[�̖�����
	MV1SetUseOrigShader(FALSE);
}
