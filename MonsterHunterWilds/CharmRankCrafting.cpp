#include "pch.h"
#include "CharmRankCrafting.h"
#include "CharmRankCrafting.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::CharmRankCrafting CharmRankCrafting::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
			json_object.GetNamedBoolean(L"craftable"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"zennyCost"),
            winrt::MonsterHunterWilds::CraftingCost::ParseJsonArray(json_object.GetNamedArray(L"materials"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRankCrafting> CharmRankCrafting::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

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
