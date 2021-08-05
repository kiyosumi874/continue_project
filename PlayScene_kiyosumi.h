//----------------------------------------------------------------------------------//
// @file         PlayScene_kiyosumi.h
// @brief        PlayScene_kiyosumi�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class PlayScene_kiyosumi : public SceneBase
{
public:
     PlayScene_kiyosumi();    // �R���X�g���N�^
    ~PlayScene_kiyosumi();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class PlayCamera* mPlayCamera;    // �v���C�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class PlayUI*         mPlayUI;    // �v���CUI�N���X�ւ̃|�C���^�����o�ϐ�
    float mDeltaTime;          // �f���^�^�C��
    bool  mInputReturnFlag;    // Enter�L�[�̘A�����͖h�~
    bool  mGameCountFlag3;     // �Ō�̃~�j�Q�[�����I��������ǂ�����Flag
    int   mScore;
};