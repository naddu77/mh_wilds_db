#pragma once
#include "Bow.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Bow : BowT<Bow>
    {
        Bow(
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
            winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> const& coatings);

        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> Coatings();
        int32_t Id();
        int32_t GameId();
        winrt::MonsterHunterWilds::WeaponKind Kind();
        hstring Name();
        int32_t Rarity();
        winrt::MonsterHunterWilds::WeaponDamage Damage();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> Specials();
        winrt::MonsterHunterWilds::Sharpness Sharpness();
        winrt::Windows::Foundation::Collections::IVector<int32_t> Handicraft();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Skills();
        int32_t DefenseBonus();
        winrt::MonsterHunterWilds::Elderseal Elderseal();
        int32_t Affinity();
        winrt::Windows::Foundation::Collections::IVector<int32_t> Slots();
        winrt::MonsterHunterWilds::WeaponCrafting Crafting();
        winrt::MonsterHunterWilds::WeaponSeries Series();

    private:
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> coatings_;
        int32_t id_;
        int32_t game_id_;
        winrt::MonsterHunterWilds::WeaponKind kind_;
        hstring name_;
        int32_t rarity_;
        winrt::MonsterHunterWilds::WeaponDamage damage_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> specials_;
        winrt::MonsterHunterWilds::Sharpness sharpness_;
        winrt::Windows::Foundation::Collections::IVector<int32_t> handicraft_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> skills_;
        int32_t defense_bonus_;
        winrt::MonsterHunterWilds::Elderseal elderseal_;
        int32_t affinity_;
        winrt::Windows::Foundation::Collections::IVector<int32_t> slots_;
        winrt::MonsterHunterWilds::WeaponCrafting crafting_;
        winrt::MonsterHunterWilds::WeaponSeries series_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Bow : BowT<Bow, implementation::Bow>
    {
    };
}
