#ifndef COMFY_ANIM_H
#define COMFY_ANIM_H

enum
{
    COMFY_ANIM_TYPE_NONE,
    COMFY_ANIM_TYPE_EASING,
    COMFY_ANIM_TYPE_SPRING,
};

// t represents progress of the animation, where 0 is the start of the animation and 1 is the end.
// The return value is a Q_24_8 fixed-point value.
typedef s32 (*ComfyAnimEasingFunc)(s32 t);

struct ComfyAnimEasingConfig
{
    u32 durationFrames;
    s32 from;
    s32 to;
    ComfyAnimEasingFunc easingFunc;
    u32 delayFrames;
};

struct ComfyAnimSpringConfig
{
    s32 from;
    s32 to;
    s32 tension;
    s32 friction;
    s32 mass;
    u32 clampAfter;
    u32 delayFrames;
};

struct ComfyAnimConfig
{
    u8 type;
    union
    {
        struct ComfyAnimEasingConfig easing;
        struct ComfyAnimSpringConfig spring;
    } data;
};

struct ComfyAnimEasingState
{
    u32 curFrame;
};

struct ComfyAnimSpringState
{
    u32 overshootCount;
};

struct ComfyAnim
{
    struct ComfyAnimConfig config;
    union
    {
        struct ComfyAnimEasingState easingState;
        struct ComfyAnimSpringState springState;
    } state;
    s32 position;
    s32 velocity;
    u32 delayFrames;
    bool32 completed;
    bool32 inUse;
};

#define NUM_COMFY_ANIMS     8
#define INVALID_COMFY_ANIM  NUM_COMFY_ANIMS
extern struct ComfyAnim gComfyAnims[NUM_COMFY_ANIMS];

#define COMFY_ANIM_SPRING_DEFAULT_MASS     Q_24_8(50)
#define COMFY_ANIM_SPRING_DEFAULT_TENSION  Q_24_8(175)
#define COMFY_ANIM_SPRING_DEFAULT_FRICTION Q_24_8(1000)

void TryAdvanceComfyAnim(struct ComfyAnim *anim);
void AdvanceComfyAnimations(void);
void InitComfyAnimConfig_Easing(struct ComfyAnimEasingConfig *config);
void InitComfyAnimConfig_Spring(struct ComfyAnimSpringConfig *config);
void InitComfyAnim_Easing(struct ComfyAnimEasingConfig *config, struct ComfyAnim *out);
void InitComfyAnim_Spring(struct ComfyAnimSpringConfig *config, struct ComfyAnim *out);
u32 CreateComfyAnim_Easing(struct ComfyAnimEasingConfig *config);
u32 CreateComfyAnim_Spring(struct ComfyAnimSpringConfig *config);
void ReleaseComfyAnim(u32 comfyAnimId);
void ReleaseComfyAnims(void);
int ReadComfyAnimValueSmooth(struct ComfyAnim *anim);
u32 GetEasingComfyAnim_CurrentFrame(struct ComfyAnim *anim);

s32 ComfyAnimEasing_Linear(s32 t);
s32 ComfyAnimEasing_EaseInQuad(s32 t);
s32 ComfyAnimEasing_EaseOutQuad(s32 t);
s32 ComfyAnimEasing_EaseInOutQuad(s32 t);
s32 ComfyAnimEasing_EaseInCubic(s32 t);
s32 ComfyAnimEasing_EaseOutCubic(s32 t);
s32 ComfyAnimEasing_EaseInOutCubic(s32 t);
s32 ComfyAnimEasing_EaseInOutBack(s32 t);

#endif // COMFY_ANIM_H
