//----------------------------------------------------------------------------------//
// @file         PlayUI.h
// @brief        PlayUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class PlayUI : public UIBase
{
public:
	PlayUI();    // �R���X�g���N�^
	~PlayUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

private:
	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
};