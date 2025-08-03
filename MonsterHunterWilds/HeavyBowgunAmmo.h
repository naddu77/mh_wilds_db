#pragma once
#include "HeavyBowgunAmmo.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HeavyBowgunAmmo : HeavyBowgunAmmoT<HeavyBowgunAmmo>
    {
        HeavyBowgunAmmo(winrt::MonsterHunterWilds::AmmoKind const& kind, int32_t level, int32_t capacity);

        winrt::MonsterHunterWilds::AmmoKind Kind();
        int32_t Level();
        int32_t Capacity();

    private:
        winrt::MonsterHunterWilds::AmmoKind kind_;
        int32_t level_;
        int32_t capacity_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HeavyBowgunAmmo : HeavyBowgunAmmoT<HeavyBowgunAmmo, implementation::HeavyBowgunAmmo>
    {
    };
}
