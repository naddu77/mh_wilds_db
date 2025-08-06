#include "pch.h"
#include "ArmorCrafting.h"
#include "ArmorCrafting.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorCrafting ArmorCrafting::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
               winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
               winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"zennyCost"),
               winrt::MonsterHunterWilds::CraftingCost::ParseJsonArray(json_object.GetNamedArray(L"materials"))
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
