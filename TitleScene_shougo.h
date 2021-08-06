//----------------------------------------------------------------------------------//
// @file         TitleScene_shougo.h
// @brief        TitleScene_shougo�N���X
// @note         �p����:SceneBase�N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/5    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class TitleScene_shougo : public SceneBase
{
public:

    TitleScene_shougo();    // �R���X�g���N�^
    ~TitleScene_shougo();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������

private:
    class TitleCamera* mTitleCamera;    // �^�C�g���J�����N���X�ւ̃|�C���^�����o�ϐ�
    class TitleUI* mTitleUI;    // �^�C�g��UI�N���X�ւ̃|�C���^�����o�ϐ�
    float mDeltaTime;          // �f���^�^�C��
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    // �X�^�[�g�{�^���̃t���O
    bool mStartButtonFlag;

    // �X�^�[�g�{�^�����������Ƃ��̃��O�����Count
    float mSceneTransitionCount;

    // �L�����\���f�o�b�O�p
    int mHandle;
    float mRotate;
};
