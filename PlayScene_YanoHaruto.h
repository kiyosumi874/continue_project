//----------------------------------------------------------------------------------//
// @file         PlayScene_YanoHaruto.h
// @brief        PlayScene_YanoHaruto�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬 
// 8/30          �v���C�V�[������R�s�y->�v�[���ϋq�ǉ��B�C���N���[�h����audience.h�������Ɉړ�
//----------------------------------------------------------------------------------//

#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "Audience.h"


class PlayScene_YanoHaruto : public SceneBase
{
public:
    PlayScene_YanoHaruto();    // �R���X�g���N�^
    ~PlayScene_YanoHaruto();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������

private:
    //class PlayCamera* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class Camera* mCamera;
    class PlayUI* mPlayUI;    // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    class BGM* mBGM;
    class Audience* mAudience[AudienceLine][AudienceNum];       //�ϋq�ւ̃|�C���^
    class StaticObjectActor* mPool;           //�v�[���ւ̃|�C���^
    //class Player* mPlayer;            // �v���C���[�N���X�ւ̃|�C���^�����o�ϐ�
    class PlayerActor* mPlayer;

    VECTOR       mTargetPos;        //�v�[���̍��W
    VECTOR       mAudiencePos;      //�ϋq�̏ꏊ

    int   mAudienceHighestJumpLine; //�ϋq�̃W�����v�̍ō����x
    int   mAudienceGroundHeight;    //�ϋq�̗��n�ʂ̍��x
    float mAudienceJumpPower;       //�ϋq�̃W�����v��
    bool  mAudienceDownFlag;        //�ϋq�̗����t���O
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
;
