//----------------------------------------------------------------------------------//
// @file         Object_shougo.h
// @brief        Object_shougo�N���X
// @note                       
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/7     �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once

class Object_shougo
{
public:
	 Object_shougo();    // �R���X�g���N�^
	~Object_shougo();    // �f�X�g���N�^

	void Update(float _deltaTime);    // �X�V
	void Draw()                  ;    // �`��
	void Load()                  ;    // ������

private:
	float mDeltaTime;    // �f���^�^�C��

	// ���f���\��
	int mModelHandle;

};