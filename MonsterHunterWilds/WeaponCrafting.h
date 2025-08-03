#pragma once
#include "WeaponCrafting.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct WeaponCrafting : WeaponCraftingT<WeaponCrafting>
    {
        WeaponCrafting(int32_t id, bool craftable, winrt::MonsterHunterWilds::Weapon const& previous, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> const& branches, int32_t crafting_zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& crafting_materials, int32_t upgrade_zenny_cost, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& upgrade_materials, int32_t row, int32_t column);
        
        int32_t Id();
        bool Craftable();
        winrt::MonsterHunterWilds::Weapon Previous();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> Branches();
        int32_t CraftingZennyCost();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> CraftingMaterials();
        int32_t UpgradeZennyCost();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> UpgradeMaterials();
        int32_t Row();
        int32_t Column();

    private:
        int32_t id_;
        bool craftable_;
        winrt::MonsterHunterWilds::Weapon previous_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> branches_;
        int32_t crafting_zenny_cost_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> crafting_materials_;
        int32_t upgrade_zenny_cost_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> upgrade_materials_;
        int32_t row_;
        int32_t column_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct WeaponCrafting : WeaponCraftingT<WeaponCrafting, implementation::WeaponCrafting>
    {
    };
}
