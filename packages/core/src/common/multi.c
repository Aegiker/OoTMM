#include <combo.h>

u32 gMultiMarkChests;
u32 gMultiMarkCollectibles;
u32 gMultiMarkSwitch0;
u32 gMultiMarkSwitch1;

static int mmSceneId(int sceneId)
{
    switch (sceneId)
    {
    case SCE_MM_TEMPLE_STONE_TOWER_INVERTED:
        return SCE_MM_TEMPLE_STONE_TOWER;
    case SCE_MM_SOUTHERN_SWAMP_CLEAR:
        return SCE_MM_SOUTHERN_SWAMP;
    case SCE_MM_MOUNTAIN_VILLAGE_SPRING:
        return SCE_MM_MOUNTAIN_VILLAGE_WINTER;
    case SCE_MM_GORON_VILLAGE_SPRING:
        return SCE_MM_GORON_VILLAGE_WINTER;
    case SCE_MM_TWIN_ISLANDS_SPRING:
        return SCE_MM_TWIN_ISLANDS_WINTER;
    case SCE_MM_STONE_TOWER_INVERTED:
        return SCE_MM_STONE_TOWER;
    default:
        return sceneId;
    }
}

static int getChestMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
        return !!(gMultiMarkChests & (1 << flagId));
#endif

    return !!(gOotSave.perm[sceneId].chests & (1 << flagId));
}

static int getChestMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkChests & (1 << flagId));
    return !!(gSaveContext.cycleSceneFlags[sceneId].chest & (1 << flagId));
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].chest & (1 << flagId));
}

static void setChestMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
    {
        SetChestFlag(play, flagId);
        gMultiMarkChests |= (1 << flagId);
        return;
    }
#endif

    gOotSave.perm[sceneId].chests |= (1 << flagId);
}

static void setChestMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetChestFlag(play, flagId);
        gMultiMarkChests |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].chest |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].chest |= (1 << flagId);
}

static int getCollectibleMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
        return !!(gMultiMarkCollectibles & (1 << flagId));
#endif

    return !!(gOotSave.perm[sceneId].collectibles & (1 << flagId));
}

static int getCollectibleMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkCollectibles & (1 << flagId));
    return !!(gSaveContext.cycleSceneFlags[sceneId].collectible & (1 << flagId));
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].collectible & (1 << flagId));
}

static void setCollectibleMarkOot(GameState_Play* play, int sceneId, int flagId)
{
#if defined(GAME_OOT)
    if (play && play->sceneId == sceneId)
    {
        SetCollectibleFlag(play, flagId);
        gMultiMarkCollectibles |= (1 << flagId);
        return;
    }
#endif

    gOotSave.perm[sceneId].chests |= (1 << flagId);
}

static void setCollectibleMarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetCollectibleFlag(play, flagId);
        gMultiMarkCollectibles |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].collectible |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].chest |= (1 << flagId);
}

static int getSwitch0MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkSwitch0 & (1 << flagId));
    return !!(gSaveContext.cycleSceneFlags[sceneId].switch0 & (1 << flagId));
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].switch0 & (1 << flagId));
}

static int getSwitch1MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
        return !!(gMultiMarkSwitch1 & (1 << flagId));
    return !!(gSaveContext.cycleSceneFlags[sceneId].switch1 & (1 << flagId));
#endif

    return !!(gMmSave.permanentSceneFlags[sceneId].switch1 & (1 << flagId));
}

static void setSwitch0MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetSwitchFlag(play, flagId);
        gMultiMarkSwitch0 |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].switch0 |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].switch0 |= (1 << flagId);
}

static void setSwitch1MarkMm(GameState_Play* play, int sceneId, int flagId)
{
    sceneId = mmSceneId(sceneId);

#if defined(GAME_MM)
    if (play && mmSceneId(play->sceneId) == sceneId)
    {
        SetSwitchFlag(play, flagId | 0x20);
        gMultiMarkSwitch1 |= (1 << flagId);
        return;
    }
    gSaveContext.cycleSceneFlags[sceneId].switch1 |= (1 << flagId);
#endif

    gMmSave.permanentSceneFlags[sceneId].switch1 |= (1 << flagId);
}

static int getStrayFairyMarkMm(GameState_Play* play, int sceneId, int id)
{
    if (id >= 0x30)
        return getCollectibleMarkMm(play, sceneId, id & 0x1f);
    else if (id >= 0x20)
        return getSwitch1MarkMm(play, sceneId, id & 0x1f);
    else
        return getSwitch0MarkMm(play, sceneId, id & 0x1f);
}

static void setStrayFairyMarkMm(GameState_Play* play, int sceneId, int id)
{
    if (id >= 0x30)
        setCollectibleMarkMm(play, sceneId, id & 0x1f);
    else if (id >= 0x20)
        setSwitch1MarkMm(play, sceneId, id & 0x1f);
    else
        setSwitch0MarkMm(play, sceneId, id & 0x1f);
}

static int getFiskMark(GameState_Play* play, int sceneId, int id)
{
    if (id >= 17)
        return getCollectibleMarkOot(play, sceneId, id & 0x1f);
    else
        return getChestMarkOot(play, sceneId, id & 0x1f);
}

static void setFishMark(GameState_Play* play, int sceneId, int id)
{
    if (id >= 17)
        setCollectibleMarkOot(play, sceneId, id & 0x1f);
    else
        setChestMarkOot(play, sceneId, id & 0x1f);
}

static void markXflag(Xflag* xf, int sliceId, int sceneId, int roomId, int id)
{
    bzero(xf, sizeof(*xf));
    xf->sliceId = sliceId;
    xf->setupId = (roomId & 0xc0) >> 6;
    xf->sceneId = sceneId;
    xf->roomId = roomId & 0x3f;
    xf->id = id;
}

static int getXflagsMarkOot(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    return comboXflagsGetOot(&xf);
}

static int getXflagsMarkMm(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    return comboXflagsGetMm(&xf);
}

static void setXflagsMarkOot(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    comboXflagsSetOot(&xf);
}

static void setXflagsMarkMm(GameState_Play* play, int sliceId, int sceneId, int roomId, int id)
{
    Xflag xf;

    markXflag(&xf, sliceId, sceneId, roomId, id);
    comboXflagsSetMm(&xf);
}

void multiSetMarkedOot(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!comboConfig(CFG_MULTIPLAYER))
        return;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        setChestMarkOot(play, sceneId, id);
        break;
    case OV_COLLECTIBLE:
        setCollectibleMarkOot(play, sceneId, id);
        break;
    case OV_NPC:
        BITMAP8_SET(gSharedCustomSave.oot.npc, id);
        break;
    case OV_GS:
        BITMAP32_SET(gOotSave.gsFlags, id - 8);
        break;
    case OV_SF:
        break;
    case OV_COW:
        gCowFlags |= (1 << id);
        break;
    case OV_SHOP:
        BITMAP8_SET(gSharedCustomSave.oot.shops, id);
        break;
    case OV_SCRUB:
        BITMAP8_SET(gSharedCustomSave.oot.scrubs, id);
        break;
    case OV_SR:
        BITMAP8_SET(gSharedCustomSave.oot.sr, id);
        break;
    case OV_FISH:
        setFishMark(play, sceneId, id);
        break;
    default:
        setXflagsMarkOot(play, ovType - OV_XFLAG0, sceneId, roomId, id);
        break;
    }
}

void multiSetMarkedMm(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!comboConfig(CFG_MULTIPLAYER))
        return;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        setChestMarkMm(play, sceneId, id);
        break;
    case OV_COLLECTIBLE:
        setCollectibleMarkMm(play, sceneId, id);
        break;
    case OV_NPC:
        BITMAP8_SET(gSharedCustomSave.mm.npc, id);
        break;
    case OV_GS:
        break;
    case OV_SF:
        setStrayFairyMarkMm(play, sceneId, id);
        break;
    case OV_COW:
        gCowFlags |= (1 << id);
        break;
    case OV_SHOP:
        BITMAP8_SET(gSharedCustomSave.mm.shops, id);
        break;
    case OV_SCRUB:
        break;
    case OV_SR:
        break;
    case OV_FISH:
        break;
    default:
        setXflagsMarkMm(play, ovType - OV_XFLAG0, sceneId, roomId, id);
        break;
    }
}

int multiIsMarkedOot(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!comboConfig(CFG_MULTIPLAYER))
        return 0;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        return getChestMarkOot(play, sceneId, id);
    case OV_COLLECTIBLE:
        return getCollectibleMarkOot(play, sceneId, id);
    case OV_NPC:
        return BITMAP8_GET(gSharedCustomSave.oot.npc, id);
    case OV_GS:
        return BITMAP32_GET(gOotSave.gsFlags, id - 8);
    case OV_SF:
        break;
    case OV_COW:
        return !!(gCowFlags & (1 << id));
    case OV_SHOP:
        return BITMAP8_GET(gSharedCustomSave.oot.shops, id);
    case OV_SCRUB:
        return BITMAP8_GET(gSharedCustomSave.oot.scrubs, id);
    case OV_SR:
        return BITMAP8_GET(gSharedCustomSave.oot.sr, id);
    case OV_FISH:
        return getFiskMark(play, sceneId, id);
    default:
        return getXflagsMarkOot(play, ovType - OV_XFLAG0, sceneId, roomId, id);
    }

    return 0;
}

int multiIsMarkedMm(GameState_Play* play, u8 ovType, u8 sceneId, u8 roomId, u8 id)
{
    if (!comboConfig(CFG_MULTIPLAYER))
        return 0;

    switch (ovType)
    {
    case OV_NONE:
        break;
    case OV_CHEST:
        return getChestMarkMm(play, sceneId, id);
    case OV_COLLECTIBLE:
        return getCollectibleMarkMm(play, sceneId, id);
    case OV_NPC:
        return BITMAP8_GET(gSharedCustomSave.mm.npc, id);
    case OV_GS:
        break;
    case OV_SF:
        return getStrayFairyMarkMm(play, sceneId, id);
    case OV_COW:
        return !!(gCowFlags & (1 << id));
    case OV_SHOP:
        return BITMAP8_GET(gSharedCustomSave.mm.shops, id);
    case OV_SCRUB:
        break;
    case OV_SR:
        break;
    case OV_FISH:
        break;
    default:
        return getXflagsMarkMm(play, ovType - OV_XFLAG0, sceneId, roomId, id);
    }

    return 0;
}
