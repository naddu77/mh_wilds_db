#include "pch.h"
#include "SkillIcon.h"
#include "SkillIcon.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    SkillIcon::SkillIcon(int32_t game_id, winrt::MonsterHunterWilds::SkillKind const& kind)
        : game_id_{ game_id }, kind_{ kind }
    {

	}

    int32_t SkillIcon::GameId()
    {
		return game_id_;
    }

    winrt::MonsterHunterWilds::SkillKind SkillIcon::Kind()
    {
		return kind_;
    }
}
