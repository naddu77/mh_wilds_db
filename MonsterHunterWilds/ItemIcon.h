#pragma once
#include "ItemIcon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ItemIcon : ItemIconT<ItemIcon>
    {
        ItemIcon(int32_t game_id, winrt::MonsterHunterWilds::ItemIconKind const& name, winrt::Windows::Foundation::IReference<int32_t> const& color_id, winrt::MonsterHunterWilds::Color const& color);

        int32_t GameId();
        winrt::MonsterHunterWilds::ItemIconKind Name();
        winrt::Windows::Foundation::IReference<int32_t> ColorId();
        winrt::MonsterHunterWilds::Color Color();

    private:
        int32_t game_id_;
        winrt::MonsterHunterWilds::ItemIconKind name_;
        winrt::Windows::Foundation::IReference<int32_t> color_id_;
		winrt::MonsterHunterWilds::Color color_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ItemIcon : ItemIconT<ItemIcon, implementation::ItemIcon>
    {
    };
}
