#include "pch.h"
#include "Phial.h"
#include "Phial.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Phial::Phial(winrt::MonsterHunterWilds::SwitchAxePhial const& kind, winrt::MonsterHunterWilds::WeaponDamage const& damage)
        : kind_{ kind }
        , damage_{ damage }
    {
        
    }

    winrt::MonsterHunterWilds::SwitchAxePhial Phial::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::WeaponDamage Phial::Damage()
    {
        return damage_;
    }
}
