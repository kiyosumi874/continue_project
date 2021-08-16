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
	VECTOR mPos;	 //プールの座標
	VECTOR mRote;	 //プールの角度
	int mModelHandle;//プールのモデル
};