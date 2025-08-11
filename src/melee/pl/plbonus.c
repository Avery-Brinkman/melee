#include "plbonus.h"

#include "inlines.h"
#include "pl_040D.h"
#include "plattack.h"
#include "player.h"
#include "plbonusinline.h"
#include "plstale.h"
#include "pltrick.h"
#include "types.h"

#include <placeholder.h>
#include <platform.h>

#include <baselib/debug.h>
#include <gm/gm_unsplit.h>

static inline void setKindToOne_inline(int player, int kind)
{
    pl_StaleMoveTableExt_t* table = Player_GetStaleMoveTableIndexPtr2(player);
    HSD_ASSERTMSG(56, player != 6, "player != Gm_Player_Other");
    HSD_ASSERTMSG(57, gmDecisionGetType(kind) == 0,
                  "gmDecisionGetType(kind) == Gm_DecType_Flag");
    table->x0_staleMoveTable.x904[kind] = 1U;
}

static inline void setKindToValue_inline(int player, int kind,
                                         unsigned int val)
{
    pl_StaleMoveTableExt_t* table = Player_GetStaleMoveTableIndexPtr2(player);
    HSD_ASSERTMSG(80, player != 6, "player != Gm_Player_Other");
    HSD_ASSERTMSG(81, gmDecisionGetType(kind) == 1,
                  "gmDecisionGetType(kind) == Gm_DecType_Point");
    table->x0_staleMoveTable.x904[kind] = val;
}

unsigned int pl_800386D8(pl_800386D8_t* arg0, ssize_t arg1)
{
    return arg0->x3E8[arg1];
}

int pl_800386E8(pl_800386E8_arg0_t* arg0)
{
    int temp = arg0->unk_190 + arg0->unk_5AC;
    return temp + arg0->unk_5B0;
}

/// #fn_80038700

void pl_80038788(int player, int kind, int arg2)
{
    setKindToValue_inline(player, kind, arg2);
}

void pl_80038824(int arg0, int kind)
{
    pl_StaleMoveTableExt_t* temp_r31 = Player_GetStaleMoveTableIndexPtr2(arg0);

    HSD_ASSERTMSG(92, gmDecisionGetType(kind) == 1,
                  "gmDecisionGetType(kind) == Gm_DecType_Point");
    temp_r31->x0_staleMoveTable.x904[kind] += 1;
}

void pl_80038898(int arg0, int kind)
{
    unsigned int currentValue;
    pl_StaleMoveTableExt_t* temp_r31 = Player_GetStaleMoveTableIndexPtr2(arg0);
    HSD_ASSERTMSG(103, gmDecisionGetType(kind) == 1,
                  "gmDecisionGetType(kind) == Gm_DecType_Point");
    currentValue = temp_r31->x0_staleMoveTable.x904[kind];
    RETURN_IF(currentValue == 0);
    temp_r31->x0_staleMoveTable.x904[kind] = currentValue - 1;
}

pl_804D6470_t* pl_80038914(void)
{
    return pl_804D6470;
}

void pl_8003891C(int slot)
{
    int i;
    pl_StaleMoveTableExt_t* temp_r31;
    /// @todo: This aint it
    volatile int temp_zero;

    temp_r31 = Player_GetStaleMoveTableIndexPtr2(slot);
    plStale_ResetStaleMoveTableForPlayer(slot);
    plAttack_8003759C(slot);
    pl_80040DDC(slot);
    pl_80041524(slot);
    pl_800418F4(slot);

    for (i = 0; i < 39; ++i) {
        temp_r31->x0_staleMoveTable.x674[i] = 0;
    }
    for (i = 0; i < 39; ++i) {
        temp_r31->x0_staleMoveTable.x710[i] = 0;
    }
    for (i = 0; i < 39; ++i) {
        temp_r31->x0_staleMoveTable.x7AC[i] = 0;
    }
    for (i = 0; i < 30; ++i) {
        temp_r31->x0_staleMoveTable.x848[i] = 0;
    }

    fn_80038FB8(slot);
    temp_r31->x0_staleMoveTable.xC60 = 0.0f;
    temp_r31->x0_staleMoveTable.xC64 = 0.0f;
    temp_r31->x0_staleMoveTable.xC68 = 0;
    temp_r31->x0_staleMoveTable.xC6C = 0.0f;
    temp_r31->x0_staleMoveTable.xC70 = 0.0f;
    temp_r31->x0_staleMoveTable.xC74 = 0.0f;
    for (i = 0; i < 6; ++i) {
        temp_r31->x0_staleMoveTable.xC78[i] = 0.0f;
    }
    temp_r31->x0_staleMoveTable.xC90 = 0;
    temp_r31->x0_staleMoveTable.xC94 = 0;
    temp_r31->x0_staleMoveTable.xC98 = 0.0f;
    temp_r31->x0_staleMoveTable.xC9C = 0.0f;
    temp_r31->x0_staleMoveTable.xCA0 = 0.0f;
    temp_r31->x0_staleMoveTable.xCA4 = 0;
    temp_r31->x0_staleMoveTable.xCAC = 6;
    temp_r31->x0_staleMoveTable.xCB4 = 0;

    /// @todo: What?
    {
        temp_zero = 0;
        temp_r31->x0_staleMoveTable.xCB8 = 6;
        *(int*) (&temp_r31->x0_staleMoveTable.xCBC.x0) = temp_zero;
    }

    temp_r31->x0_staleMoveTable.xCC0.x0 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x4 = 0;
    temp_r31->x0_staleMoveTable.xCC0.kb_applied1 = 0.0f;
    temp_r31->x0_staleMoveTable.xCC0.xC = 6;
    temp_r31->x0_staleMoveTable.xCC0.x10_b0 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x11_b3 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b1 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b2 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b3 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b4 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b5 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b6 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x10_b7 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x11_b0 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x11_b1 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x11_b2 = 0;
    temp_r31->x0_staleMoveTable.xCC0.x11_b4 = 0;
    temp_r31->x0_staleMoveTable.xCD4 = 0;
    temp_r31->x0_staleMoveTable.xCD8 = 0;
    temp_r31->x0_staleMoveTable.xCE0 = 0.0f;
    temp_r31->x0_staleMoveTable.xCDC = 0.0f;
    temp_r31->x0_staleMoveTable.xCE4 = 0;
    temp_r31->x0_staleMoveTable.xCE8 = 0;
    temp_r31->x0_staleMoveTable.xCEC = 0;
    temp_r31->x0_staleMoveTable.xCF0 = 0;
    temp_r31->xCF4 = 0;
    temp_r31->xCF8 = 0.0f;
    temp_r31->x0_staleMoveTable.xCA8 = 0;
    temp_r31->xD04 = 0;
    temp_r31->xD08 = 0;
    temp_r31->xD0C = 0;
    temp_r31->xD10 = 0;
    temp_r31->xD14 = 0;
    temp_r31->xD18 = 0;
    temp_r31->xD1C = 0;
    temp_r31->xD20 = 0;
    temp_r31->xD24 = 0;
    temp_r31->xD28 = 0;
    temp_r31->xD2C = 0;
    temp_r31->xD30 = 0;
    temp_r31->xD34 = 0;
    temp_r31->xD38 = 0;
    temp_r31->xD3C = 0;
    temp_r31->xD40 = 0;
    temp_r31->xD44 = 0;
    temp_r31->xD48 = 0;
    temp_r31->xD4C = 0;
    temp_r31->xD50 = 0;
    temp_r31->xD54 = 0;
    temp_r31->xDC0 = 0.0f;
    temp_r31->xD58 = 0;
    temp_r31->xD5C = -1U;
    temp_r31->xD60 = 0;
    temp_r31->xD64 = 6;
    temp_r31->xD68 = 0;
    temp_r31->xD6C = 6;
    temp_r31->xCFC = 0;
    temp_r31->xD00 = 0;
    temp_r31->xD70 = 0;
    temp_r31->xD74 = 0.0f;
    temp_r31->xD78 = 0.0f;
    temp_r31->xD7C = 0.0f;
    temp_r31->xD80 = 0.0f;
    temp_r31->xD84 = 0.0f;
    temp_r31->xD88 = 0.0f;
    temp_r31->xD94 = 0.0f;
    temp_r31->xD98 = 0;
    temp_r31->xD8C = 0.0f;
    temp_r31->xD90 = 0;
    temp_r31->xD9C = 0;
    temp_r31->xDA0 = 0;
    temp_r31->xDA4 = 0;
    temp_r31->xDA8 = 0;
    temp_r31->xDAC = 0;
    temp_r31->xDB4 = 0;
    temp_r31->xDBC = 0;
    temp_r31->xDC4 = 0;
    temp_r31->xDC8 = 0;
    temp_r31->xDCC = 0;
    temp_r31->xDD0.bit0 = 0;
    temp_r31->xDD0.bit1 = 0;
    temp_r31->xDD0.bit2 = 0;
    temp_r31->xDD0.bit3 = 0;
    temp_r31->xDD0.bit4 = 0;
    temp_r31->xDD0.bit5 = 0;
    temp_r31->xDD0.bit6 = 0;
    temp_r31->xDD0.bit7 = 0;
    temp_r31->xDD1.bit0 = 0;
    temp_r31->xDD1.bit1 = 0;
    temp_r31->xDD1.bit2 = 0;
    temp_r31->xDD1.bit3 = 0;
    temp_r31->xDB8 = 0;
    temp_r31->xDD1.bit4 = 0;
    temp_r31->xDD1.bit5 = 0;
    temp_r31->xDD1.bit6 = 0;
    temp_r31->xDD1.bit7 = 0;
}

void pl_80038F10(int slot)
{
    pl_StaleMoveTableExt_t* temp_r3_2;
    int i;

    pl_StaleMoveTableExt_t* temp_r3 = Player_GetStaleMoveTableIndexPtr2(slot);
    temp_r3->xD50 = 0;
    temp_r3->xD54 = 0;
    temp_r3->xD60 = 0;
    temp_r3->xD64 = 6;

    for (i = 0; i < 6; ++i) {
        temp_r3_2 = Player_GetStaleMoveTableIndexPtr2(i);

        if (slot == temp_r3_2->xD64) {
            temp_r3_2->xD60 = 0;
            temp_r3_2->xD64 = 6;
        }

        if (slot == temp_r3_2->x0_staleMoveTable.xCAC) {
            temp_r3_2->x0_staleMoveTable.xCAC = 6;
        }

        if (slot == temp_r3_2->xD6C) {
            temp_r3_2->xD6C = 6;
        }
    }
}

void fn_80038FB8(int arg0)
{
    int var_ctr;
    pl_StaleMoveTableExt_t* temp_r3 = Player_GetStaleMoveTableIndexPtr2(arg0);

    for (var_ctr = 0; var_ctr < 215; ++var_ctr) {
        temp_r3->x0_staleMoveTable.x904[var_ctr] = 0;
    }
}

int pl_8003906C(int arg0, int arg1, unsigned int* arg2, unsigned int arg3,
                unsigned int arg4, unsigned int arg5, int* arg6)
{
    unsigned int var_r3;

    if (pl_Verify_gm_8016AEDC()) {
        if (gm_8016AEDC() <= arg3) {
            if (arg5 >= arg4) {
                if (arg1 != -1) {
                    setKindToValue_inline(arg0, arg1, 1U);
                } else {
                    *arg2 = 1U;
                }
            }

            if (arg3 == gm_8016AEDC()) {
                *arg6 = (int) arg5;
                return 1;
            }
        } else if ((gm_8016AEDC() % arg3) == 0) {
            if (arg1 != -1) {
                var_r3 = pl_80039418(arg0, arg1);
            } else {
                var_r3 = *arg2;
            }

            if (((int) var_r3 != 0) && (arg5 - (unsigned int) *arg6 < arg4)) {
                if (arg1 != -1) {
                    setKindToValue_inline(arg0, arg1, 0U);
                } else {
                    *arg2 = 0U;
                }
            }

            *arg6 = (int) arg5;
            return 1;
        }
    }
    return 0;
}

/// #pl_80039238

unsigned int pl_80039418(int arg0, int arg1)
{
    pl_StaleMoveTableExt_t* table = Player_GetStaleMoveTableIndexPtr2(arg0);
    return table->x0_staleMoveTable.x904[arg1];
}

static inline void pl_80039450_inline(int slot)
{
    pl_StaleMoveTableExt_t* var_r26;
    int i;

    var_r26 = Player_GetStaleMoveTableIndexPtr2(slot);

    for (i = 0; i < 215; ++i) {
        if (gmDecisionGetType(i) == 0) {
            var_r26->x0_staleMoveTable.x904[0] = 0;
        }
        var_r26 = (pl_StaleMoveTableExt_t*) ((char*) var_r26 + 4);
    }
}

void pl_80039450(int arg0)
{
    pl_StaleMoveTableExt_t* temp_r29 = Player_GetStaleMoveTableIndexPtr2(arg0);

    pl_80039450_inline(arg0);

    fn_80039618(arg0);
    fn_8003B044(arg0);
    fn_8003B9A4(arg0);
    fn_8003BD60(arg0);
    fn_8003C340(arg0);
    fn_8003CC84(arg0);
    fn_8003D2EC(arg0);

    if (!temp_r29->xDD0.bit1) {
        setKindToOne_inline(arg0, 0x4F);
    }

    if (gm_8016B0FC() == 0 && !temp_r29->xDD0.bit2) {
        setKindToOne_inline(arg0, 0x55);
    }

    if (temp_r29->xDCC != 0U && temp_r29->xDD1.bit5) {
        setKindToOne_inline(arg0, 0x4E);
    }
}

static inline bool between_x33_and_x3D(int kind)
{
    return kind >= 0x33 && kind <= 0x3D;
}

static inline bool between_x11_and_x30(int kind)
{
    return kind >= 0x11 && kind <= 0x30;
}

void fn_80039618(int arg0)
{
    s32 sp54;
    u32 sp50;
    void* temp_r3_8;
    HSD_GObj* temp_r26;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 var_f30;
    f32 var_f31;
    pl_800386D8_t* temp_r27;
    pl_StaleMoveTableExt_t* temp_r24;
    s32 temp_r0_2;
    s32 temp_r0_4;
    s32 temp_r15;
    s32 temp_r20;
    s32 temp_r21_27;
    s32 temp_r21_40;
    s32 temp_r25;
    s32 temp_r3_20;
    s32 var_ctr;
    s32 var_ctr_2;
    s32 var_ctr_3;
    s32 var_r21;
    s32 var_r22;
    s32 var_r26;
    s32 var_r26_2;
    s32 var_r27;
    s32 var_r28;
    s32 var_r28_2;
    s32 var_r28_3;
    s32 var_r31;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;
    s32 var_r5_2;
    s32 var_r5_3;
    u32 temp_r0;
    u32 temp_r14;
    u32 temp_r16;
    u32 temp_r17;
    u32 temp_r22;
    u32 temp_r28;
    u32 temp_r3_14;
    u32 temp_r3_15;
    u32 temp_r3_16;
    u32 temp_r3_17;
    u32 temp_r3_18;
    u32 temp_r3_19;
    u32 temp_r4_17;
    u32 temp_r4_18;
    u32 temp_r6;
    u32 var_r0;
    u32 var_r5;
    u32 var_r6;
    u8 temp_r0_3;
    u8* temp_r18;
    u8* temp_r19;
    u8* temp_r23;
    u8* var_r31_2;
    u8* var_r31_3;
    u8* var_r3_2;
    u8* var_r3_3;
    u8* var_r3_4;
    int i;
    PAD_STACK(8);

    temp_r24 = Player_GetStaleMoveTableIndexPtr2(arg0);
    temp_r27 = Player_GetTotalAttackCountPtr(arg0);
    temp_r0 = temp_r27->x344;
    temp_r26 = Player_GetEntity(arg0);
    temp_r18 = temp_r27->x4;
    sp54 = temp_r27->x194;
    temp_r16 = temp_r27->x1A8;
    temp_r23 = temp_r27->x1B0;
    temp_r17 = temp_r27->x340;
    temp_r19 = temp_r27->x35C;
    temp_r22 = temp_r27->x348;
    temp_r28 = temp_r27->x34C;
    sp50 = temp_r27->x354;
    temp_r14 = temp_r27->x500;
    temp_r20 = temp_r27->total_attack_count;
    temp_r25 = temp_r27->x1AC;
    temp_r15 = temp_r27->x358;
    if ((temp_r0 != 0U) && (temp_r0 == (u32) temp_r25)) {
        setKindToOne_inline(arg0, 0x0);
    }
    if ((temp_r22 != 0U) && (temp_r22 == (u32) temp_r25)) {
        setKindToOne_inline(arg0, 0x21);
    }
    if ((temp_r28 != 0U) && (temp_r28 == (u32) temp_r25)) {
        setKindToOne_inline(arg0, 0x22);
    }

    /// @todo Need to fix this logic, lots of unrolled stuff, maybe some
    /// inlines
    if ((u32) temp_r25 != 0U) {
        var_ctr = 0xB;
        var_r4 = 1;
        while (true) {
            bool match = true;
            for (i = 0; i < 9; ++i) {
                if ((var_r4 + 1 >= 0x33 && var_r4 + 1 <= 0x3D) ||
                    ((u32*) temp_r23)[i] == 0)
                {
                    match = false;
                    break;
                }
            }
            if (match) {
                var_r4 += 8;
                var_ctr--;
                if (var_ctr == 0) {
                    setKindToOne_inline(arg0, 0x24);
                    break;
                }
            } else {
                break;
            }
        }
    }

    var_r3_2 = temp_r23 + 0x100;
    var_r5 = 0U;
    var_r6 = 0U;
    var_r4_2 = 0x40;
    do {
        temp_r0_2 = *var_r3_2;
        var_r5 += temp_r0_2;
        switch (var_r4_2) {
        case 0x42:
        case 0x46:
        case 0x4A:
        case 0x4E:
        case 0x56:
            var_r6 += temp_r0_2;
            break;
        }
        var_r4_2 += 1;
        var_r3_2 += 4;
    } while (var_r4_2 <= 0x62);
    if (var_r5 != 0U) {
        // if ((u32) temp_r25 == (u32) temp_r23->unk188) {
        if ((u32) temp_r25 == *((u32*) &temp_r23[0x188])) {
            setKindToOne_inline(arg0, 0x95);
        } else if ((u32) temp_r25 == var_r6) {
            setKindToOne_inline(arg0, 0x96);
        } else if ((u32) temp_r25 == var_r5) {
            setKindToOne_inline(arg0, 0x94);
        }
    }
    var_r28 = 0;
loop_81:
    var_r31 = 1;
loop_82:
    if ((pl_80037B2C((struct pl_80037B2C_unk*) temp_r27, var_r28, var_r31) !=
         0) ||
        (pl_80038628(temp_r26, var_r31) == 0))
    {
        var_r31 += 1;
        if (var_r31 <= 0x10) {
            goto loop_82;
        }
    }
    if (var_r31 == 0x11) {
        setKindToOne_inline(arg0, 0x11);
    } else {
        var_r28 += 1;
        if (var_r28 < 6) {
            goto loop_81;
        }
    }
    if ((u32) Player_GetStaleMoveTableIndexPtr2(arg0)
            ->x0_staleMoveTable.x904[0x11] == 0U)
    {
        var_r31_2 = temp_r23 + 4;
        var_r21 = 0;
        var_r22 = 0;
        var_r28_2 = 1;
    loop_94:
        if (((u32) *var_r31_2 != 0U) ||
            (pl_80038628(temp_r26, var_r28_2) == 0))
        {
            var_r28_2 += 1;
            var_r31_2 += 4;
            if (var_r28_2 <= 0xB) {
                goto loop_94;
            }
        }
        if (var_r28_2 == 0xC) {
            var_r21 = 1;
        }
        var_r28_3 = 0xC;
        var_r31_3 = temp_r23 + 0x30;
    loop_100:
        if (((u32) *var_r31_3 != 0U) ||
            (pl_80038628(temp_r26, var_r28_3) == 0))
        {
            var_r28_3 += 1;
            var_r31_3 += 4;
            if (var_r28_3 <= 0x10) {
                goto loop_100;
            }
        }
        if (var_r28_3 == 0x11) {
            var_r22 = 1;
        }
        if ((var_r21 != 0) && (var_r22 != 0)) {
            setKindToOne_inline(arg0, 0x10);
        } else if (var_r21 != 0) {
            setKindToOne_inline(arg0, 0xE);
        } else if (var_r22 != 0) {
            setKindToOne_inline(arg0, 0xF);
        }
    }
    var_ctr_2 = 0x63;
    var_r3_3 = temp_r19 + 4;
    var_r5_2 = 0;
    var_r4_3 = 0;
    var_r0 = 0U;
loop_125:
    temp_r6 = *var_r3_3;
    if (temp_r6 != 0U) {
        var_r5_2 += 1;
        if (temp_r6 > var_r0) {
            var_r0 = temp_r6;
        }
        if ((var_r4_3 == 0) || (temp_r6 < (u32) var_r4_3)) {
            var_r4_3 = (s32) temp_r6;
        }
    }
    if (((s32) var_r0 == 0) || (var_r4_3 == 0) ||
        ((((f32) (var_r0 - var_r4_3) >= ((f32) var_r0 * pl_804D6470->x28)) ==
          0)))
    {
        var_r3_3 += 4;
        var_ctr_2 -= 1;
        if (var_ctr_2 == 0) {
            if (var_r5_2 >= (s32) pl_804D6470->x24) {
                setKindToOne_inline(arg0, 0x12);
            } else {
                goto loop_125;
            }
        }
        if ((u32) temp_r25 != 0U) {
            if (temp_r17 == (u32) temp_r25) {
                setKindToOne_inline(arg0, 0x15);
            } else if (pl_CalculateAverage(temp_r17, temp_r25) >=
                       pl_804D6470->x34)
            {
                setKindToOne_inline(arg0, 0x14);
            }
        }
        if ((u32) sp54 == 0U) {
            setKindToOne_inline(arg0, 0x16);
        }

        var_ctr_3 = 0xB;
        var_r3_4 = temp_r23 + 4;
        var_r5_3 = 0;
        var_r4_4 = 1;
        while (var_ctr_3 != 0) {
            for (i = 0; i < 9; ++i) {
                if (var_r3_4[i] != 0U) {
                    if (var_r4_4 >= 0x11 && var_r4_4 <= 0x30) {
                        var_r5_3 += 1;
                    } else {
                        break;
                    }
                }
                var_r4_4 += 1;
            }

            // var_r4_4 = var_r4_4 + 4;
            var_r3_4 = (void*) (&var_r3_4[11]);
            var_ctr_3 -= 1;
        }
        if (var_r5_3 != 0) {
            if (var_r5_3 == 1) {
                setKindToOne_inline(arg0, 0x18);
            } else {
                setKindToOne_inline(arg0, 0x17);
            }
        }

        if ((u32) temp_r25 != 0U) {
            temp_r3_14 = temp_r27->x56C;
            if (pl_CalculateAverage(temp_r3_14, temp_r25) >= pl_804D6470->x8) {
                setKindToOne_inline(arg0, 0x3);
            }
        }
        if (((u32) temp_r25 != 0U) && ((u32) temp_r27->x574 == (u32) temp_r25))
        {
            setKindToOne_inline(arg0, 0x5);
        } else if ((u32) temp_r25 >= (u32) pl_804D6470->xC) {
            temp_r3_15 = temp_r27->x574;
            if (pl_CalculateAverage(temp_r3_15, temp_r25) >= pl_804D6470->x10)
            {
                setKindToOne_inline(arg0, 0x4);
            }
        }
        if (((u32) temp_r20 == 0U) &&
            (temp_r24->x0_staleMoveTable.xC60 == 0.0f))
        {
            setKindToOne_inline(arg0, 0x64);
        } else {
            if ((u32) temp_r20 == 0U) {
                setKindToOne_inline(arg0, 0x60);
            } else {
                temp_r4_17 = temp_r24->xD04;
                if (temp_r4_17 >= (u32) pl_804D6470->x54) {
                    setKindToOne_inline(arg0, 0x2F);
                } else if (temp_r4_17 >= (u32) pl_804D6470->x50) {
                    setKindToOne_inline(arg0, 0x2E);
                }
            }
            if (temp_r24->x0_staleMoveTable.xC60 == 0.0F) {
                setKindToOne_inline(arg0, 0x62);
            } else if ((u32) temp_r24->xD0C >= (u32) pl_804D6470->xF0) {
                setKindToOne_inline(arg0, 0x61);
            }
        }
        temp_r21_27 = gm_80172140();
        temp_r3_16 = Player_GetFalls(arg0) + temp_r21_27;
        if (temp_r3_16 == 0U) {
            setKindToOne_inline(arg0, 0x63);
        } else if (temp_r3_16 == (u32) temp_r24->x0_staleMoveTable.xC94) {
            setKindToOne_inline(arg0, 0x66);
        }
        temp_r0_3 = temp_r24->xDD1.xDD1_value;
        if (((temp_r0_3 >> 7U) & 1) && ((temp_r0_3 >> 6U) & 1) &&
            ((temp_r0_3 >> 5U) & 1) && ((temp_r0_3 >> 4U) & 1))
        {
            setKindToOne_inline(arg0, 0x86);
        }
        if ((temp_r16 != 0U) && (temp_r16 == temp_r14) &&
            (sp50 == (u32) Player_GetStaleMoveTableIndexPtr2(arg0)
                         ->x0_staleMoveTable.x904[6]))
        {
            setKindToOne_inline(arg0, 0x8);
        }
        if (gm_801720B4() == 0) {
            temp_f0 = temp_r24->x0_staleMoveTable.xC64;
            temp_r0_4 = (s32) temp_f0;
            if ((f32) temp_r0_4 >= 400.0F) {
                setKindToOne_inline(arg0, 0x20);
            } else if ((f32) temp_r0_4 >= 350.0F) {
                setKindToOne_inline(arg0, 0x1F);
            } else if ((f32) temp_r0_4 >= 300.0F) {
                if (!gm_8016B3A0()) {
                    setKindToOne_inline(arg0, 0x1E);
                }
            } else if ((f32) temp_r0_4 >= 250.0F) {
                setKindToOne_inline(arg0, 0x1D);
            } else if ((f32) temp_r0_4 >= 200.0F) {
                setKindToOne_inline(arg0, 0x1C);
            } else if ((f32) temp_r0_4 >= 150.0F) {
                setKindToOne_inline(arg0, 0x1B);
            }
        }
        if ((u32) temp_r24->xDC8 != 0U) {
            if ((u32) temp_r15 == (u32) temp_r20) {
                setKindToOne_inline(arg0, 0xD);
            } else if (pl_CalculateAverage(temp_r15, temp_r20) >=
                       pl_804D6470->x20)
            {
                setKindToOne_inline(arg0, 0xC);
            }
        }
        temp_r21_40 = fn_80038700((s32) temp_r27, 1, 0x10);
        temp_r3_17 = fn_80038700((s32) &temp_r27->x358, 1, 0x10);
        if ((temp_r3_17 != 0U) && ((u32) temp_r21_40 == temp_r3_17) &&
            !(((u8) temp_r24->xDD1.xDD1_value >> 3U) & 1))
        {
            setKindToOne_inline(arg0, 0x23);
        }
        if (temp_r24->x0_staleMoveTable.xC74 >= pl_804D6470->x160) {
            setKindToOne_inline(arg0, 0xAA);
        }
        if (pl_800414C0(arg0) >= pl_804D6470->x0) {
            setKindToOne_inline(arg0, 0x1);
        }
        if (pl_80038628(temp_r26, 2) != 0) {
            temp_r3_18 = *(u32*) &temp_r18[4];
            if ((temp_r3_18 != 0U) && (temp_r3_18 == *(u32*) &temp_r18[8])) {
                temp_r4_18 = *(u32*) &temp_r19[4];
                if ((temp_r4_18 == *(u32*) &temp_r19[8]) &&
                    (temp_r3_18 == temp_r4_18))
                {
                    if (pl_80038628(temp_r26, 3) != 0) {
                        temp_r3_19 = *(u32*) &temp_r18[4];
                        if ((temp_r3_19 == *(u32*) &temp_r18[0xC]) &&
                            (temp_r3_19 == *(u32*) &temp_r19[0xC]))
                        {
                            setKindToOne_inline(arg0, 0x19);
                        }
                    } else {
                        setKindToOne_inline(arg0, 0x19);
                    }
                }
            }
        }
        var_f31 = 0.0f;
        var_r26 = 0;
        var_f30 = 0.0f;
        do {
            if (var_r26 != arg0) {
                temp_f0_2 = 0;
                // *((arg0 * 4) +
                //   (Player_GetStaleMoveTableIndexPtr2(var_r26) + 0xC78));
                if (var_f31 < temp_f0_2) {
                    var_f31 = temp_f0_2;
                }
                var_f30 += temp_f0_2;
            }
            var_r26 += 1;
        } while (var_r26 < 6);
        if (var_f30 != 0.0f) {
            if (gm_8016B558() == 3 &&
                pl_CalculateAverage(var_f31, var_f30) >= pl_804D6470->xF8)
            {
                setKindToOne_inline(arg0, 0x67);
            } else if (gm_8016B558() >= 4 &&
                       pl_CalculateAverage(var_f31, var_f30) >=
                           pl_804D6470->xFC)
            {
                setKindToOne_inline(arg0, 0x67);
            }
        }
        if (gm_8016B558() >= 3) {
            var_r27 = 0;
            var_r26_2 = 0;
        loop_421:
            if ((var_r26_2 != arg0) &&
                (temp_r3_20 = Player_GetKOsByPlayerIndex(arg0, var_r26_2),
                 ((temp_r3_20 == 0) == 0)))
            {
                if (((f32) temp_r3_20 >= pl_804D6470->x100) && (var_r27 == 0))
                {
                    var_r27 = 1;
                    goto block_427;
                }
                var_r27 = 0;
            } else {
            block_427:
                var_r26_2 += 1;
                if (var_r26_2 < 6) {
                    goto loop_421;
                }
            }
            if (var_r27 != 0) {
                setKindToOne_inline(arg0, 0x68);
            }
        }
    }
}

/// #fn_8003B044

/// #fn_8003B9A4

/// #fn_8003BD60

/// #fn_8003C340

/// #fn_8003CC84

/// #fn_8003D2EC
