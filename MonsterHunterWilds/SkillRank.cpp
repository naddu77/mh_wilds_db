#include "pch.h"
#include "SkillRank.h"
#include "SkillRank.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::SkillRank SkillRank::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"name"),
            json_object.GetNamedString(L"description"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"level")
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> SkillRank::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> SkillRank::TryParse(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            return ParseJsonArray(json_object.GetNamedArray(key));
        }

        return nullptr;
    }

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
