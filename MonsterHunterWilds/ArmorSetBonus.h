#pragma once
#include "ArmorSetBonus.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorSetBonus : ArmorSetBonusT<ArmorSetBonus>
    {
        static winrt::MonsterHunterWilds::ArmorSetBonus Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ArmorSetBonus(int32_t id, winrt::MonsterHunterWilds::Skill const& skill, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> const& ranks);

        int32_t Id();
        winrt::MonsterHunterWilds::Skill Skill();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> Ranks();

	private:
        int32_t id_;
        winrt::MonsterHunterWilds::Skill skill_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> ranks_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorSetBonus : ArmorSetBonusT<ArmorSetBonus, implementation::ArmorSetBonus>
    {
    };
}
