#include "pch.h"
#include "ItemIcon.h"
#include "ItemIcon.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    ItemIcon::ItemIcon(int32_t game_id, winrt::MonsterHunterWilds::ItemIconKind const& name, winrt::Windows::Foundation::IReference<int32_t> const& color_id, winrt::MonsterHunterWilds::Color const& color)
        : game_id_{ game_id }, name_{ name }, color_id_{ color_id }, color_{ color }
    {

	}

    int32_t ItemIcon::GameId()
    {
		return game_id_;
    }

    winrt::MonsterHunterWilds::ItemIconKind ItemIcon::Name()
    {
		return name_;
    }

    winrt::Windows::Foundation::IReference<int32_t> ItemIcon::ColorId()
    {
		return color_id_;
    }

    winrt::MonsterHunterWilds::Color ItemIcon::Color()
    {
		return color_;
    }
}
