#pragma once
#include "RewardCondition.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct RewardCondition : RewardConditionT<RewardCondition>
    {
        static winrt::MonsterHunterWilds::RewardCondition Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::RewardCondition> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        RewardCondition(winrt::MonsterHunterWilds::RewardConditionKind const& kind, winrt::MonsterHunterWilds::Rank const& rank, int32_t quantity, double chance, hstring const& part);

        winrt::MonsterHunterWilds::RewardConditionKind Kind();
        winrt::MonsterHunterWilds::Rank Rank();
        int32_t Quantity();
        double Chance();
        hstring Part();

    private:
        winrt::MonsterHunterWilds::RewardConditionKind kind_;
        winrt::MonsterHunterWilds::Rank rank_;
        int32_t quantity_;
        double chance_;
		hstring part_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct RewardCondition : RewardConditionT<RewardCondition, implementation::RewardCondition>
    {
    };
}
