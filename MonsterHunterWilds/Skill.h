#pragma once
#include "Skill.g.h"
#include "SkillRank.h"
#include "SkillIcon.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Skill : SkillT<Skill>
    {
        static winrt::MonsterHunterWilds::Skill Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        Skill(
            int32_t id,
            hstring const& name,
            hstring const& description,
            winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& ranks,
            winrt::MonsterHunterWilds::SkillKind const& kind,
            winrt::MonsterHunterWilds::SkillIcon const& icon);
        
        int32_t Id();
        hstring Name();
        hstring Description();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Ranks();
        winrt::MonsterHunterWilds::SkillKind Kind();
        winrt::MonsterHunterWilds::SkillIcon Icon();

    private:
        int32_t id_;
		hstring name_;
		hstring description_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> ranks_;
		winrt::MonsterHunterWilds::SkillKind kind_;
		winrt::MonsterHunterWilds::SkillIcon icon_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Skill : SkillT<Skill, implementation::Skill>
    {
    };
}
