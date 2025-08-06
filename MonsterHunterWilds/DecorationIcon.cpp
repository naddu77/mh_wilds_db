#include "pch.h"
#include "DecorationIcon.h"
#include "DecorationIcon.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::DecorationIcon DecorationIcon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::EnumMap::ColorMap(json_object.GetNamedString(L"color")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"colorId")
        };
    }

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
