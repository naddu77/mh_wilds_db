#include "pch.h"
#include "ItemIcon.h"
#include "ItemIcon.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ItemIcon ItemIcon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::EnumMap::ItemIconKindMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedInt32(json_object, L"colorId"),
            winrt::MonsterHunterWilds::EnumMap::ColorMap(json_object.GetNamedString(L"color"))
        };
    }

    ItemIcon::ItemIcon(int32_t game_id, winrt::MonsterHunterWilds::ItemIconKind const& kind, winrt::Windows::Foundation::IReference<int32_t> const& color_id, winrt::MonsterHunterWilds::Color const& color)
        : game_id_{ game_id }, kind_{ kind }, color_id_{ color_id }, color_{ color }
    {

	}

    int32_t ItemIcon::GameId()
    {
		return game_id_;
    }

    winrt::MonsterHunterWilds::ItemIconKind ItemIcon::Kind()
    {
		return kind_;
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
