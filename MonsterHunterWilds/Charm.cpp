#include "pch.h"
#include "Charm.h"
#include "Charm.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Charm Charm::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            winrt::MonsterHunterWilds::CharmRank::ParseJsonArray(json_object.GetNamedArray(L"ranks"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Charm> Charm::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    Charm::Charm(int32_t id, int32_t game_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> const& ranks)
        : id_{ id }, game_id_{ game_id }, ranks_{ ranks }
    {

	}

    int32_t Charm::Id()
    {
        return id_;
    }

    int32_t Charm::GameId()
    {
        return game_id_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> Charm::Ranks()
    {
        return ranks_;
    }
}
