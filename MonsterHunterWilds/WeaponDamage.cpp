#include "pch.h"
#include "WeaponDamage.h"
#include "WeaponDamage.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::WeaponDamage WeaponDamage::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"raw")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"display")),
        };
    }

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
