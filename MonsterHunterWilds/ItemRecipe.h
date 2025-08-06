#pragma once
#include "ItemRecipe.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ItemRecipe : ItemRecipeT<ItemRecipe>
    {
        static winrt::MonsterHunterWilds::ItemRecipe Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        ItemRecipe(int32_t id, int32_t amount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> const& inputs);

        int32_t Id();
        int32_t Amount();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> Inputs();

    private:
        int32_t id_;
        int32_t amount_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> inputs_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ItemRecipe : ItemRecipeT<ItemRecipe, implementation::ItemRecipe>
    {
    };
}
