#pragma once
#include "WeaponDamage.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct WeaponDamage : WeaponDamageT<WeaponDamage>
    {
        WeaponDamage(int32_t raw, int32_t display);

        int32_t Raw();
        int32_t Display();

    private:
        int32_t raw_;
        int32_t display_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct WeaponDamage : WeaponDamageT<WeaponDamage, implementation::WeaponDamage>
    {
    };
}
