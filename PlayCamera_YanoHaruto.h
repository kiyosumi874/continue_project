#pragma once
#include "CameraBase.h"
#include "Pool.h"
class PlayCamera_YanoHaruto : public CameraBase
{
	Pool* mPool;
public:
	PlayCamera_YanoHaruto();    // �R���X�g���N�^
	~PlayCamera_YanoHaruto();    // �f�X�g���N�^

	void Update()                override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��
	VECTOR mSetTargetPos(const VECTOR& _Pos) {return mCameraTarget = _Pos; };
private:
	VECTOR mCameraPosition;    // �J�����̈ʒu
	VECTOR mCameraTarget;      // �J�����̒����_( ���Ă�����W )
	VECTOR mCameraUp;          // �J�����̏����
};