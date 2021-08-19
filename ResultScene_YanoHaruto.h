#pragma once
#pragma once
#include "SceneBase.h"

class ResultScene_YanoHaruto : public SceneBase
{
public:
    ResultScene_YanoHaruto();    // �R���X�g���N�^
    ~ResultScene_YanoHaruto();    // �f�X�g���N�^

    SceneBase* Update(float _deltaTime)override;    // �X�V
    void       Draw()                  override;    // �`��
    void       Sound()                 override;    // ���y
    void       Load()                  override;    // ������
private:
    float mDeltaTime;         // �f���^�^�C��
    bool  mInputReturnFlag;   // Enter�L�[�̘A�����͖h�~
};

