#include "pch.h"
#include "ChargeBlade.h"
#include "ChargeBlade.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ChargeBlade ChargeBlade::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            winrt::MonsterHunterWilds::EnumMap::WeaponKindMap(json_object.GetNamedString(L"kind")),
            json_object.GetNamedString(L"name"),
            static_cast<int32_t>(json_object.GetNamedNumber(L"rarity")),
            winrt::MonsterHunterWilds::WeaponDamage::Parse(json_object.GetNamedObject(L"damage")),
            ParseJsonArray(json_object.GetNamedArray(L"specials"), [](auto const& s) {
                auto kind{ s.GetObject().GetNamedString(L"kind") };

                if (kind == L"element")
                {
                    return winrt::MonsterHunterWilds::WeaponElement::Parse(s.GetObject()).as<winrt::MonsterHunterWilds::WeaponSpecial>();
                }
                else if (kind == L"status")
                {
                    return winrt::MonsterHunterWilds::WeaponStatus::Parse(s.GetObject()).as<winrt::MonsterHunterWilds::WeaponSpecial>();
                }

                std::unreachable();
            }),
            TryParseNamedObject(json_object, L"sharpness", [](auto const& json_object) { return winrt::MonsterHunterWilds::Sharpness::Parse(json_object); }),
            TryParseNamedArray(json_object, L"handicraft", [](auto const& h) { return static_cast<int32_t>(h.GetNumber()); }),
            ParseJsonArray(json_object.GetNamedArray(L"skills"), [](auto const& s) { return winrt::MonsterHunterWilds::SkillRank::Parse(s.GetObject()); }),
            static_cast<int32_t>(json_object.GetNamedNumber(L"defenseBonus")),
            winrt::MonsterHunterWilds::EnumMap::EldersealMap(json_object.GetNamedString(L"elderseal")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"affinity")),
            ParseJsonArray(json_object.GetNamedArray(L"slots"), [](auto const& s) { return static_cast<int32_t>(s.GetNumber()); }),
            winrt::MonsterHunterWilds::WeaponCrafting::Parse(json_object.GetNamedObject(L"crafting")),
            TryParseNamedObject(json_object, L"series", [](auto const& json_object) { return winrt::MonsterHunterWilds::WeaponSeries::Parse(json_object); }),
            winrt::MonsterHunterWilds::EnumMap::ChargeBladePhialMap(json_object.GetNamedString(L"phial"))
        };
    }

    ChargeBlade::ChargeBlade(
        int32_t id,
        int32_t game_id,
        winrt::MonsterHunterWilds::WeaponKind const& kind,
        hstring const& name,
        int32_t rarity,
        winrt::MonsterHunterWilds::WeaponDamage const& damage,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> const& specials,
        winrt::MonsterHunterWilds::Sharpness const& sharpness,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& handicraft,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills,
        int32_t defense_bonus,
        winrt::MonsterHunterWilds::Elderseal const& elderseal,
        int32_t affinity,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::MonsterHunterWilds::WeaponCrafting const& crafting,
        winrt::MonsterHunterWilds::WeaponSeries const& series,
        winrt::MonsterHunterWilds::ChargeBladePhial const& phial)
        : id_{ id }
        , game_id_{ game_id }
        , kind_{ kind }
        , name_{ name }
        , rarity_{ rarity }
        , damage_{ damage }
        , specials_{ specials }
        , sharpness_{ sharpness }
        , handicraft_{ handicraft }
        , skills_{ skills }
        , defense_bonus_{ defense_bonus }
        , elderseal_{ elderseal }
        , affinity_{ affinity }
        , slots_{ slots }
        , crafting_{ crafting }
        , series_{ series }
        , phial_{ phial }
    {
        
    }

    winrt::MonsterHunterWilds::ChargeBladePhial ChargeBlade::Phial()
    {
        return phial_;
    }

    int32_t ChargeBlade::Id()
    {
        return id_;
    }

    int32_t ChargeBlade::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind ChargeBlade::Kind()
    {
        return kind_;
    }

    hstring ChargeBlade::Name()
    {
        return name_;
    }

    int32_t ChargeBlade::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage ChargeBlade::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> ChargeBlade::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness ChargeBlade::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> ChargeBlade::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> ChargeBlade::Skills()
    {
        return skills_;
    }

    int32_t ChargeBlade::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::MonsterHunterWilds::Elderseal ChargeBlade::Elderseal()
    {
        return elderseal_;
    }

    int32_t ChargeBlade::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> ChargeBlade::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting ChargeBlade::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries ChargeBlade::Series()
    {
        return series_;
    }
}
