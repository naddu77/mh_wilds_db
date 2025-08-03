#include "pch.h"
#include "LightBowgunAmmo.h"
#include "LightBowgunAmmo.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    LightBowgunAmmo::LightBowgunAmmo(winrt::MonsterHunterWilds::AmmoKind const& kind, int32_t level, int32_t capacity, bool rapid)
        : kind_{ kind }
        , level_{ level }
        , capacity_{ capacity }
        , rapid_{ rapid }
    {
        throw hresult_not_implemented();
    }

    winrt::MonsterHunterWilds::AmmoKind LightBowgunAmmo::Kind()
    {
        return kind_;
    }

    int32_t LightBowgunAmmo::Level()
    {
        return level_;
    }

    int32_t LightBowgunAmmo::Capacity()
    {
        return capacity_;
    }

    bool LightBowgunAmmo::Rapid()
    {
        return rapid_;
    }
}
