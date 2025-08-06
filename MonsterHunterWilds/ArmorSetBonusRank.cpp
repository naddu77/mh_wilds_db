#include "pch.h"
#include "ArmorSetBonusRank.h"
#include "ArmorSetBonusRank.g.cpp"

import std;

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

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> ArmorSetBonusRank::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
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
