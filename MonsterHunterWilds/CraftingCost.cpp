#include "pch.h"
#include "CraftingCost.h"
#include "CraftingCost.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
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
