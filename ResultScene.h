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

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound(float _deltaTime)                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class Camera* mCamera;
    class ResultUI* mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    class PlayerActor* mPlayer;
    class AudienceContoroller* mAudience;
    class StaticObjectActor* mPodium;
    class StaticObjectActor* mPool;
    class StaticObjectActor* mSky;
    class Effect* mFireWorks;
    class Effect* mConfetti;     //������
    class WaterObject* mWater;

    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;

    int mFadeSpeed;

    float mCameraPosX;
    float mCameraPosY;
    float mCameraPosZ;
    float mCameraTargetPosX;
    float mCameraTargetPosY;
    float mCameraTargetPosZ;

    VECTOR mFireWorksPos;
    VECTOR mConfettiPos;
    VECTOR mFirstPlace;
    VECTOR mSecondPlace;
    VECTOR mThirdPlace;

};

