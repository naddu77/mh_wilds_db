#include "pch.h"
#include "SwitchAxe.h"
#include "SwitchAxe.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    SwitchAxe::SwitchAxe(
        int32_t id,
        int32_t game_id,
        winrt::MonsterHunterWilds::WeaponKind const& kind,
        hstring const& name,
        int32_t rarity,
        winrt::MonsterHunterWilds::WeaponDamage const& damage,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> const& specials,
        winrt::MonsterHunterWilds::Sharpness const& sharpness,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& handicraft,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills,
        int32_t defense_bonus,
        winrt::MonsterHunterWilds::Elderseal const& elderseal,
        int32_t affinity,
        winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
        winrt::MonsterHunterWilds::WeaponCrafting const& crafting,
        winrt::MonsterHunterWilds::WeaponSeries const& series,
        winrt::MonsterHunterWilds::SwitchAxePhial const& phial)
        : id_{ id }
        , game_id_{ game_id }
        , kind_{ kind }
        , name_{ name }
        , rarity_{ rarity }
        , damage_{ damage }
        , specials_{ specials }
        , sharpness_{ sharpness }
        , handicraft_{ handicraft }
        , skills_{ skills }
        , defense_bonus_{ defense_bonus }
        , elderseal_{ elderseal }
        , affinity_{ affinity }
        , slots_{ slots }
        , crafting_{ crafting }
        , series_{ series }
        , phial_{ phial }
    {
        
    }

    winrt::MonsterHunterWilds::SwitchAxePhial SwitchAxe::Phial()
    {
        return phial_;
    }

    int32_t SwitchAxe::Id()
    {
        return id_;
    }

    int32_t SwitchAxe::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind SwitchAxe::Kind()
    {
        return kind_;
    }

    hstring SwitchAxe::Name()
    {
        return name_;
    }

    int32_t SwitchAxe::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage SwitchAxe::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> SwitchAxe::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness SwitchAxe::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> SwitchAxe::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> SwitchAxe::Skills()
    {
        return skills_;
    }

    int32_t SwitchAxe::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::MonsterHunterWilds::Elderseal SwitchAxe::Elderseal()
    {
        return elderseal_;
    }

    int32_t SwitchAxe::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> SwitchAxe::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting SwitchAxe::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries SwitchAxe::Series()
    {
        return series_;
    }
}
