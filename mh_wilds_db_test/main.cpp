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

int main()
{
	std::wcout.imbue(std::locale{ "" });

	winrt::init_apartment();

	//std::wcout << std::format(L"Database Version: {}\n", winrt::MonsterHunterWilds::Database::GetVersionAsync().get());

    // Skills
    TestSkills().get();


	//__debugbreak();
}
