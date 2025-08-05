#include "pch.h"
#include "WeaponCrafting.h"
#include "WeaponCrafting.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::WeaponCrafting WeaponCrafting::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            json_object.GetNamedBoolean(L"craftable"),
            TryParseNamedObject(json_object, L"previous", [](auto const& json_object) { return winrt::MonsterHunterWilds::MiniWeapon::Parse(json_object); }),
            ParseJsonArray(json_object.GetNamedArray(L"branches"), [](auto const& b) { return winrt::MonsterHunterWilds::MiniWeapon::Parse(b.GetObject()); }),
            static_cast<int32_t>(json_object.GetNamedNumber(L"craftingZennyCost")),
            ParseJsonArray(json_object.GetNamedArray(L"craftingMaterials"), [](auto const& m) { return winrt::MonsterHunterWilds::CraftingCost::Parse(m.GetObject()); }),
            static_cast<int32_t>(json_object.GetNamedNumber(L"upgradeZennyCost")),
            ParseJsonArray(json_object.GetNamedArray(L"upgradeMaterials"), [](auto const& m) { return winrt::MonsterHunterWilds::CraftingCost::Parse(m.GetObject()); }),
            static_cast<int32_t>(json_object.GetNamedNumber(L"row")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"column"))
        };
    }

    WeaponCrafting::WeaponCrafting(
        int32_t id,
        bool craftable,
        winrt::MonsterHunterWilds::MiniWeapon const& previous,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniWeapon> const& branches,
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

    winrt::MonsterHunterWilds::MiniWeapon WeaponCrafting::Previous()
    {
        return previous_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniWeapon> WeaponCrafting::Branches()
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
