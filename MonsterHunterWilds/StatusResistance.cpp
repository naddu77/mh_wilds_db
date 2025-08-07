#include "pch.h"
#include "StatusResistance.h"
#include "StatusResistance.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterResistance StatusResistance::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::StatusResistance{
			winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"condition"),
            winrt::MonsterHunterWilds::EnumMap::StatusMap(json_object.GetNamedString(L"status"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> StatusResistance::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::StatusResistance::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    StatusResistance::StatusResistance(int32_t id, hstring condition, winrt::MonsterHunterWilds::Status const& status)
        : status_{ status }, id_{ id }, condition_{ condition }, kind_{ winrt::MonsterHunterWilds::ResistanceKind::Status }
    {
        
    }

    winrt::MonsterHunterWilds::Status StatusResistance::Status()
    {
        return status_;
    }

    int32_t StatusResistance::Id()
    {
        return id_;
    }

    hstring StatusResistance::Condition()
    {
        return condition_;
    }

    winrt::MonsterHunterWilds::ResistanceKind StatusResistance::Kind()
    {
        return kind_;
    }
}
