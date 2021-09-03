//----------------------------------------------------------------------------------//
// @file         TitleScene_YanoHaruto.h
// @brief        TitleScene_YanoHaruto�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬 8/30 ���@�^�C�g���V�[������
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"
extern const float FIRST_DELTA_TIME;
extern const char* MOVE_SCENE_IMG;
extern const char* PLAYER_MODEL_HANDLE;
extern const char* SOUND_CLICK_HANDLE;

class TitleScene_YanoHaruto : public SceneBase
{
public:

    TitleScene_YanoHaruto();    // �R���X�g���N�^
    ~TitleScene_YanoHaruto();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������

private:
    class Camera* mCamera;
    class TitleUI* mTitleUI;    // �^�C�g��UI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class SE* mClickNormal;
    class PlayerActor* mPlayer;
    float mDeltaTime;          // �f���^�^�C��
    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    bool mClickNormalFlag;
    // �X�^�[�g�{�^���̃t���O
    bool mStartButtonFlag;

    // �X�^�[�g�{�^�����������Ƃ��̃��O�����Count
    float mSceneTransitionCount;


    int mMoveSceneHandle;
    int mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;

};
