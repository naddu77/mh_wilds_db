#include "pch.h"
#include "ArmorSetBonusRank.h"
#include "ArmorSetBonusRank.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    ArmorSetBonusRank::ArmorSetBonusRank(int32_t id, int32_t pieces, winrt::MonsterHunterWilds::SkillRank const& skill)
        : id_{ id }, pieces_{ pieces }, skill_{ skill }
    {

	}

    int32_t ArmorSetBonusRank::Id()
    {
        return id_;
    }

    int32_t ArmorSetBonusRank::Pieces()
    {
        return pieces_;
    }

    winrt::MonsterHunterWilds::SkillRank ArmorSetBonusRank::Skill()
    {
        return skill_;
    }
}
