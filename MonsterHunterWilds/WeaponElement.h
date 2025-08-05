#pragma once
#include "WeaponElement.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct WeaponElement : WeaponElementT<WeaponElement>
    {
        static winrt::MonsterHunterWilds::WeaponElement Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        WeaponElement(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Element const& element);

        winrt::MonsterHunterWilds::Element Element();
        int32_t Id();
        winrt::MonsterHunterWilds::WeaponDamage Damage();
        bool Hidden();
        winrt::MonsterHunterWilds::SpecialKind SpecialKind();

    private:
        winrt::MonsterHunterWilds::Element element_;
        int32_t id_;
        winrt::MonsterHunterWilds::WeaponDamage damage_;
        bool hidden_;
        winrt::MonsterHunterWilds::SpecialKind special_kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct WeaponElement : WeaponElementT<WeaponElement, implementation::WeaponElement>
    {
    };
}
