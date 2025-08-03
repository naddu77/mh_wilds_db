#include "pch.h"
#include "ItemRecipe.h"
#include "ItemRecipe.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    ItemRecipe::ItemRecipe(int32_t id, int32_t amount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> const& inputs)
        : id_{ id }, amount_{ amount }, inputs_{ inputs }
    {

	}

    int32_t ItemRecipe::Id()
    {
		return id_;
    }

    int32_t ItemRecipe::Amount()
    {
		return amount_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> ItemRecipe::Inputs()
    {
        return inputs_;
    }
}
