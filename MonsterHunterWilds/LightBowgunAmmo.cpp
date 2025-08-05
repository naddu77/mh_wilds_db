#include "pch.h"
#include "LightBowgunAmmo.h"
#include "LightBowgunAmmo.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::LightBowgunAmmo LightBowgunAmmo::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::EnumMap::AmmoKindMap(json_object.GetNamedString(L"kind")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"level")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"capacity")),
            json_object.GetNamedBoolean(L"rapid")
        };
    }

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
