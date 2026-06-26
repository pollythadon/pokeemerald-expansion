#include "global.h"
#include "comfy_anim.h"
#include "math_util.h"

EWRAM_DATA struct ComfyAnim gComfyAnims[NUM_COMFY_ANIMS] = {0};

static void AdvanceComfyAnim_Easing(struct ComfyAnim *anim)
{
    s32 t, x, prevPosition;
    struct ComfyAnimEasingConfig *config = &anim->config.data.easing;

    anim->state.easingState.curFrame++;

    // Determine progress of animation, normalized to (0, 1].
    t = MathUtil_Div32(Q_24_8(anim->state.easingState.curFrame), Q_24_8(config->durationFrames));

    // Early exit if we know we're at the end of the animation.
    if (t == Q_24_8(1))
    {
        anim->position = config->to;
        anim->completed = TRUE;
        return;
    }

    x = config->easingFunc(t);
    prevPosition = anim->position;
    anim->position = config->from + MathUtil_Mul32(x, config->to - config->from);
    anim->velocity = anim->position - prevPosition;

    if (anim->state.easingState.curFrame >= config->durationFrames)
        anim->completed = TRUE;
}

// These values intentionally complete spring animations before imperceptible sub-pixel oscillations linger.
#define SPRING_POSITION_PRECISION     0x10
#define STATIONARY_VELOCITY_THRESHOLD 0x10

static void AdvanceComfyAnim_Spring(struct ComfyAnim *anim)
{
    s32 springForce, dampingForce, acceleration, prevPosition;
    s32 prevPositionSign, curPositionSign;
    struct ComfyAnimSpringConfig *config = &anim->config.data.spring;

    if (abs(anim->velocity) < STATIONARY_VELOCITY_THRESHOLD && abs(config->to - anim->position) < SPRING_POSITION_PRECISION)
    {
        anim->position = config->to;
        anim->completed = TRUE;
        return;
    }

    if (anim->delayFrames > 0)
    {
        anim->delayFrames--;
        return;
    }

    springForce = -1 * MathUtil_Mul32(MathUtil_Mul32(config->tension, 0x5), anim->position - config->to);
    dampingForce = -1 * MathUtil_Mul32(MathUtil_Mul32(config->friction, 0x5), anim->velocity);
    acceleration = MathUtil_Div32(springForce + dampingForce, config->mass);
    anim->velocity += acceleration;
    prevPosition = anim->position;
    anim->position += anim->velocity;

    if (config->clampAfter > 0)
    {
        prevPositionSign = prevPosition - config->to > 0;
        curPositionSign = anim->position - config->to > 0;
        if (prevPositionSign != curPositionSign)
        {
            anim->state.springState.overshootCount++;
            if (anim->state.springState.overshootCount >= config->clampAfter)
            {
                anim->position = config->to;
                anim->completed = TRUE;
                return;
            }
        }
    }
}

void TryAdvanceComfyAnim(struct ComfyAnim *anim)
{
    switch (anim->config.type)
    {
    case COMFY_ANIM_TYPE_EASING:
        if (!anim->completed)
            AdvanceComfyAnim_Easing(anim);
        break;
    case COMFY_ANIM_TYPE_SPRING:
        AdvanceComfyAnim_Spring(anim);
        break;
    }
}

void AdvanceComfyAnimations(void)
{
    int i;

    for (i = 0; i < NUM_COMFY_ANIMS; i++)
    {
        if (gComfyAnims[i].inUse)
            TryAdvanceComfyAnim(&gComfyAnims[i]);
    }
}

static u32 GetAvailableComfyAnim(void)
{
    int i;

    for (i = 0; i < NUM_COMFY_ANIMS; i++)
    {
        if (!gComfyAnims[i].inUse)
            return i;
    }

    return INVALID_COMFY_ANIM;
}

void InitComfyAnimConfig_Easing(struct ComfyAnimEasingConfig *config)
{
    memset(config, 0, sizeof(*config));
    config->easingFunc = ComfyAnimEasing_Linear;
}

void InitComfyAnimConfig_Spring(struct ComfyAnimSpringConfig *config)
{
    memset(config, 0, sizeof(*config));
    config->mass = COMFY_ANIM_SPRING_DEFAULT_MASS;
    config->tension = COMFY_ANIM_SPRING_DEFAULT_TENSION;
    config->friction = COMFY_ANIM_SPRING_DEFAULT_FRICTION;
}

void InitComfyAnim_Easing(struct ComfyAnimEasingConfig *config, struct ComfyAnim *out)
{
    out->inUse = TRUE;
    out->completed = FALSE;
    out->velocity = 0;
    out->delayFrames = config->delayFrames;
    out->position = config->from;
    out->config.type = COMFY_ANIM_TYPE_EASING;
    out->config.data.easing = *config;
    out->state.easingState.curFrame = 0;
}

u32 CreateComfyAnim_Easing(struct ComfyAnimEasingConfig *config)
{
    u32 i = GetAvailableComfyAnim();

    if (i == INVALID_COMFY_ANIM)
        return i;

    InitComfyAnim_Easing(config, &gComfyAnims[i]);
    return i;
}

void InitComfyAnim_Spring(struct ComfyAnimSpringConfig *config, struct ComfyAnim *out)
{
    out->inUse = TRUE;
    out->completed = FALSE;
    out->velocity = 0;
    out->delayFrames = config->delayFrames;
    out->position = config->from;
    out->config.type = COMFY_ANIM_TYPE_SPRING;
    out->config.data.spring = *config;
    out->state.springState.overshootCount = 0;
}

u32 CreateComfyAnim_Spring(struct ComfyAnimSpringConfig *config)
{
    u32 i = GetAvailableComfyAnim();

    if (i == INVALID_COMFY_ANIM)
        return i;

    InitComfyAnim_Spring(config, &gComfyAnims[i]);
    return i;
}

void ReleaseComfyAnim(u32 comfyAnimId)
{
    if (comfyAnimId < NUM_COMFY_ANIMS)
        gComfyAnims[comfyAnimId].inUse = FALSE;
}

void ReleaseComfyAnims(void)
{
    int i;

    for (i = 0; i < NUM_COMFY_ANIMS; i++)
        ReleaseComfyAnim(i);
}

int ReadComfyAnimValueSmooth(struct ComfyAnim *anim)
{
    return Q_24_8_TO_INT(anim->position + 0x80);
}

u32 GetEasingComfyAnim_CurrentFrame(struct ComfyAnim *anim)
{
    switch (anim->config.type)
    {
    default:
        return 0;
    case COMFY_ANIM_TYPE_EASING:
        return anim->state.easingState.curFrame;
    }
}

// Easing functions borrowed from easings.net library
// https://github.com/ai/easings.net/blob/master/src/easings/easingsFunctions.ts

s32 ComfyAnimEasing_Linear(s32 t)
{
    return t;
}

s32 ComfyAnimEasing_EaseInQuad(s32 t)
{
    return MathUtil_Mul32(t, t);
}

s32 ComfyAnimEasing_EaseOutQuad(s32 t)
{
    s32 v = Q_24_8(1) - t;
    return Q_24_8(1) - MathUtil_Mul32(v, v);
}

s32 ComfyAnimEasing_EaseInOutQuad(s32 t)
{
    if (t < (Q_24_8(1) >> 1))
        return 2 * MathUtil_Mul32(t, t);
    else
    {
        s32 v = -2 * t + Q_24_8(2);
        return Q_24_8(1) - (MathUtil_Mul32(v, v) >> 1);
    }
}

s32 ComfyAnimEasing_EaseInCubic(s32 t)
{
    return MathUtil_Mul32(t, MathUtil_Mul32(t, t));
}

s32 ComfyAnimEasing_EaseOutCubic(s32 t)
{
    s32 v = Q_24_8(1) - t;
    return Q_24_8(1) - MathUtil_Mul32(v, MathUtil_Mul32(v, v));
}

s32 ComfyAnimEasing_EaseInOutCubic(s32 t)
{
    if (t < (Q_24_8(1) >> 1))
        return 4 * MathUtil_Mul32(t, MathUtil_Mul32(t, t));
    else
    {
        s32 v = -2 * t + Q_24_8(2);
        return Q_24_8(1) - (MathUtil_Mul32(v, MathUtil_Mul32(v, v)) >> 1);
    }
}

s32 ComfyAnimEasing_EaseInOutBack(s32 t)
{
    s32 c1 = 0x298; // Q_24_8 representation of 1.70158 * 1.525

    if (t < (Q_24_8(1) >> 1))
    {
        s32 v1 = 2 * t;
        s32 a = MathUtil_Mul32(v1, v1);
        s32 b = MathUtil_Mul32(2 * (c1 + Q_24_8(1)), t) - c1;
        return MathUtil_Mul32(a, b) >> 1;
    }
    else
    {
        s32 v1 = 2 * t - Q_24_8(2);
        s32 a = MathUtil_Mul32(v1, v1);
        s32 b = MathUtil_Mul32(c1 + Q_24_8(1), v1) + c1;
        return (MathUtil_Mul32(a, b) + Q_24_8(2)) >> 1;
    }
}
