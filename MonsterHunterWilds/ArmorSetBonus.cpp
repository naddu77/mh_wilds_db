#include "pch.h"
#include "ArmorSetBonus.h"
#include "ArmorSetBonus.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorSetBonus ArmorSetBonus::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            winrt::MonsterHunterWilds::Skill::Parse(json_object.GetNamedObject(L"skill")),
            ParseJsonArray(json_object.GetNamedArray(L"ranks"), [](auto const& json_value) { return winrt::MonsterHunterWilds::ArmorSetBonusRank::Parse(json_value.GetObject()); })
        };
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
