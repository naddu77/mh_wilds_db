#include "pch.h"
#include "SkillIcon.h"
#include "SkillIcon.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::SkillIcon SkillIcon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::SkillIconKind> skill_icon_kind_map{
            { L"affinity", winrt::MonsterHunterWilds::SkillIconKind::Affinity },
            { L"attack", winrt::MonsterHunterWilds::SkillIconKind::Attack },
            { L"defense", winrt::MonsterHunterWilds::SkillIconKind::Defense },
            { L"element", winrt::MonsterHunterWilds::SkillIconKind::Element },
            { L"gathering", winrt::MonsterHunterWilds::SkillIconKind::Gathering },
            { L"group", winrt::MonsterHunterWilds::SkillIconKind::Group },
            { L"handicraft", winrt::MonsterHunterWilds::SkillIconKind::Handicraft },
            { L"health", winrt::MonsterHunterWilds::SkillIconKind::Health },
            { L"item", winrt::MonsterHunterWilds::SkillIconKind::Item },
            { L"offense", winrt::MonsterHunterWilds::SkillIconKind::Offense },
            { L"ranged", winrt::MonsterHunterWilds::SkillIconKind::Ranged },
            { L"set", winrt::MonsterHunterWilds::SkillIconKind::Set },
            { L"stamina", winrt::MonsterHunterWilds::SkillIconKind::Stamina },
            { L"utility", winrt::MonsterHunterWilds::SkillIconKind::Utility }
        };

        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            skill_icon_kind_map[json_object.GetNamedString(L"kind")]
        };
    }

    SkillIcon::SkillIcon(int32_t game_id, winrt::MonsterHunterWilds::SkillIconKind const& kind)
        : game_id_{ game_id }, kind_{ kind }
    {

	}

    int32_t SkillIcon::GameId()
    {
		return game_id_;
    }

    winrt::MonsterHunterWilds::SkillIconKind SkillIcon::Kind()
    {
		return kind_;
    }
}
