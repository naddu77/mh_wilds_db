#include "pch.h"
#include "CraftingCost.h"
#include "CraftingCost.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::CraftingCost CraftingCost::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"quantity")),
            Item::Parse(json_object.GetNamedObject(L"item"))
        };
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
