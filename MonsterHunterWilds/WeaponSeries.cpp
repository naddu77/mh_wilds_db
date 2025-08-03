#include "pch.h"
#include "WeaponSeries.h"
#include "WeaponSeries.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
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
