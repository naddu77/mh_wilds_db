#include "pch.h"
#include "RewardCondition.h"
#include "RewardCondition.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::RewardCondition RewardCondition::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::EnumMap::RewardConditionKindMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::EnumMap::RankMap(json_object.GetNamedString(L"rank")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"quantity"),
            json_object.GetNamedNumber(L"chance"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"part")
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> RewardCondition::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::RewardCondition::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    RewardCondition::RewardCondition(winrt::MonsterHunterWilds::RewardConditionKind const& kind, winrt::MonsterHunterWilds::Rank const& rank, int32_t quantity, double chance, hstring const& part)
		: kind_{ kind }, rank_{ rank }, quantity_{ quantity }, chance_{ chance }, part_{ part }
    {
        
    }

    winrt::MonsterHunterWilds::RewardConditionKind RewardCondition::Kind()
    {
		return kind_;
    }

    winrt::MonsterHunterWilds::Rank RewardCondition::Rank()
    {
		return rank_;
    }

    int32_t RewardCondition::Quantity()
    {
		return quantity_;
    }

    double RewardCondition::Chance()
    {
		return chance_;
    }

    hstring RewardCondition::Part()
    {
		return part_;
    }
}
