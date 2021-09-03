#pragma once
#include "Actor.h"


class WaterObject : public Actor
{
public:

	WaterObject();
	~WaterObject();


	void UpdateActor(float _deltaTime) override;


	void ActivateWaterShader();

	void DrawWater();

private:

	int mNowTime, mOldTime;          // ���ݎ��ԁA�Â�����
	FLOAT4 mFGameTimes;              // ���Ԋi�[�p


	int mDiffuseHandle;              // �f�B�t���[�Y�}�b�v
	int mNormalHandle;               // �m�[�}���}�b�v
	int mHeightHandle;               // �n�C�g�}�b�v


	int mPsHandle;                   // �s�N�Z���V�F�[�_�[�n���h��
	int mVsHandle;                   // ���_�V�F�[�_�[�n���h��

};