#pragma once
#include"Dxlib.h"
class Pool
{
public:
	Pool();
	~Pool();
	void Init();
	void Update();
	void Draw();
	const VECTOR& mGetPoolPos()const { return mPos; };
private:
	VECTOR mPos;	 //�v�[���̍��W
	VECTOR mRote;	 //�v�[���̊p�x
	int mModelHandle;//�v�[���̃��f��
};