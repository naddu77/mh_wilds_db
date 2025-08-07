#include "pch.h"
#include "StatusWeakness.h"
#include "StatusWeakness.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterWeakness StatusWeakness::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::StatusWeakness{
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"level"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"condition"),
            winrt::MonsterHunterWilds::EnumMap::StatusMap(json_object.GetNamedString(L"status"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> StatusWeakness::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::StatusWeakness::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    StatusWeakness::StatusWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Status const& status)
        : id_{ id }, level_{ level }, condition_{ condition }, status_{ status }
    {
        
    }

    winrt::MonsterHunterWilds::Status StatusWeakness::Status()
    {
		return status_;
    }

    int32_t StatusWeakness::Id()
    {
		return id_;
    }

    int32_t StatusWeakness::Level()
    {
		return level_;
    }

    hstring StatusWeakness::Condition()
    {
		return condition_;
    }

    winrt::MonsterHunterWilds::WeaknessKind StatusWeakness::Kind()
    {
		return winrt::MonsterHunterWilds::WeaknessKind::Status;
    }
}
