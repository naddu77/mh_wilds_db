#pragma once
#include "ItemIcon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ItemIcon : ItemIconT<ItemIcon>
    {
        static winrt::MonsterHunterWilds::ItemIcon Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ItemIcon(int32_t game_id, winrt::MonsterHunterWilds::ItemIconKind const& kind, winrt::Windows::Foundation::IReference<int32_t> const& color_id, winrt::MonsterHunterWilds::Color const& color);

        int32_t GameId();
        winrt::MonsterHunterWilds::ItemIconKind Kind();
        winrt::Windows::Foundation::IReference<int32_t> ColorId();
        winrt::MonsterHunterWilds::Color Color();

    private:
        int32_t game_id_;
        winrt::MonsterHunterWilds::ItemIconKind kind_;
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
