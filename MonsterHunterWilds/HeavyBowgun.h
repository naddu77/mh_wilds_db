#pragma once
#include "HeavyBowgun.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HeavyBowgun : HeavyBowgunT<HeavyBowgun>
    {
        static winrt::MonsterHunterWilds::HeavyBowgun Parse(winrt::Windows::Data::Json::JsonObject const& json_object);        

        HeavyBowgun(
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
            winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> elderseal,
            int32_t affinity,
            winrt::Windows::Foundation::Collections::IVector<int32_t> const& slots,
            winrt::MonsterHunterWilds::WeaponCrafting const& crafting,
            winrt::MonsterHunterWilds::WeaponSeries const& series,
            winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> const& ammo);
        
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> Ammo();
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
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> Elderseal();
        int32_t Affinity();
        winrt::Windows::Foundation::Collections::IVector<int32_t> Slots();
        winrt::MonsterHunterWilds::WeaponCrafting Crafting();
        winrt::MonsterHunterWilds::WeaponSeries Series();

    private:
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> ammo_;
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
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> elderseal_;
        int32_t affinity_;
        winrt::Windows::Foundation::Collections::IVector<int32_t> slots_;
        winrt::MonsterHunterWilds::WeaponCrafting crafting_;
        winrt::MonsterHunterWilds::WeaponSeries series_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HeavyBowgun : HeavyBowgunT<HeavyBowgun, implementation::HeavyBowgun>
    {
    };
}
