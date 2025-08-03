#include "pch.h"
#include "WeaponElement.h"
#include "WeaponElement.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    WeaponElement::WeaponElement(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Element const& element)
        : id_{ id }
        , damage_{ damage }
        , hidden_{ hidden }
        , element_{ element }
    {
        
    }

    winrt::MonsterHunterWilds::Element WeaponElement::Element()
    {
        return element_;
    }

    int32_t WeaponElement::Id()
    {
        return id_;
    }

    winrt::MonsterHunterWilds::WeaponDamage WeaponElement::Damage()
    {
        return damage_;
    }

    bool WeaponElement::Hidden()
    {
        return hidden_;
    }

    winrt::MonsterHunterWilds::SpecialKind WeaponElement::SpecialKind()
    {
        return special_kind_;
    }
}
