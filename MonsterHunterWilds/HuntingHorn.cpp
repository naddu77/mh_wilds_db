#include "pch.h"
#include "HuntingHorn.h"
#include "HuntingHorn.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    HuntingHorn::HuntingHorn(
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
        winrt::MonsterHunterWilds::HuntingHornMelody const& melody,
        winrt::MonsterHunterWilds::HuntingHornBubble const& echo_bubble,
        winrt::MonsterHunterWilds::HuntingHornWave const& echo_wave)
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
        , melody_{ melody }
        , echo_bubble_{ echo_bubble }
        , echo_wave_{ echo_wave }
    {
        
    }

    winrt::MonsterHunterWilds::HuntingHornMelody HuntingHorn::Melody()
    {
        return melody_;
    }

    winrt::MonsterHunterWilds::HuntingHornBubble HuntingHorn::EchoBubble()
    {
        return echo_bubble_;
    }

    winrt::MonsterHunterWilds::HuntingHornWave HuntingHorn::EchoWave()
    {
        return echo_wave_;
    }

    int32_t HuntingHorn::Id()
    {
        return id_;
    }

    int32_t HuntingHorn::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::WeaponKind HuntingHorn::Kind()
    {
        return kind_;
    }

    hstring HuntingHorn::Name()
    {
        return name_;
    }

    int32_t HuntingHorn::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::WeaponDamage HuntingHorn::Damage()
    {
        return damage_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> HuntingHorn::Specials()
    {
        return specials_;
    }

    winrt::MonsterHunterWilds::Sharpness HuntingHorn::Sharpness()
    {
        return sharpness_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> HuntingHorn::Handicraft()
    {
        return handicraft_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> HuntingHorn::Skills()
    {
        return skills_;
    }

    int32_t HuntingHorn::DefenseBonus()
    {
        return defense_bonus_;
    }

    winrt::MonsterHunterWilds::Elderseal HuntingHorn::Elderseal()
    {
        return elderseal_;
    }

    int32_t HuntingHorn::Affinity()
    {
        return affinity_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> HuntingHorn::Slots()
    {
        return slots_;
    }

    winrt::MonsterHunterWilds::WeaponCrafting HuntingHorn::Crafting()
    {
        return crafting_;
    }

    winrt::MonsterHunterWilds::WeaponSeries HuntingHorn::Series()
    {
        return series_;
    }
}
