#include "pch.h"
#include "Item.h"
#include "Item.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Item::Item(
        int32_t id,
        int32_t game_id,
        hstring const& name,
        hstring const& description,
        int32_t rarity,
        int32_t carry_limit,
        int32_t the_value,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> const& recipes,
        winrt::MonsterHunterWilds::ItemIcon const& icon)
        : id_{ id }, game_id_{ game_id }, name_{ name }, description_{ description },
		rarity_{ rarity }, carry_limit_{ carry_limit }, value_{ the_value }, recipes_{ recipes }, icon_{ icon }
    {
        
    }

    int32_t Item::Id()
    {
		return id_;
    }

    int32_t Item::GameId()
    {
		return game_id_;
    }

    hstring Item::Name()
    {
        return name_;
    }

    hstring Item::Description()
    {
        return description_;
    }

    int32_t Item::Rarity()
    {
        return rarity_;
    }

    int32_t Item::CarryLimit()
    {
        return carry_limit_;
    }

    int32_t Item::Value()
    {
        return value_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ItemRecipe> Item::Recipes()
    {
        return recipes_;
    }

    winrt::MonsterHunterWilds::ItemIcon Item::Icon()
    {
        return icon_;
    }
}
