#include "pch.h"
#include "MonsterReward.h"
#include "MonsterReward.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterReward MonsterReward::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::Item::Parse(json_object.GetNamedObject(L"item")),
            winrt::MonsterHunterWilds::RewardCondition::ParseJsonArray(json_object.GetNamedArray(L"conditions"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> MonsterReward::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
			| std::views::transform([](winrt::Windows::Data::Json::IJsonValue const& json_value) { return Parse(json_value.GetObject()); })
			| std::ranges::to<std::vector>()
        );
    }

    MonsterReward::MonsterReward(winrt::MonsterHunterWilds::Item const& item, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> const& conditions)
		: item_{ item }, conditions_{ conditions }
    {
        
    }

    winrt::MonsterHunterWilds::Item MonsterReward::Item()
    {
		return item_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> MonsterReward::Conditions()
    {
        return conditions_;
    }
}
