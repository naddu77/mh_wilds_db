#include "pch.h"
#include "WeaponSeries.h"
#include "WeaponSeries.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::WeaponSeries WeaponSeries::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId"))
        };
    }

    WeaponSeries::WeaponSeries(int32_t id, int32_t game_id)
        : id_{ id }
        , game_id_{ game_id }
    {
        
    }

    int32_t WeaponSeries::Id()
    {
        return id_;
    }

    int32_t WeaponSeries::GameId()
    {
        return game_id_;
    }
}
