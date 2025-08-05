#pragma once
#include "ItemRecipe.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ItemRecipe : ItemRecipeT<ItemRecipe>
    {
        static winrt::MonsterHunterWilds::ItemRecipe Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ItemRecipe(int32_t id, int32_t amount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> const& inputs);

        int32_t Id();
        int32_t Amount();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> Inputs();

    private:
        int32_t id_;
        int32_t amount_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> inputs_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ItemRecipe : ItemRecipeT<ItemRecipe, implementation::ItemRecipe>
    {
    };
}
