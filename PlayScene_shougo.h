//----------------------------------------------------------------------------------//
// @file         PlayScene_shougo.h
// @brief        PlayScene_shougo�N���X
// @note         �p����:SceneBase�N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class PlayScene_shougo : public SceneBase
{
public:
    PlayScene_shougo();    // �R���X�g���N�^
    ~PlayScene_shougo();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class PlayCamera_shougo* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class PlayUI* mPlayUI;                   // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    class Object_shougo* mObject;            // �I�u�W�F�N�g�N���X�ւ̃|�C���^�����o�ϐ�
    class Player* mPlayer;            // �v���C���[�N���X�ւ̃|�C���^�����o�ϐ�
    float mDeltaTime;                        // �f���^�^�C��
    bool  mInputReturnFlag;                  // Enter�L�[�̘A�����͖h�~
    bool  mGameCountFlag3;                   // �Ō�̃~�j�Q�[�����I��������ǂ�����Flag
    int   mScore;

};
