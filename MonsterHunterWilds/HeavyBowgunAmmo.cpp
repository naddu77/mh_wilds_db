#include "pch.h"
#include "HeavyBowgunAmmo.h"
#include "HeavyBowgunAmmo.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    HeavyBowgunAmmo::HeavyBowgunAmmo(winrt::MonsterHunterWilds::AmmoKind const& kind, int32_t level, int32_t capacity)
        : kind_{ kind }
        , level_{ level }
        , capacity_{ capacity }
    {
        
    }

    winrt::MonsterHunterWilds::AmmoKind HeavyBowgunAmmo::Kind()
    {
        return kind_;
    }

    int32_t HeavyBowgunAmmo::Level()
    {
        return level_;
    }

    int32_t HeavyBowgunAmmo::Capacity()
    {
        return capacity_;
    }
}
