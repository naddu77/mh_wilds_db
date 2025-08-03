#include "pch.h"
#include "Skill.h"
#include "Skill.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Skill::Skill(
        int32_t id,
        hstring const& name,
        hstring const& description,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& ranks,
        winrt::MonsterHunterWilds::SkillKind const& kind,
        winrt::MonsterHunterWilds::SkillIcon const& icon)
        : id_{ id }
        , name_{ name }
		, description_{ description },
        ranks_{ ranks },
        kind_{ kind },
        icon_{ icon }
    {
        
    }

    int32_t Skill::Id()
    {
		return id_;
    }

    hstring Skill::Name()
    {
		return name_;
    }

    hstring Skill::Description()
    {
		return description_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Skill::Ranks()
    {
		return ranks_;
    }

    winrt::MonsterHunterWilds::SkillKind Skill::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::SkillIcon Skill::Icon()
    {
        return icon_;
    }
}
