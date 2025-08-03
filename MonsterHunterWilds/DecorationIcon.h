#pragma once
#include "DecorationIcon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct DecorationIcon : DecorationIconT<DecorationIcon>
    {
        DecorationIcon(winrt::MonsterHunterWilds::Color const& color, int32_t color_id);

        winrt::MonsterHunterWilds::Color Color();
        int32_t ColorId();

    private:
        winrt::MonsterHunterWilds::Color color_;
		int32_t color_id_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct DecorationIcon : DecorationIconT<DecorationIcon, implementation::DecorationIcon>
    {
    };
}
