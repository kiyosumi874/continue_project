#pragma once
#include "Actor.h"


class WaterObject : public Actor
{
public:

	WaterObject();
	~WaterObject();

	void UpdateActor(float _deltaTime) override;

	void UpdateWaterShader(float _deltaTime);

	void DrawWater();

private:


	int mNowTime, mOldTime;          // ���ݎ��ԁA�Â�����
	FLOAT4 mFGameTimes;              // ���Ԋi�[�E�V�F�[�_�\���M�pfloat(x4)�A���C


	int mDiffuseHandle;              // �f�B�t���[�Y�}�b�v
	int mNormalHandle;               // �m�[�}���}�b�v
	int mHeightHandle;               // �n�C�g�}�b�v (�����g�p)


	int mPsHandle;                   // �s�N�Z���V�F�[�_�[�n���h��
	int mVsHandle;                   // ���_�V�F�[�_�[�n���h��

};