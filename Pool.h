//-------------------------------------------+
//8/30 ����by���
//-------------------------------------------+

#pragma once
#include"Dxlib.h"
#include"StaticObjectActor.h"
class Pool
{
public:
	/*Pool();
	~Pool();*/
//	void Delete() { MV1DeleteModel(mModelHandle); }													 //���f���f�[�^�̏���
//	void Draw() { MV1DrawModel(mModelHandle); }                                                      //�`�揈��
//	const VECTOR& mGetPoolPos()const { return mPos; }												 //�ʒu��Ԃ�
//	void Load();
//	//��]�l�̒P�ʂ̓��W�A���ł��̂ŁA�x���P�ʂ̒l��������ꍇ�́@�x * DX_PI_F / 180.0f�@�̌v�Z�����Ă�������
//	void Rotate(const VECTOR in_rotate) { MV1SetRotationXYZ(mModelHandle,in_rotate); }	             //��]�@�@
//	void ScaleControle(const VECTOR in_scale) { MV1SetScale(mModelHandle, in_scale); }	             //�g��k��
//	void SetPos(const VECTOR in_pos) 																 //�ʒu�ύX
//	{
//		MV1SetPosition(mModelHandle, in_pos); 
//		mPos = in_pos;
//	}						                                                                         
//
//private:
//	//VECTOR mPos;      //pool�̂ق��ɃJ�������������߂�vector
//	int mModelHandle; //�v�[���̃��f��
};