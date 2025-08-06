#include "pch.h"
#include "Phial.h"
#include "Phial.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Phial Phial::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::EnumMap::SwitchAxePhialMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedObject(json_object, L"damage", [](auto const& json_value) { return winrt::MonsterHunterWilds::WeaponDamage::Parse(json_value.GetObject()); }).as<winrt::MonsterHunterWilds::WeaponDamage>()
        };
    }

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
