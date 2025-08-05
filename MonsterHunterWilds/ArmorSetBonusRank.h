#pragma once
#include "ArmorSetBonusRank.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorSetBonusRank : ArmorSetBonusRankT<ArmorSetBonusRank>
    {
        static winrt::MonsterHunterWilds::ArmorSetBonusRank Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ArmorSetBonusRank(int32_t id, int32_t pieces, winrt::MonsterHunterWilds::SkillRank const& skill);

        int32_t Id();
        int32_t Pieces();
        winrt::MonsterHunterWilds::SkillRank Skill();

    private:
        int32_t id_;
        int32_t pieces_;
		winrt::MonsterHunterWilds::SkillRank skill_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorSetBonusRank : ArmorSetBonusRankT<ArmorSetBonusRank, implementation::ArmorSetBonusRank>
    {
    };
}
