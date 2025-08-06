#include "pch.h"
#include "Skill.h"
#include "Skill.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Skill Skill::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"description"),
            winrt::MonsterHunterWilds::SkillRank::TryParse(json_object, L"ranks"),
            json_object.HasKey(L"kind") ? winrt::MonsterHunterWilds::EnumMap::SkillKindMap(json_object.GetNamedString(L"kind")) : winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::SkillKind>{},
            winrt::MonsterHunterWilds::SkillIcon::TryParse(json_object, L"icon")
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill> Skill::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    Skill::Skill(
        int32_t id,
        hstring const& name,
        hstring const& description,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& ranks,
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::SkillKind> const& kind,
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

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::SkillKind> Skill::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::SkillIcon Skill::Icon()
    {
        return icon_;
    }
}
