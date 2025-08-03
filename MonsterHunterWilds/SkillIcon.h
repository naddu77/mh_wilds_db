#pragma once
#include "SkillIcon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct SkillIcon : SkillIconT<SkillIcon>
    {
        SkillIcon(int32_t game_id, winrt::MonsterHunterWilds::SkillKind const& kind);

        int32_t GameId();
        winrt::MonsterHunterWilds::SkillKind Kind();

    private:
        int32_t game_id_;
		winrt::MonsterHunterWilds::SkillKind kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct SkillIcon : SkillIconT<SkillIcon, implementation::SkillIcon>
    {
    };
}
