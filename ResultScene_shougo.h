//----------------------------------------------------------------------------------//
// @file         ResultScene_shougo.h
// @brief        ResultScene_shougo�N���X
// @note         �p����:SceneBase�N���X              
// @author       ��� �Č� (shougo iguchi, @2021)
// @changelog
// 2021/ 8/2     �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_shougo : public SceneBase
{
public:
    ResultScene_shougo(int _score);    // �R���X�g���N�^
    ~ResultScene_shougo();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    class ResultCamera_shougo* mResultCamera;    // ���U���g�J�����N���X�ւ̃|�C���^�����o�ϐ�
    class ResultUI* mResultUI;        // ���U���gUI�N���X�ւ̃|�C���^�����o�ϐ�
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
    int mScore;
};


