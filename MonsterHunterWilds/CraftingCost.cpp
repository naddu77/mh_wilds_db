#include "pch.h"
#include "CraftingCost.h"
#include "CraftingCost.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::CraftingCost CraftingCost::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"quantity")),
            Item::Parse(json_object.GetNamedObject(L"item"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> CraftingCost::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    CraftingCost::CraftingCost(int32_t quantity, winrt::MonsterHunterWilds::Item const& item)
        : quantity_{ quantity }, item_{ item }
    {

	}

    int32_t CraftingCost::Quantity()
    {
        return quantity_;
    }

    winrt::MonsterHunterWilds::Item CraftingCost::Item()
    {
        return item_;
    }
}
