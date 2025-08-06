#include "pch.h"
#include "Item.h"
#include "Item.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Item Item::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            json_object.GetNamedString(L"name"),
            json_object.GetNamedString(L"description"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"rarity"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"carryLimit"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"value"),
            winrt::MonsterHunterWilds::ItemRecipe::ParseJsonArray(json_object.GetNamedArray(L"recipes")),
            winrt::MonsterHunterWilds::ItemIcon::Parse(json_object.GetNamedObject(L"icon"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> Item::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    Item::Item(
        int32_t id,
        int32_t game_id,
        hstring const& name,
        hstring const& description,
        int32_t rarity,
        int32_t carry_limit,
        int32_t the_value,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> const& recipes,
        winrt::MonsterHunterWilds::ItemIcon const& icon)
        : id_{ id }, game_id_{ game_id }, name_{ name }, description_{ description },
		rarity_{ rarity }, carry_limit_{ carry_limit }, value_{ the_value }, recipes_{ recipes }, icon_{ icon }
    {
        
    }

    int32_t Item::Id()
    {
		return id_;
    }

    int32_t Item::GameId()
    {
		return game_id_;
    }

    hstring Item::Name()
    {
        return name_;
    }

    hstring Item::Description()
    {
        return description_;
    }

    int32_t Item::Rarity()
    {
        return rarity_;
    }

    int32_t Item::CarryLimit()
    {
        return carry_limit_;
    }

    int32_t Item::Value()
    {
        return value_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> Item::Recipes()
    {
        return recipes_;
    }

    winrt::MonsterHunterWilds::ItemIcon Item::Icon()
    {
        return icon_;
    }
}
