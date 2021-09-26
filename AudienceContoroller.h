#pragma once
/// <summary>
/// �ϋq�̐���ϋq���m�̋����A�W�����v����^�C�~���O�����߂�N���X
///�@9�E11���z��
/// </summary>
#include "DxLib.h"
#include <iostream>
#include <vector>
#include "SceneBase.h"

using namespace std;
class AudienceContoroller
{
	const static int AUDIENCE_LINES = 5;//�ϋq�̗�
	const static int AUDIENCE_EVERY_LINE = 14;//�񂲂Ƃ̊ϋq
	vector<class NewAudience*> Audiences;
	vector<class NewAudience*> Audiences2;
public:
	AudienceContoroller();
	~AudienceContoroller();
	void SetAudience();
	void SetAudienceState(int _state);        //�W�����v����������Ȃ�1
	void LoadAudience();
	void Draw();
	void Update(float _deltaTime);
private:
	float mAudienceBetweenX;								  //�ϋq���m�̋���
	float mAudienceBetweenZ;								  //�ϋq���m�̋���
	float mHeightStairs;									  //�K�i�̍�
	VECTOR mPosition;		          						  //�ϋq�̍��W
	VECTOR mScale;
	VECTOR mRotate;
	float mFirstAudiencePositionX;                            //�ϋq�̏���X�ʒu
	float mFirstAudiencePositionX2;                            //�ϋq�̏���X�ʒu
	float mFirstAudiencePositionZ;                            //�ϋq�̏���Z�ʒu
	float mFirstAudiencePositionZ2;                            //�ϋq�̏���Z�ʒu
	float mGroundHeight;										  //�ϋq�̗����Ă���ꏊ
	float mFirstGroundHeight;
	float mHighestJump;										  //�ϋq�̍ō��W�����v���x

	float mRad; //light�p�x���W�A��	
	float mRad2;

	int  mLight;
};