//----------------------------------------------------------------------------------//
// @file         PlayScene_kiyosumi.h
// @brief        PlayScene_kiyosumi�N���X
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
    FADE_OUT
};

class PlayScene_kiyosumi : public SceneBase
{
public:
    PlayScene_kiyosumi();    // �R���X�g���N�^
    ~PlayScene_kiyosumi();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
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
    void GameModeFadeOutBehavior(float _deltaTime);

    GAME_MODE_STATE mGameMode;

    //class PlayCamera* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class Audience* mAudience;       //�ϋq�ւ̃|�C���^
    class StaticObjectActor* mPool;
    class PlayerActor* mPlayer;
    class SE* mMetoronome;
    class SE* mClickNormal;
    class SE* mClickClitical;

    VECTOR       mTargetPos;        //�J�����̌��Ă�����W

    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~

    int   mScore;

    int mStopCount;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    int mFadeSpeed;

    bool mBGMFlag;

    int mGameWaitCount;

    float mJumpPower;
};
