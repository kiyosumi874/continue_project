//----------------------------------------------------------------------------------//
// @file         PlayScene.h
// @brief        PlayScene�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"

enum class GAME_MODE_STATE : unsigned char
{
    FADE_IN,
    CAMERA_MOVE,
    WAIT,
    CIRCLE_GAME,
    GAUGE_GAME,
    PENDULUM_GAME,
    GAYA,
    FADE_OUT
};

class PlayScene : public SceneBase
{
public:
    PlayScene();    // �R���X�g���N�^
    PlayScene(float _deltaTime);    // �R���X�g���N�^
    ~PlayScene();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime, int& _hiScore)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound(float _deltaTime) override;    // ���y
    void       Load()                  override;    // ������

private:
    void GameModeFadeInBehavior(float _deltaTime);
    void GameModeCameraMoveBehavior(float _deltaTime);
    void GameModeWaitBehavior(float _deltaTime);
    void GameModeCircleGameBehavior(float _deltaTime);
    void GameModeGaugeGameBehavior(float _deltaTime);
    void GameModePendulumGameBehavior(float _deltaTime);
    void GameModeGayaBehavior(float _deltaTime);
    void GameModeFadeOutBehavior(float _deltaTime);

    void LoadEX(int& _tmp, short& _count, int _handle);

    GAME_MODE_STATE mGameMode;

    //class PlayCamera* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    //class BGM* mBGM2;
    class Audience* mAudience;       //�ϋq�ւ̃|�C���^
    //class Audience* mAudience2;       //�ϋq�ւ̃|�C���^
    class StaticObjectActor* mPool;
    class StaticObjectActor* mSky;
    class PlayerActor* mPlayer;
    class SE* mMetoronome;
    class SE* mClickNormal;
    class SE* mClickClitical;
    class SE* mKansei;
    class SE* mGayaGaya;
    class WaterObject* mWater;
    class Effect* mSmalleSplash;
    class Effect* mNormalSplash;
    class Effect* mBigSplash;
    class Effect* mFeather;
    VECTOR       mTargetPos;        //�J�����̌��Ă�����W

    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    float mDeltaTime;
    int   mScore;

    int mStopCount;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    int mFadeSpeed;

    bool mBGMFlag;
    bool mBGMFlag2;

    bool mFlag;
    bool mFlag2;
    bool mFlag3;

    int mGameWaitCount;

    float mJumpPower;

    int mFontHandle;
    int mHandle;
};
