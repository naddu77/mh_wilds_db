#include "pch.h"
#include "CharmRank.h"
#include "CharmRank.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    CharmRank::CharmRank(int32_t id, hstring const& name, hstring const& description, int32_t level, int32_t rarity, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills, winrt::MonsterHunterWilds::CharmRankCrafting const& crafting)
        : id_{ id }, name_{ name }, description_{ description }, level_{ level }, rarity_{ rarity }, skills_{ skills }, crafting_{ crafting }
    {

	}

    int32_t CharmRank::Id()
    {
        return id_;
    }

    hstring CharmRank::Name()
    {
        return name_;
    }

    hstring CharmRank::Description()
    {
        return description_;
    }

    int32_t CharmRank::Level()
    {
        return level_;
    }

    int32_t CharmRank::Rarity()
    {
        return rarity_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> CharmRank::Skills()
    {
        return skills_;
    }

    winrt::MonsterHunterWilds::CharmRankCrafting CharmRank::Crafting()
    {
        return crafting_;
    }
}
