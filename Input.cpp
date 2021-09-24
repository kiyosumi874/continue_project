#include "Input.h"
#include "DxLib.h"

/// <summary>
/// ENTER�L�[�̏�Ԃ𒲂ׂ�
/// </summary>
/// <returns>�������u��true��Ԃ�</returns>
bool Input::IsReturnPushDown()
{
    static bool keyFlag = false;
    if (CheckHitKey(KEY_INPUT_RETURN))
    {
        bool tmpFlag = keyFlag;
        keyFlag = true;
        return tmpFlag == false;
    }
    else
    {
        keyFlag = false;
    }
}
/// <summary>
/// ESC�L�[�̏�Ԃ𒲂ׂ�
/// </summary>
/// <returns>�������u��true��Ԃ�</returns>
bool Input::IsEscapePushDown()
{
    static bool keyFlag = false;
    if (CheckHitKey(KEY_INPUT_ESCAPE))
    {
        bool tmpFlag = keyFlag;
        keyFlag = true;
        return tmpFlag == false;
    }
    else
    {
        keyFlag = false;
    }
}
