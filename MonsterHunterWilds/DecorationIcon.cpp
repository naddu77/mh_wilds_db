#include "pch.h"
#include "DecorationIcon.h"
#include "DecorationIcon.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    DecorationIcon::DecorationIcon(winrt::MonsterHunterWilds::Color const& color, int32_t color_id)
        : color_{ color }, color_id_{ color_id }
    {

	}

    winrt::MonsterHunterWilds::Color DecorationIcon::Color()
    {
        return color_;
    }

    int32_t DecorationIcon::ColorId()
    {
        return color_id_;
    }
}
