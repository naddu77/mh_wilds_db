#include "pch.h"
#include <winrt/MonsterHunterWilds.h>

import std;

winrt::Windows::Foundation::IAsyncAction TestSkills()
{
    winrt::MonsterHunterWilds::Database db;
    auto skills{ co_await db.GetSkillsAsync() };

    for (auto const& skill : skills)
    {
        std::wcout << std::format(L"Skill ID: {}, Name: {}, Kind: {}, Description: {}\n",
            skill.Id(), skill.Name(), std::to_underlying(skill.Kind()), skill.Description());

        for (auto const& rank : skill.Ranks())
        {
            std::wcout << std::format(L"  Rank ID: {}, Level: {}, Name: {}, Description: {}\n",
                rank.Id(), rank.Level(), rank.Name(), rank.Description());
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

int main()
{
	std::wcout.imbue(std::locale{ "" });

	winrt::init_apartment();

	//std::wcout << std::format(L"Database Version: {}\n", winrt::MonsterHunterWilds::Database::GetVersionAsync().get());

    //TestSkills().get();
    //TestCharms().get();


	//__debugbreak();
}
