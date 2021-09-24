//----------------------------------------------------------------------------------//
// @file         TitleUI.h
// @brief        TitleUI�N���X
// @note         �p����:UIBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "UIBase.h"

class TitleUI : public UIBase
{
public:
	 TitleUI();    // �R���X�g���N�^
	~TitleUI();    // �f�X�g���N�^

	void Update(float _deltaTime)override;    // �X�V
	void Load()                  override;    // ���[�h
	void Draw()                  override;    // �`��

	// �X�^�[�g�{�^���̃t���O�̃Q�b�^�[
	const bool& GetStartButtonFlag() const { return mStartButtonFlag; }
private:
	float mDeltaTime;    // �f���^�^�C��
	int   mHandle;       // �n���h���i�[�ϐ�
	int mSizeX;
	int mSizeY;
	int   mHandle2;       // �n���h���i�[�ϐ�
	int mSize2X;
	int mSize2Y;
	int   mHandle3;       // �n���h���i�[�ϐ�
	double mAlphaPal;
	double mAlphaCount;

	// �X�^�[�g�{�^���̈ʒu�����߂�ϐ�
	int mStartButtonBeginX;    // �����X
	int mStartButtonBeginY;    // �����Y
	int mStartButtonEndX;      // �E����X
	int mStartButtonEndY;	   // �E����Y
	// �X�^�[�g�{�^���̃t�H���g�T�C�Y
	int mStartButtonFontSize;
	// �X�^�[�g�{�^���̃t���O
	bool mStartButtonFlag;

	bool mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~

	int mFontHandle;

	float mTmpTime;
	bool mTmpTimeFlag;

};