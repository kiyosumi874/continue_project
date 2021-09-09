//----------------------------------------------------------------------------------//
// @file         TitleScene_kiyosumi.h
// @brief        TitleScene_kiyosumi�N���X
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

class TitleScene_kiyosumi : public SceneBase
{
public:

    TitleScene_kiyosumi();    // �R���X�g���N�^
    ~TitleScene_kiyosumi();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
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
    class Audience* mAudience;       //�ϋq�ւ̃|�C���^

    typedef struct MoveCircle
    {
        float mPosX;
        float mPosY;
        float mPosZ;
        float mCenterX;
        float mCenterY;
        float mCenterZ;
        float mAngle;
        float mLength;
    };

    enum class CAMERA_TYPE : unsigned char
    {
        CAMERA_1,
        CAMERA_2,
        CAMERA_3
    };
    MoveCircle mMoveCircle;
    CAMERA_TYPE mCameraType;

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

