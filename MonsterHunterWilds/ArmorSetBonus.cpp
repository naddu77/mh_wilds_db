#include "pch.h"
#include "ArmorSetBonus.h"
#include "ArmorSetBonus.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorSetBonus ArmorSetBonus::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::Skill::Parse(json_object.GetNamedObject(L"skill")),
            winrt::MonsterHunterWilds::JsonParser::ParseArmorSetBonusRanks(json_object.GetNamedArray(L"ranks"))
        };
    }

    winrt::MonsterHunterWilds::ArmorSetBonus ArmorSetBonus::TryParse(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto json_value{ json_object.GetNamedValue(key) };
                json_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Object)
            {
                return Parse(json_value.GetObject());
            }
        }

        return nullptr;
    }

    ArmorSetBonus::ArmorSetBonus(int32_t id, winrt::MonsterHunterWilds::Skill const& skill, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> const& ranks)
		: id_{ id }, skill_{ skill }, ranks_{ ranks }
    {
        
    }

    int32_t ArmorSetBonus::Id()
    {
        return id_;
    }

    winrt::MonsterHunterWilds::Skill ArmorSetBonus::Skill()
    {
        return skill_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> ArmorSetBonus::Ranks()
    {
        return ranks_;
    }
}
