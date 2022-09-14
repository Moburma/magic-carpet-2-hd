#pragma once

#include <functional>
#include "../../remc2/engine/defs.h"
#include "../../remc2/portability/mctypes.h"
#include "../../../remc2/engine/global_types.h"

int sub_B5C60_getTerrainAlt2_orig(uint16_t a1, uint16_t a2, uint8_t mapHeightmap_11B4E0[]);
void sub_44DB0_truncTerrainHeight_orig(int16_t mapEntityIndex_15B4E0[], uint8_t mapHeightmap_11B4E0[]);
void sub_44EE0_smooth_tiles_orig(uaxis_2d a2x, uint8_t mapTerrainType_10B4E0[], uint8_t mapHeightmap_11B4E0[], uint8_t mapAngle_13B4E0[]);
