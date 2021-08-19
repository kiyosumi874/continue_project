//----------------------------------------------------------------------------------//
// @file         ResultScene_kiyosumi.h
// @brief        ResultScene_kiyosumi�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/31    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_kiyosumi : public SceneBase
{
public:
     ResultScene_kiyosumi(int _score);    // �R���X�g���N�^
    ~ResultScene_kiyosumi();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class ResultCamera* mResultCamera;    // ���U���g�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class ResultUI*     mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;

    int mMoveSceneHandle;
    float mAlphaPal;
    bool mAlphaPalFlag;
    bool mCheckHitFlag;
};

