#pragma once
#include "CharmRank.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct CharmRank : CharmRankT<CharmRank>
    {
        static winrt::MonsterHunterWilds::CharmRank Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        CharmRank(int32_t id, hstring const& name, hstring const& description, int32_t level, int32_t rarity, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills, winrt::MonsterHunterWilds::CharmRankCrafting const& crafting);
        
        int32_t Id();
        hstring Name();
        hstring Description();
        int32_t Level();
        int32_t Rarity();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Skills();
        winrt::MonsterHunterWilds::CharmRankCrafting Crafting();

    private:
        int32_t id_;
        hstring name_;
        hstring description_;
        int32_t level_;
        int32_t rarity_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> skills_;
		winrt::MonsterHunterWilds::CharmRankCrafting crafting_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct CharmRank : CharmRankT<CharmRank, implementation::CharmRank>
    {
    };
}
