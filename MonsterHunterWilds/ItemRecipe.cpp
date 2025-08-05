#include "pch.h"
#include "ItemRecipe.h"
#include "ItemRecipe.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ItemRecipe ItemRecipe::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"amount")),
            ParseJsonArray(json_object.GetNamedArray(L"inputs"), [](auto const& json_value) { return winrt::MonsterHunterWilds::Item::Parse(json_value.GetObject()); })
        };
    }

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
