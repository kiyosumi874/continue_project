//----------------------------------------------------------------------------------//
// @file         ResultScene.h
// @brief        ResultScene�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
// 2021/ 8/25    camera��player�̃N���X��ǉ�
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene : public SceneBase
{
public:
    ResultScene(int _score);    // �R���X�g���N�^
    ~ResultScene();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class ResultCamera* mResultCamera;    // ���U���g�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class ResultUI* mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    class PlayerActor* mPlayer;
    class StaticObjectActor* mStaticObjectActor;
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

};

