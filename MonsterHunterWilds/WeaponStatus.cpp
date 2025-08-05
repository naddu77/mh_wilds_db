#include "pch.h"
#include "WeaponStatus.h"
#include "WeaponStatus.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::WeaponStatus WeaponStatus::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        

        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            WeaponDamage::Parse(json_object.GetNamedObject(L"damage")),
            json_object.GetNamedBoolean(L"hidden"),
            winrt::MonsterHunterWilds::EnumMap::StatusMap(json_object.GetNamedString(L"status"))
        };
    }

    WeaponStatus::WeaponStatus(int32_t id, winrt::MonsterHunterWilds::WeaponDamage const& damage, bool hidden, winrt::MonsterHunterWilds::Status const& status)
        : id_{ id }
        , damage_{ damage }
        , hidden_{ hidden }
        , special_kind_{ winrt::MonsterHunterWilds::SpecialKind::Status }
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
