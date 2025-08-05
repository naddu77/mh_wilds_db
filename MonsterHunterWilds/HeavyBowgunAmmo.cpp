#include "pch.h"
#include "HeavyBowgunAmmo.h"
#include "HeavyBowgunAmmo.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HeavyBowgunAmmo HeavyBowgunAmmo::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::EnumMap::AmmoKindMap(json_object.GetNamedString(L"kind")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"level")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"capacity")),
        };
    }

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
