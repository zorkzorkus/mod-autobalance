/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE
 */

#ifndef __AB_PLAYER_COUNT_SCALING_SETTINGS_H
#define __AB_PLAYER_COUNT_SCALING_SETTINGS_H

#include "DataMap.h"
#include "Define.h"

class AutoBalancePlayerCountScalingSettings : public DataMap::Base
{
public:
    AutoBalancePlayerCountScalingSettings() {}
    AutoBalancePlayerCountScalingSettings(bool enabled, uint32 baselinePlayers, float health, float mana, float armor, float damage, float ccduration) :
        enabled(enabled), baselinePlayers(baselinePlayers), health(health), mana(mana), armor(armor), damage(damage), ccduration(ccduration) {}

    bool   enabled         = false;
    uint32 baselinePlayers = 0;   // 0 = the instance's maximum player count

    // health, mana, armor, and ccduration are WEIGHTS describing how strongly the
    // stat follows the relative player count:
    //   multiplier = 1.0 + weight * (players - baseline) / baseline
    // 1.0 scales the stat proportionally with the group size, 0.0 leaves it
    // unchanged at any player count. At `baseline` players every multiplier is 1.0.
    //
    // damage is instead the DAMAGE MULTIPLIER AT THE INSTANCE'S MAXIMUM player
    // count: above the baseline, damage ramps linearly from 1.0 up to this value;
    // below the baseline it follows the InflectionPoint-style damage curve
    // (see getPlayerCountScalingDamageMultiplier).
    float health          = 1.0;
    float mana            = 0.0;
    float armor           = 0.0;
    float damage          = 1.05;
    float ccduration      = 0.0;
};

#endif
