#include "pch.h"
#include "Location.h"
#include "Location.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Location Location::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"zoneCount"),
            winrt::MonsterHunterWilds::Camp::ParseJsonArray(json_object.GetNamedArray(L"camps", winrt::Windows::Data::Json::JsonArray::Parse(L"[]")))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> Location::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::Location::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    Location::Location(int32_t id, int32_t gameId, hstring const& name, int32_t zoneCount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> const& camps)
		: id_{ id }, game_id_{ gameId }, name_{ name }, zone_count_{ zoneCount }, camps_{ camps }
    {
        
    }

    int32_t Location::Id()
    {
		return id_;
    }

    int32_t Location::GameId()
    {
        return game_id_;
    }

    hstring Location::Name()
    {
        return name_;
    }

    int32_t Location::ZoneCount()
    {
		return zone_count_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> Location::Camps()
    {
		return camps_;
    }
}
