#pragma once
#include "SkillRank.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct SkillRank : SkillRankT<SkillRank>
    {
        static winrt::MonsterHunterWilds::SkillRank Parse(winrt::Windows::Data::Json::JsonObject const& json);

        SkillRank(int32_t id, hstring const& name, hstring const& description, int32_t level);

        int32_t Id();
        hstring Name();
        hstring Description();
        int32_t Level();

    private:
        int32_t id_;
        hstring name_;
        hstring description_;
		int32_t level_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct SkillRank : SkillRankT<SkillRank, implementation::SkillRank>
    {
    };
}
