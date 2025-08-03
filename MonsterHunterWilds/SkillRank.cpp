#include "pch.h"
#include "SkillRank.h"
#include "SkillRank.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    SkillRank::SkillRank(int32_t id, hstring const& name, hstring const& description, int32_t level)
        : id_{ id }, name_{ name }, description_{ description }, level_{ level }
    {

	}

    int32_t SkillRank::Id()
    {
		return id_;
    }

    hstring SkillRank::Name()
    {
		return name_;
    }

    hstring SkillRank::Description()
    {
		return description_;
    }

    int32_t SkillRank::Level()
    {
		return level_;
    }
}
