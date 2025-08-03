#include "pch.h"
#include "Gunlance.h"
#include "Gunlance.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Gunlance::Gunlance(
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
        winrt::MonsterHunterWilds::GunlanceShell const& shell,
        int32_t shell_level)
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
        , shell_{ shell }
        , shell_level_{ shell_level }
    {
        
    }

    winrt::MonsterHunterWilds::GunlanceShell Gunlance::Shell()
    {
        return shell_;
    }

    int32_t Gunlance::ShellLevel()
    {
        return shell_level_;
    }

    int32_t Gunlance::Id()
    {
        return id_;
    }

    int32_t Gunlance::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind Gunlance::Kind()
    {
        return kind_;
    }

    hstring Gunlance::Name()
    {
        return name_;
    }

    int32_t Gunlance::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage Gunlance::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> Gunlance::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness Gunlance::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Gunlance::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Gunlance::Skills()
    {
        return skills_;
    }

    int32_t Gunlance::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::MonsterHunterWilds::Elderseal Gunlance::Elderseal()
    {
        return elderseal_;
    }

    int32_t Gunlance::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> Gunlance::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting Gunlance::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries Gunlance::Series()
    {
        return series_;
    }
}
