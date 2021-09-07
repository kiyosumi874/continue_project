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
    ~ResultScene_YanoHaruto();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound(float _deltaTime)                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class ResultCamera* mResultCamera;    // ���U���g�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class ResultUI* mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    class PlayerActor* mPlayer;
    class StaticObjectActor* mPodium;
    class StaticObjectActor* mPool;
    class Effect* mFireWorks;

    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

};

