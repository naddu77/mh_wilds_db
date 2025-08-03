#include "pch.h"
#include <winrt/MonsterHunterWilds.h>

import std;

int main()
{
	std::wcout.imbue(std::locale{ "" });

	winrt::init_apartment();

	std::wcout << std::format(L"Database Version: {}\n", winrt::MonsterHunterWilds::Database::GetVersionAsync().get());

	auto test{ winrt::MonsterHunterWilds::Database::TestSkillRank() };

	auto ok{ test.Name() };
	auto ok2{ test.Description() };

	std::wcout << std::format(L"{}", ok == ok2);

	std::wcout << std::format(L"A {} B\n", std::data(ok) == nullptr);
	std::wcout << std::format(L"A {} B\n", std::data(test.Description()) == nullptr);

	__debugbreak();
}
