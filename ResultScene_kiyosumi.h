//----------------------------------------------------------------------------------//
// @file         ResultScene_kiyosumi.h
// @brief        ResultScene_kiyosumi�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
// 2021/ 8/25    camera��player�̃N���X��ǉ�
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_kiyosumi : public SceneBase
{
public:
    ResultScene_kiyosumi(int _score);    // �R���X�g���N�^
    ~ResultScene_kiyosumi();    // �f�X�g���N�^

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
    class StaticObjectActor* mSky;
    class Effect* mFireWorks;

    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

};

