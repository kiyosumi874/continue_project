#include "Input.h"
#include "DxLib.h"

/// <summary>
/// ENTERキーの状態を調べる
/// </summary>
/// <returns>押した瞬間trueを返す</returns>
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
/// ESCキーの状態を調べる
/// </summary>
/// <returns>押した瞬間trueを返す</returns>
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
