#include "pch.h"
#include "Skill.h"
#include "Skill.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Skill Skill::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::SkillKind> skill_kind_map{
            { L"armor", winrt::MonsterHunterWilds::SkillKind::Armor },
            { L"weapon", winrt::MonsterHunterWilds::SkillKind::Weapon },
            { L"set", winrt::MonsterHunterWilds::SkillKind::Set },
            { L"group", winrt::MonsterHunterWilds::SkillKind::Group }
        };
        
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            json_object.GetNamedString(L"name"),
            TryGetNamedString(json_object, L"description"),
            ParseJsonArray(json_object.GetNamedArray(L"ranks"), [](auto const& r) { return SkillRank::Parse(r.GetObject()); }),
            skill_kind_map[json_object.GetNamedString(L"kind")],
            winrt::MonsterHunterWilds::SkillIcon::Parse(json_object.GetNamedObject(L"icon"))
        };
    }

    Skill::Skill(
        int32_t id,
        hstring const& name,
        hstring const& description,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& ranks,
        winrt::MonsterHunterWilds::SkillKind const& kind,
        winrt::MonsterHunterWilds::SkillIcon const& icon)
        : id_{ id }
        , name_{ name }
		, description_{ description }
        , ranks_{ ranks }
        , kind_{ kind }
        , icon_{ icon }
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
