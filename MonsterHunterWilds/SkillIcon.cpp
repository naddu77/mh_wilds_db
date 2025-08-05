#include "pch.h"
#include "SkillIcon.h"
#include "SkillIcon.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::SkillIcon SkillIcon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            winrt::MonsterHunterWilds::EnumMap::SkillIconKindMap(json_object.GetNamedString(L"kind"))
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
