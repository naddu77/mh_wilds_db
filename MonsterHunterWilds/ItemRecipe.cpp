#include "pch.h"
#include "ItemRecipe.h"
#include "ItemRecipe.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ItemRecipe ItemRecipe::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"amount"),
            winrt::MonsterHunterWilds::MiniItem::ParseJsonArray(json_object.GetNamedArray(L"inputs"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> ItemRecipe::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    ItemRecipe::ItemRecipe(int32_t id, int32_t amount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> const& inputs)
        : id_{ id }, amount_{ amount }, inputs_{ inputs }
    {

	}

    int32_t ItemRecipe::Id()
    {
		return id_;
    }

    int32_t ItemRecipe::Amount()
    {
		return amount_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> ItemRecipe::Inputs()
    {
        return inputs_;
    }
}
