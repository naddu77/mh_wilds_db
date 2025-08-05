#pragma once
#include "LightBowgunAmmo.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct LightBowgunAmmo : LightBowgunAmmoT<LightBowgunAmmo>
    {
        static winrt::MonsterHunterWilds::LightBowgunAmmo Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        LightBowgunAmmo(winrt::MonsterHunterWilds::AmmoKind const& kind, int32_t level, int32_t capacity, bool rapid);

        winrt::MonsterHunterWilds::AmmoKind Kind();
        int32_t Level();
        int32_t Capacity();
        bool Rapid();

    private:
        winrt::MonsterHunterWilds::AmmoKind kind_;
        int32_t level_;
        int32_t capacity_;
        bool rapid_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct LightBowgunAmmo : LightBowgunAmmoT<LightBowgunAmmo, implementation::LightBowgunAmmo>
    {
    };
}
