#include "pch.h"
#include "CharmRankCrafting.h"
#include "CharmRankCrafting.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::CharmRankCrafting CharmRankCrafting::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
			json_object.GetNamedBoolean(L"craftable"),
            static_cast<int32_t>(json_object.GetNamedNumber(L"zennyCost")),
            ParseJsonArray(json_object.GetNamedArray(L"materials"), [](auto const& m) { return winrt::MonsterHunterWilds::CraftingCost::Parse(m.GetObject()); })
        };
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
