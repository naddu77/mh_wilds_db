#pragma once
#include "ArmorCrafting.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorCrafting : ArmorCraftingT<ArmorCrafting>
    {
        static winrt::MonsterHunterWilds::ArmorCrafting Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ArmorCrafting(int32_t id, int32_t zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& materials);

        int32_t Id();
        int32_t ZennyCost();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> Materials();

    private:
        int32_t id_;
        int32_t zenny_cost_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> materials_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorCrafting : ArmorCraftingT<ArmorCrafting, implementation::ArmorCrafting>
    {
    };
}
