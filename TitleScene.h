//----------------------------------------------------------------------------------//
// @file         TitleScene.h
// @brief        TitleScene�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:

    TitleScene();    // �R���X�g���N�^
    ~TitleScene();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������

private:
    class TitleCamera* mTitleCamera;    // �^�C�g���J�����N���X�ւ̃|�C���^�����o�ϐ�
    class TitleUI* mTitleUI;    // �^�C�g��UI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class SE* mClickNormal;
    float mDeltaTime;          // �f���^�^�C��
    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    bool mClickNormalFlag;
    // �X�^�[�g�{�^���̃t���O
    bool mStartButtonFlag;

    // �X�^�[�g�{�^�����������Ƃ��̃��O�����Count
    float mSceneTransitionCount;

    // �L�����\���f�o�b�O�p
    int mHandle;
    int mAttachIndex;
    float mTotalTime;
    float mPlayTime;
    float x, z;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;

};

