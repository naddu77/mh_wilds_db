#include "pch.h"
#include "HeavyBowgun.h"
#include "HeavyBowgun.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HeavyBowgun HeavyBowgun::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
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
            winrt::MonsterHunterWilds::JsonParser::ParseSkillRanks(json_object.GetNamedArray(L"skills")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"defenseBonus"),
            winrt::MonsterHunterWilds::EnumMap::TryEldersealMap(json_object, L"elderseal"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"affinity"),
            winrt::MonsterHunterWilds::JsonParser::ParseNamedInt32Array(json_object, L"slots"),
            winrt::MonsterHunterWilds::WeaponCrafting::Parse(json_object.GetNamedObject(L"crafting")),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedObject(json_object, L"series", [](auto const& json_value) { return winrt::MonsterHunterWilds::WeaponSeries::Parse(json_value.GetObject()); }).as<winrt::MonsterHunterWilds::WeaponSeries>(),
            winrt::MonsterHunterWilds::JsonParser::ParseHeavyBowgunAmmos(json_object)
        };
    }

    HeavyBowgun::HeavyBowgun(
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
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> elderseal,
        int32_t affinity,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::MonsterHunterWilds::WeaponCrafting const& crafting,
        winrt::MonsterHunterWilds::WeaponSeries const& series,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> const& ammo)
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
        , ammo_{ ammo }
    {
        
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> HeavyBowgun::Ammo()
    {
        return ammo_;
    }

    int32_t HeavyBowgun::Id()
    {
        return id_;
    }

    int32_t HeavyBowgun::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind HeavyBowgun::Kind()
    {
        return kind_;
    }

    hstring HeavyBowgun::Name()
    {
        return name_;
    }

    int32_t HeavyBowgun::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage HeavyBowgun::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> HeavyBowgun::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness HeavyBowgun::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> HeavyBowgun::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> HeavyBowgun::Skills()
    {
        return skills_;
    }

    int32_t HeavyBowgun::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal>  HeavyBowgun::Elderseal()
    {
        return elderseal_;
    }

    int32_t HeavyBowgun::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> HeavyBowgun::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting HeavyBowgun::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries HeavyBowgun::Series()
    {
        return series_;
    }
}
