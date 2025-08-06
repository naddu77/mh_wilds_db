#include "pch.h"
#include "ArmorSetBonusRank.h"
#include "ArmorSetBonusRank.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorSetBonusRank ArmorSetBonusRank::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"pieces"),
            winrt::MonsterHunterWilds::SkillRank::Parse(json_object.GetNamedObject(L"skill"))
        };
    }

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
