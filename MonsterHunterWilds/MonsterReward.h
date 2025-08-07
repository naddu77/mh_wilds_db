#pragma once
#include "MonsterReward.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MonsterReward : MonsterRewardT<MonsterReward>
    {
		static winrt::MonsterHunterWilds::MonsterReward Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
		static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        MonsterReward(winrt::MonsterHunterWilds::Item const& item, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> const& conditions);

        winrt::MonsterHunterWilds::Item Item();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> Conditions();

    private:
        winrt::MonsterHunterWilds::Item item_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> conditions_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MonsterReward : MonsterRewardT<MonsterReward, implementation::MonsterReward>
    {
    };
}
