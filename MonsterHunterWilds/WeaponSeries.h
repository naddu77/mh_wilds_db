#pragma once
#include "WeaponSeries.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct WeaponSeries : WeaponSeriesT<WeaponSeries>
    {
        static winrt::MonsterHunterWilds::WeaponSeries Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        WeaponSeries() = default;
        WeaponSeries(int32_t id, int32_t game_id);

        int32_t Id();
        int32_t GameId();

    private:
        int32_t id_;
        int32_t game_id_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct WeaponSeries : WeaponSeriesT<WeaponSeries, implementation::WeaponSeries>
    {
    };
}
