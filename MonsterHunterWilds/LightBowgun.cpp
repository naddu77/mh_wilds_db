#include "pch.h"
#include "LightBowgun.h"
#include "LightBowgun.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    LightBowgun::LightBowgun(
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
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::LightBowgunAmmo> const& ammo,
        winrt::MonsterHunterWilds::LightBowgunSpecialAmmo const& special_ammo)
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
        , ammo_{ ammo }
        , special_ammo_{ special_ammo }
    {
        
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::LightBowgunAmmo> LightBowgun::Ammo()
    {
        return ammo_;
    }

    winrt::MonsterHunterWilds::LightBowgunSpecialAmmo LightBowgun::SpecialAmmo()
    {
        return special_ammo_;
    }
    
    int32_t LightBowgun::Id()
    {
        return id_;
    }

    int32_t LightBowgun::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind LightBowgun::Kind()
    {
        return kind_;
    }

    hstring LightBowgun::Name()
    {
        return name_;
    }

    int32_t LightBowgun::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage LightBowgun::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> LightBowgun::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness LightBowgun::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> LightBowgun::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> LightBowgun::Skills()
    {
        return skills_;
    }

    int32_t LightBowgun::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::MonsterHunterWilds::Elderseal LightBowgun::Elderseal()
    {
        return elderseal_;
    }

    int32_t LightBowgun::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> LightBowgun::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting LightBowgun::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries LightBowgun::Series()
    {
        return series_;
    }
}
