#pragma once
#include "Item.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Item : ItemT<Item>
    {
        static winrt::MonsterHunterWilds::Item Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        Item(
            int32_t id,
            int32_t game_id,
            hstring const& name,
            hstring const& description,
            int32_t rarity,
            int32_t carry_limit,
            int32_t the_value,
            winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> const& recipes,
            winrt::MonsterHunterWilds::ItemIcon const& icon);
        
        int32_t Id();
        int32_t GameId();
        hstring Name();
        hstring Description();
        int32_t Rarity();
        int32_t CarryLimit();
        int32_t Value();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> Recipes();
        winrt::MonsterHunterWilds::ItemIcon Icon();

    private:
        int32_t id_;
		int32_t game_id_;
        hstring name_;
        hstring description_;
        int32_t rarity_;
        int32_t carry_limit_;
        int32_t value_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> recipes_;
		winrt::MonsterHunterWilds::ItemIcon icon_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Item : ItemT<Item, implementation::Item>
    {
    };
}
