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

extern const float FIRST_DELTA_TIME;
extern const char* MOVE_SCENE_IMG;
extern const char* PLAYER_MODEL_HANDLE;
extern const char* SOUND_CLICK_HANDLE;

class TitleScene : public SceneBase
{
public:

    TitleScene();    // �R���X�g���N�^
    ~TitleScene();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound(float _deltaTime)                 override;    // ���y
    void       Load()                  override;    // ������

private:
    class Camera* mCamera;
    class TitleUI* mTitleUI;    // �^�C�g��UI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class SE* mClickNormal;
    class PlayerActor* mPlayer;
    class StaticObjectActor* mSky;
    class StaticObjectActor* mPool;
    class AudienceContoroller* mAudience;       //�ϋq�ւ̃|�C���^
    //class Audience* mAudience2;       //�ϋq�ւ̃|�C���^
    class WaterObject* mWater;

    enum class CAMERA_TYPE : unsigned char
    {
        CAMERA_1,
        CAMERA_2,
        CAMERA_3
    };
    CAMERA_TYPE mCameraType;

    bool mBGMFlag;
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    bool mClickNormalFlag;
    // �X�^�[�g�{�^���̃t���O
    bool mStartButtonFlag;

    // �X�^�[�g�{�^�����������Ƃ��̃��O�����Count
    float mSceneTransitionCount;


    int mMoveSceneHandle;
    int mLightHandle;
    int mLightHandle2;
    int mLightHandle3;
    int mLightHandle4;
    int mAlphaPal;
    bool mAlphaPalFlag;

    int mFadeSpeed;
    int mGridHandle;

};

