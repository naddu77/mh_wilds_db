#include "pch.h"
#include "ArmorCrafting.h"
#include "ArmorCrafting.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorCrafting ArmorCrafting::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
               static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
               static_cast<int32_t>(json_object.GetNamedNumber(L"zennyCost")),
               ParseJsonArray(json_object.GetNamedArray(L"materials"), [](auto const& json_value) { return winrt::MonsterHunterWilds::CraftingCost::Parse(json_value.GetObject()); })
        };
    }

    ArmorCrafting::ArmorCrafting(int32_t id, int32_t zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& materials)
        : id_{ id }, zenny_cost_{ zenny_cost }, materials_{ materials }
    {
	}

    int32_t ArmorCrafting::Id()
    {
		return id_;
    }

    int32_t ArmorCrafting::ZennyCost()
    {
		return zenny_cost_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> ArmorCrafting::Materials()
    {
		return materials_;
    }
}
