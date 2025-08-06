#include "pch.h"
#include "Armor.h"
#include "Armor.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Armor Armor::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"name"),
            json_object.GetNamedString(L"description"),
            winrt::MonsterHunterWilds::EnumMap::ArmorKindMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::EnumMap::RankMap(json_object.GetNamedString(L"rank")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"rarity"),
            winrt::MonsterHunterWilds::ArmorDefense::Parse(json_object.GetNamedObject(L"defense")),
            winrt::MonsterHunterWilds::ArmorResistances::Parse(json_object.GetNamedObject(L"resistances")),
            winrt::MonsterHunterWilds::JsonParser::ParseNamedInt32Array(json_object, L"slots"),
            winrt::MonsterHunterWilds::SkillRank::ParseJsonArray(json_object.GetNamedArray(L"skills")),
            winrt::MonsterHunterWilds::MiniArmorSet::Parse(json_object.GetNamedObject(L"armorSet")),
            winrt::MonsterHunterWilds::ArmorCrafting::Parse(json_object.GetNamedObject(L"crafting"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> Armor::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    Armor::Armor(
        int32_t id,
        hstring const& name,
        hstring const& description,
        winrt::MonsterHunterWilds::ArmorKind const& kind,
        winrt::MonsterHunterWilds::Rank const& rank,
        int32_t rarity,
        winrt::MonsterHunterWilds::ArmorDefense const& defense,
        winrt::MonsterHunterWilds::ArmorResistances const& resistances,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills,
        winrt::MonsterHunterWilds::MiniArmorSet const& armor_set,
        winrt::MonsterHunterWilds::ArmorCrafting const& crafting)
        : id_{ id }
        , name_{ name }
        , description_{ description }
        , kind_{ kind }
        , rank_{ rank }
        , rarity_{ rarity }
        , defense_{ defense }
        , resistances_{ resistances }
        , slots_{ slots }
        , skills_{ skills }
        , armor_set_{ armor_set }
        , crafting_{ crafting }
    {

	}

    int32_t Armor::Id()
    {
        return id_;
    }

    hstring Armor::Name()
    {
        return name_;
    }

    hstring Armor::Description()
    {
        return description_;
    }

    winrt::MonsterHunterWilds::ArmorKind Armor::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::Rank Armor::Rank()
    {
        return rank_;
    }

    int32_t Armor::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::ArmorDefense Armor::Defense()
    {
        return defense_;
    }

    winrt::MonsterHunterWilds::ArmorResistances Armor::Resistances()
    {
        return resistances_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Armor::Slots()
    {
        return slots_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Armor::Skills()
    {
        return skills_;
    }

    winrt::MonsterHunterWilds::MiniArmorSet Armor::ArmorSet()
    {
        return armor_set_;
    }

    winrt::MonsterHunterWilds::ArmorCrafting Armor::Crafting()
    {
        return crafting_;
    }
}
