#pragma once
#include "WeaponStatus.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct WeaponStatus : WeaponStatusT<WeaponStatus>
    {
        WeaponStatus(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Status const& status);

        winrt::MonsterHunterWilds::Status Status();
        int32_t Id();
        winrt::MonsterHunterWilds::WeaponDamage Damage();
        bool Hidden();
        winrt::MonsterHunterWilds::SpecialKind SpecialKind();

    private:
        winrt::MonsterHunterWilds::Status status_;
        int32_t id_;
        winrt::MonsterHunterWilds::WeaponDamage damage_;
        bool hidden_;
        winrt::MonsterHunterWilds::SpecialKind special_kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct WeaponStatus : WeaponStatusT<WeaponStatus, implementation::WeaponStatus>
    {
    };
}
