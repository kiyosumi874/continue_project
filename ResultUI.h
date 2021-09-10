//----------------------------------------------------------------------------------//
// @file         ResultUI.h
// @brief        ResultUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class ResultUI : public UIBase
{
public:
	ResultUI();    // �R���X�g���N�^
	~ResultUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Update(float _deltaTime, int& _hiScore);
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	void LoadScore(int _score);

private:
	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
	int   mScore;        // �X�R�A
	int   mHiScore;        // �X�R�A
	int mFontHandle;
	int mFontHandle2;
	int mFontHandle2ex;
	int mFontHandle3;
	int mFontHandle3ex;
	int mFontHandle4;
	int mFontHandle4ex;
};