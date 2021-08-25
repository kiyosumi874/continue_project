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

class PlayScene : public SceneBase
{
public:
    PlayScene();    // �R���X�g���N�^
    ~PlayScene();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������

private:
    //class PlayCamera* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class Audience* mAudience;       //�ϋq�ւ̃|�C���^
    class Pool* mPool;           //�v�[���ւ̃|�C���^
    //class Player* mPlayer;            // �v���C���[�N���X�ւ̃|�C���^�����o�ϐ�
    class PlayerActor* mPlayer;
   
    VECTOR       mTargetPos;        //�v�[���̍��W

    float mDeltaTime;          // �f���^�^�C��
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    bool  mGameCountFlag3;     // �Ō�̃~�j�Q�[�����I��������ǂ�����Flag
    int   mScore;
    bool mPlayCircleGameFlag;
    bool mPlayGaugeGameFlag;
    bool mPlayPendulumGameFlag;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    int mFadeSpeed;

    bool mBGMFlag;
};
