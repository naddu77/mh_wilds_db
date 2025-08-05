#pragma once
#include "Armor.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Armor : ArmorT<Armor>
    {
        static winrt::MonsterHunterWilds::Armor Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        Armor(
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
            winrt::MonsterHunterWilds::MiniArmorSet const& armor_set,
            winrt::MonsterHunterWilds::ArmorCrafting const& crafting);
        
        int32_t Id();
        hstring Name();
        hstring Description();
        winrt::MonsterHunterWilds::ArmorKind Kind();
        winrt::MonsterHunterWilds::Rank Rank();
        int32_t Rarity();
        winrt::MonsterHunterWilds::ArmorDefense Defense();
        winrt::MonsterHunterWilds::ArmorResistances Resistances();
        winrt::Windows::Foundation::Collections::IVector<int32_t> Slots();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Skills();
        winrt::MonsterHunterWilds::MiniArmorSet ArmorSet();
        winrt::MonsterHunterWilds::ArmorCrafting Crafting();

    private:
        int32_t id_;
        hstring name_;
        hstring description_;
        winrt::MonsterHunterWilds::ArmorKind kind_;
        winrt::MonsterHunterWilds::Rank rank_;
        int32_t rarity_;
        winrt::MonsterHunterWilds::ArmorDefense defense_;
        winrt::MonsterHunterWilds::ArmorResistances resistances_;
        winrt::Windows::Foundation::Collections::IVector<int32_t> slots_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> skills_;
        winrt::MonsterHunterWilds::MiniArmorSet armor_set_;
		winrt::MonsterHunterWilds::ArmorCrafting crafting_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Armor : ArmorT<Armor, implementation::Armor>
    {
    };
}
