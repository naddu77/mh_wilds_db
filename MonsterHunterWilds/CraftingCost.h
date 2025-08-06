#pragma once
#include "CraftingCost.g.h"
#include "Item.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct CraftingCost : CraftingCostT<CraftingCost>
    {
        static winrt::MonsterHunterWilds::CraftingCost Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

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
