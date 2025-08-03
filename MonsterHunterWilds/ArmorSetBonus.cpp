#include "pch.h"
#include "ArmorSetBonus.h"
#include "ArmorSetBonus.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    ArmorSetBonus::ArmorSetBonus(int32_t id, winrt::MonsterHunterWilds::Skill const& skill, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> const& ranks)
		: id_{ id }, skill_{ skill }, ranks_{ ranks }
    {
        
    }

    int32_t ArmorSetBonus::Id()
    {
        return id_;
    }

    winrt::MonsterHunterWilds::Skill ArmorSetBonus::Skill()
    {
        return skill_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> ArmorSetBonus::Ranks()
    {
        return ranks_;
    }
}
