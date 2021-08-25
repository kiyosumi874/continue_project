#include "DxLib.h"
#include "Actor.h"
/// <summary>
/// ‰Šú‰»
/// </summary>
Actor::Actor()
    : mState(State::Active)
    , mPosition(VGet(0.0f, 0.0f, 0.0f))
    , mRotate  (VGet(0.0f, 0.0f, 0.0f))
    , mScale(VGet(1.0f, 1.0f, 1.0f))
{
}
/// <summary>
/// Œãˆ—
/// </summary>
Actor::~Actor()
{
    // ˆ—‚È‚µ
}
