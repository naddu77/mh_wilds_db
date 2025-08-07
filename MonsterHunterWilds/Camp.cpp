#include "pch.h"
#include "Camp.h"
#include "Camp.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Camp Camp::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"zone"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"floor"),
            winrt::MonsterHunterWilds::EnumMap::RiskMap(json_object.GetNamedString(L"risk")),
            winrt::MonsterHunterWilds::Position::Parse(json_object.GetNamedObject(L"position"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> Camp::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::Camp::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    Camp::Camp(int32_t id, hstring const& name, int32_t zone, int32_t floor, winrt::MonsterHunterWilds::Risk const& risk, winrt::MonsterHunterWilds::Position const& position)
        : id_{ id }, name_{ name }, zone_{ zone }, floor_{ floor }, risk_{ risk }, position_{ position }
    {
        
    }

    int32_t Camp::Id()
    {
        return id_;
    }

    hstring Camp::Name()
    {
        return name_;
    }

    int32_t Camp::Zone()
    {
        return zone_;
    }

    int32_t Camp::Floor()
    {
        return floor_;
    }

    winrt::MonsterHunterWilds::Risk Camp::Risk()
    {
        return risk_;
    }

    winrt::MonsterHunterWilds::Position Camp::Position()
    {
        return position_;
    }
}
