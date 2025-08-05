#include "pch.h"
#include "WeaponElement.h"
#include "WeaponElement.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::WeaponElement WeaponElement::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            WeaponDamage::Parse(json_object.GetNamedObject(L"damage")),
            json_object.GetNamedBoolean(L"hidden"),
            winrt::MonsterHunterWilds::EnumMap::ElementMap(json_object.GetNamedString(L"element"))
        };
    }

    WeaponElement::WeaponElement(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Element const& element)
        : id_{ id }
        , damage_{ damage }
        , hidden_{ hidden }
        , special_kind_{ winrt::MonsterHunterWilds::SpecialKind::Element }
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
