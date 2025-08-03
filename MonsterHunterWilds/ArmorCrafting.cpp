#include "pch.h"
#include "ArmorCrafting.h"
#include "ArmorCrafting.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    ArmorCrafting::ArmorCrafting(int32_t id, int32_t zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> const& materials)
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

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> ArmorCrafting::Materials()
    {
		return materials_;
    }
}
