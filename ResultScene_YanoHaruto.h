#pragma once
#include "SceneBase.h"

/// <summary>
/// 8/27�G�t�F�N�g�ǉ��@by���z��
/// </summary>
/// 
#define FIREWORKS 4
#define CONFETTIES  3
class ResultScene_YanoHaruto : public SceneBase
{
public:
    ResultScene_YanoHaruto(int _score);    // �R���X�g���N�^
    ~ResultScene_YanoHaruto();             // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class Camera*                      mCamera;
    class PlayerActor*                 mPlayer;
    class PlayEffect*                  mFireWork[FIREWORKS]; //�ԉ�
    class PlayEffect*                  mConfetti[CONFETTIES];//������
    class StaticObjectActor*           mPool;                //�v�[���̃|�C���^
    class ResultCamera*                mResultCamera;    // ���U���g�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class ResultUI*                    mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    class StaticObjectActor*           mStaticObjectActor;
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;
};
