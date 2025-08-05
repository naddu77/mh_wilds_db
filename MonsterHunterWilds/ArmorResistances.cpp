#include "pch.h"
#include "ArmorResistances.h"
#include "ArmorResistances.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorResistances ArmorResistances::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"fire")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"water")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"ice")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"thunder")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"dragon"))
        };
    }

    ArmorResistances::ArmorResistances(int32_t fire, int32_t water, int32_t ice, int32_t thunder, int32_t dragon)
        : fire_{ fire }, water_{ water }, ice_{ ice }, thunder_{ thunder }, dragon_{ dragon }
    {
	}

    int32_t ArmorResistances::Fire()
    {
        return fire_;
    }

    int32_t ArmorResistances::Water()
    {
        return water_;
    }

    int32_t ArmorResistances::Ice()
    {
        return ice_;
    }

    int32_t ArmorResistances::Thunder()
    {
        return thunder_;
    }

    int32_t ArmorResistances::Dragon()
    {
        return dragon_;
    }
}
