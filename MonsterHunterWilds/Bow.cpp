#include "pch.h"
#include "Bow.h"
#include "Bow.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Bow Bow::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            winrt::MonsterHunterWilds::EnumMap::WeaponKindMap(json_object.GetNamedString(L"kind")),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"rarity"),
            winrt::MonsterHunterWilds::WeaponDamage::Parse(json_object.GetNamedObject(L"damage")),
            winrt::MonsterHunterWilds::JsonParser::ParseWeaponSpecials(json_object),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedObject(json_object, L"sharpness", [](auto const& json_value) { return winrt::MonsterHunterWilds::Sharpness::Parse(json_value.GetObject()); }).as<winrt::MonsterHunterWilds::Sharpness>(),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedInt32Array(json_object, L"handicraft"),
            winrt::MonsterHunterWilds::SkillRank::ParseJsonArray(json_object.GetNamedArray(L"skills")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"defenseBonus"),
            winrt::MonsterHunterWilds::EnumMap::TryEldersealMap(json_object, L"elderseal"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"affinity"),
            winrt::MonsterHunterWilds::JsonParser::ParseNamedInt32Array(json_object, L"slots"),
            winrt::MonsterHunterWilds::WeaponCrafting::Parse(json_object.GetNamedObject(L"crafting")),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedObject(json_object, L"series", [](auto const& json_value) { return winrt::MonsterHunterWilds::WeaponSeries::Parse(json_value.GetObject()); }).as<winrt::MonsterHunterWilds::WeaponSeries>(),
            winrt::single_threaded_vector(
                json_object.GetNamedArray(L"coatings")
                | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::EnumMap::BowCoatingMap(json_value.GetString()); })
                | std::ranges::to<std::vector>()
            )
        };
    }

    Bow::Bow(
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
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> const& elderseal,
        int32_t affinity,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::MonsterHunterWilds::WeaponCrafting const& crafting,
        winrt::MonsterHunterWilds::WeaponSeries const& series,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> const& coatings)
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
        , coatings_{ coatings }
    {
        
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> Bow::Coatings()
    {
        return coatings_;
    }

    int32_t Bow::Id()
    {
        return id_;
    }

    int32_t Bow::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind Bow::Kind()
    {
        return kind_;
    }

    hstring Bow::Name()
    {
        return name_;
    }

    int32_t Bow::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage Bow::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> Bow::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness Bow::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Bow::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Bow::Skills()
    {
        return skills_;
    }

    int32_t Bow::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> Bow::Elderseal()
    {
        return elderseal_;
    }

    int32_t Bow::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Bow::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting Bow::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries Bow::Series()
    {
        return series_;
    }
}
