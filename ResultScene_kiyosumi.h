//----------------------------------------------------------------------------------//
// @file         ResultScene_kiyosumi.h
// @brief        ResultScene_kiyosumi�N���X
// @note         �p����:SceneBase�N���X              
// @author       �Ō� ���� (Kiyosumi Shiihara, @2021)
// @changelog
// 2021/ 7/29    �V�K�쐬
//----------------------------------------------------------------------------------//

#pragma once
#include "SceneBase.h"

class ResultScene_kiyosumi : public SceneBase
{
public:
    ResultScene_kiyosumi();    // �R���X�g���N�^
    ~ResultScene_kiyosumi();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
};

