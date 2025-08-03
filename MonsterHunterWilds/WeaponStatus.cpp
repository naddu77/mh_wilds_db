#include "pch.h"
#include "WeaponStatus.h"
#include "WeaponStatus.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    WeaponStatus::WeaponStatus(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Status const& status)
        : id_{ id }
        , damage_{ damage }
        , hidden_{ hidden }
        , status_{ status }
    {
        
    }

    winrt::MonsterHunterWilds::Status WeaponStatus::Status()
    {
        return status_;
    }

    int32_t WeaponStatus::Id()
    {
        return id_;
    }

    winrt::MonsterHunterWilds::WeaponDamage WeaponStatus::Damage()
    {
        return damage_;
    }

    bool WeaponStatus::Hidden()
    {
        return hidden_;
    }

    winrt::MonsterHunterWilds::SpecialKind WeaponStatus::SpecialKind()
    {
        return special_kind_;
    }
}
