#pragma once
#include "CraftingCost.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct CraftingCost : CraftingCostT<CraftingCost>
    {
        CraftingCost(int32_t quantity, winrt::MonsterHunterWilds::Item const& item);

        int32_t Quantity();
        winrt::MonsterHunterWilds::Item Item();

    private:
        int32_t quantity_;
		winrt::MonsterHunterWilds::Item item_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct CraftingCost : CraftingCostT<CraftingCost, implementation::CraftingCost>
    {
    };
}
