#pragma once
#include "Phial.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Phial : PhialT<Phial>
    {
        Phial(winrt::MonsterHunterWilds::SwitchAxePhial const& kind, winrt::MonsterHunterWilds::WeaponDamage const& damage);

        winrt::MonsterHunterWilds::SwitchAxePhial Kind();
        winrt::MonsterHunterWilds::WeaponDamage Damage();

    private:
        winrt::MonsterHunterWilds::SwitchAxePhial kind_;
        winrt::MonsterHunterWilds::WeaponDamage damage_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Phial : PhialT<Phial, implementation::Phial>
    {
    };
}
