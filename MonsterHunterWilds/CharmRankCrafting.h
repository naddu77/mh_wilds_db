#pragma once
#include "CharmRankCrafting.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct CharmRankCrafting : CharmRankCraftingT<CharmRankCrafting>
    {
        static winrt::MonsterHunterWilds::CharmRankCrafting Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        CharmRankCrafting(bool craftable, int32_t zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& materials);

        bool Craftable();
        int32_t ZennyCost();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> Materials();

    private:
        bool craftable_{ false };
        int32_t zenny_cost_{ 0 };
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> materials_{ nullptr };
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct CharmRankCrafting : CharmRankCraftingT<CharmRankCrafting, implementation::CharmRankCrafting>
    {
    };
}
