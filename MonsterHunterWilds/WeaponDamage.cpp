#include "pch.h"
#include "WeaponDamage.h"
#include "WeaponDamage.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    WeaponDamage::WeaponDamage(int32_t raw, int32_t display)
        : raw_{ raw }
        , display_{ display }
    {
        
    }

    int32_t WeaponDamage::Raw()
    {
        return raw_;
    }

    int32_t WeaponDamage::Display()
    {
        return display_;
    }
}
