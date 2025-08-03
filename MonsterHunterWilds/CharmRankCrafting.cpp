#include "pch.h"
#include "CharmRankCrafting.h"
#include "CharmRankCrafting.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    CharmRankCrafting::CharmRankCrafting(bool craftable, int32_t zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& materials)
        : craftable_{ craftable }, zenny_cost_{ zenny_cost }, materials_{ materials }
    {

	}

    bool CharmRankCrafting::Craftable()
    {
        return craftable_;
    }

    int32_t CharmRankCrafting::ZennyCost()
    {
        return zenny_cost_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> CharmRankCrafting::Materials()
    {
        return materials_;
    }
}
