#include "pch.h"
#include "WeaponCrafting.h"
#include "WeaponCrafting.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    WeaponCrafting::WeaponCrafting(
        int32_t id,
        bool craftable,
        winrt::MonsterHunterWilds::Weapon const& previous,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> const& branches,
        int32_t crafting_zenny_cost,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& crafting_materials,
        int32_t upgrade_zenny_cost,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> const& upgrade_materials,
        int32_t row,
        int32_t column)
        : id_{ id }
        , craftable_{ craftable }
        , previous_{ previous }
        , branches_{ branches }
        , crafting_zenny_cost_{ crafting_zenny_cost }
        , crafting_materials_{ crafting_materials }
        , upgrade_zenny_cost_{ upgrade_zenny_cost }
        , upgrade_materials_{ upgrade_materials }
        , row_{ row }
        , column_{ column }
    {
        
    }

    int32_t WeaponCrafting::Id()
    {
        return id_;
    }
    bool WeaponCrafting::Craftable()
    {
        return craftable_;
    }

    winrt::MonsterHunterWilds::Weapon WeaponCrafting::Previous()
    {
        return previous_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> WeaponCrafting::Branches()
    {
        return branches_;
    }

    int32_t WeaponCrafting::CraftingZennyCost()
    {
        return crafting_zenny_cost_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> WeaponCrafting::CraftingMaterials()
    {
        return crafting_materials_;
    }

    int32_t WeaponCrafting::UpgradeZennyCost()
    {
        return upgrade_zenny_cost_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CraftingCost> WeaponCrafting::UpgradeMaterials()
    {
        return upgrade_materials_;
    }

    int32_t WeaponCrafting::Row()
    {
        return row_;
    }

    int32_t WeaponCrafting::Column()
    {
        return column_;
    }
}
