#include "pch.h"
#include "SkillRank.h"
#include "SkillRank.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::SkillRank SkillRank::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            TryGetNamedString(json_object, L"name"),
            json_object.GetNamedString(L"description"),
            static_cast<int32_t>(json_object.GetNamedNumber(L"level"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> SkillRank::TryParse(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            return winrt::single_threaded_vector(
                json_object.GetNamedArray(key)
                | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
                | std::ranges::to<std::vector>()
            );
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
