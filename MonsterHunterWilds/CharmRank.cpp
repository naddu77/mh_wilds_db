#include "pch.h"
#include "CharmRank.h"
#include "CharmRank.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::CharmRank CharmRank::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"name"),
            json_object.GetNamedString(L"description"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object,L"level"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"rarity"),
            winrt::MonsterHunterWilds::SkillRank::ParseJsonArray(json_object.GetNamedArray(L"skills")),
            winrt::MonsterHunterWilds::CharmRankCrafting::Parse(json_object.GetNamedObject(L"crafting"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> CharmRank::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    CharmRank::CharmRank(int32_t id, hstring const& name, hstring const& description, int32_t level, int32_t rarity, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills, winrt::MonsterHunterWilds::CharmRankCrafting const& crafting)
        : id_{ id }, name_{ name }, description_{ description }, level_{ level }, rarity_{ rarity }, skills_{ skills }, crafting_{ crafting }
    {

	}

    int32_t CharmRank::Id()
    {
        return id_;
    }

    hstring CharmRank::Name()
    {
        return name_;
    }

    hstring CharmRank::Description()
    {
        return description_;
    }

    int32_t CharmRank::Level()
    {
        return level_;
    }

    int32_t CharmRank::Rarity()
    {
        return rarity_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> CharmRank::Skills()
    {
        return skills_;
    }

    winrt::MonsterHunterWilds::CharmRankCrafting CharmRank::Crafting()
    {
        return crafting_;
    }
}
