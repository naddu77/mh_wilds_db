#include "pch.h"
#include "Armor.h"
#include "Armor.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Armor::Armor(
        int32_t id,
        hstring const& name,
        hstring const& description,
        winrt::MonsterHunterWilds::ArmorKind const& kind,
        winrt::MonsterHunterWilds::Rank const& rank,
        int32_t rarity,
        winrt::MonsterHunterWilds::ArmorDefense const& defense,
        winrt::MonsterHunterWilds::ArmorResistances const& resistances,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills,
        winrt::MonsterHunterWilds::ArmorSet const& armor_set,
        winrt::MonsterHunterWilds::ArmorCrafting const& crafting)
        : id_{ id }
        , name_{ name }
        , description_{ description }
        , kind_{ kind }
        , rank_{ rank }
        , rarity_{ rarity }
        , defense_{ defense }
        , resistances_{ resistances }
        , slots_{ slots }
        , skills_{ skills }
        , armor_set_{ armor_set }
        , crafting_{ crafting }
    {

	}

    int32_t Armor::Id()
    {
        return id_;
    }

    hstring Armor::Name()
    {
        return name_;
    }

    hstring Armor::Description()
    {
        return description_;
    }

    winrt::MonsterHunterWilds::ArmorKind Armor::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::Rank Armor::Rank()
    {
        return rank_;
    }

    int32_t Armor::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::ArmorDefense Armor::Defense()
    {
        return defense_;
    }

    winrt::MonsterHunterWilds::ArmorResistances Armor::Resistances()
    {
        return resistances_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Armor::Slots()
    {
        return slots_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Armor::Skills()
    {
        return skills_;
    }

    winrt::MonsterHunterWilds::ArmorSet Armor::ArmorSet()
    {
        return armor_set_;
    }

    winrt::MonsterHunterWilds::ArmorCrafting Armor::Crafting()
    {
        return crafting_;
    }
}
