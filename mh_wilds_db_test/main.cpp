#include "pch.h"
#include <winrt/MonsterHunterWilds.h>

import std;

winrt::Windows::Foundation::IAsyncAction TestArmors()
{
    winrt::MonsterHunterWilds::Database db;
    auto armors{ co_await db.GetArmorsAsync() };

    for (auto const& armor : armors)
    {
        std::wcout << std::format(L"Armor ID: {}, Name: {}, Kind: {}, Description: {}\n",
            armor.Id(), armor.Name(), std::to_underlying(armor.Kind()), armor.Description());

        auto const& armor_resistances{ armor.Resistances() };

        std::wcout << std::format(L"  AmorResistances: [{}, {}, {}, {}, {}]\n",
            armor_resistances.Fire(), armor_resistances.Water(), armor_resistances.Ice(), armor_resistances.Thunder(), armor_resistances.Dragon()
        );

        std::wcout << std::format(L"  Slots: {}\n", armor.Slots());

        for (auto const& skill : armor.Skills())
        {
            std::wcout << std::format(L"  Skill ID: {}, Name: {}, Level: {}, Description: {}\n", skill.Id(), skill.Name(), skill.Level(), skill.Description());
        }
    }
}

winrt::Windows::Foundation::IAsyncAction TestArmorSets()
{
    winrt::MonsterHunterWilds::Database db;
    auto armor_sets{ co_await db.GetArmorSetsAsync() };

    for (auto const& armor_set : armor_sets)
    {
        std::wcout << std::format(L"Armor Set ID: {}, Name: {}\n",
            armor_set.Id(), armor_set.Name());

        for (auto const& piece : armor_set.Pieces())
        {
            std::wcout << std::format(L"  Name: {}\n", piece.Name());
        }

        if (auto bonus{ armor_set.Bonus() })
        {
            std::wcout << std::format(L"  Bonus: {}\n", bonus.Skill().Name());
        }

        if (auto group_bonus{ armor_set.GroupBonus() })
        {
            std::wcout << std::format(L"  Group Bonus: {}\n", group_bonus.Skill().Name());
        }
    }
}

winrt::Windows::Foundation::IAsyncAction TestCharms()
{
    winrt::MonsterHunterWilds::Database db;
    auto charms{ co_await db.GetCharmsAsync() };

    for (auto const& charm : charms)
    {
        std::wcout << std::format(L"Charm ID: {}, Game ID: {}\n", charm.Id(), charm.GameId());

        for (auto const& rank : charm.Ranks())
        {
            std::wcout << std::format(L"  Rank ID: {}, Name: {}, Description: {}, Level: {}, Rarity: {}\n",
                rank.Id(), rank.Name(), rank.Description(), rank.Level(), rank.Rarity());

            for (auto const& skill : rank.Skills())
            {
                std::wcout << std::format(L"    Skill ID: {}, Level: {}, Name: {}, Description: {}\n",
                    skill.Id(), skill.Level(), skill.Name(), skill.Description());
            }
        }
    }
}

winrt::Windows::Foundation::IAsyncAction TestDecorations()
{
    winrt::MonsterHunterWilds::Database db;
    auto decorations{ co_await db.GetDecorationsAsync() };

    for (auto const& decoration : decorations)
    {
        std::wcout << std::format(L"Name: {}, Slot: {}, Rarity: {}, Kind: {}\n",
            decoration.Name(), decoration.Slot(), decoration.Rarity(), std::to_underlying(decoration.Kind()));
    }
}

winrt::Windows::Foundation::IAsyncAction TestItems()
{
    winrt::MonsterHunterWilds::Database db;
    auto items{ co_await db.GetItemsAsync() };

    for (auto const& item : items)
    {
        std::wcout << std::format(L"Name: {}, Description: {}\n",
            item.Name(), item.Description());
    }
}

winrt::Windows::Foundation::IAsyncAction TestSkills()
{
    winrt::MonsterHunterWilds::Database db;
    auto skills{ co_await db.GetSkillsAsync() };

    for (auto const& skill : skills)
    {
        if (auto kind{ skill.Kind() })
        {
            std::wcout << std::format(L"Skill ID: {}, Name: {}, Kind: {}, Description: {}\n",
                skill.Id(), skill.Name(), std::to_underlying(kind.Value()), skill.Description());
        }
        else
        {
            std::wcout << std::format(L"Skill ID: {}, Name: {}, Description: {}\n",
                skill.Id(), skill.Name(), skill.Description());
        }
        

        for (auto const& rank : skill.Ranks())
        {
            std::wcout << std::format(L"  Rank ID: {}, Level: {}, Name: {}, Description: {}\n",
                rank.Id(), rank.Level(), rank.Name(), rank.Description());
        }
    }
}

winrt::Windows::Foundation::IAsyncAction TestWeapons()
{
    winrt::MonsterHunterWilds::Database db;
    auto weapons{ co_await db.GetWeaponsAsync() };

    for (auto const& weapon : weapons)
    {
        std::wcout << std::format(L"Kind: {}, Name: {}\n", std::to_underlying(weapon.Kind()), weapon.Name());
    }
}

int main()
{
	std::wcout.imbue(std::locale{ "" });

	winrt::init_apartment();

	//std::wcout << std::format(L"Database Version: {}\n", winrt::MonsterHunterWilds::Database::GetVersionAsync().get());

    //TestArmors().get();
    //TestArmorSets().get();
    //TestCharms().get();
    //TestDecorations().get();
    //TestItems().get();
    //TestSkills().get();
    TestWeapons().get();

	//__debugbreak();
}
