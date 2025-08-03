#pragma once

#include "Database.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Database : DatabaseT<Database>
    {
        Database() = default;

        static winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> GetVersionAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetJsonArrayAsync(winrt::hstring url);
        static winrt::Windows::Foundation::IAsyncAction SaveUrlToFile(winrt::hstring url, winrt::hstring file_name);
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetWeaponsAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetArmorsAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetSkillsAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetCharmsAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetDecorationsAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill>> ParseSkillsAsync();

        static SkillRank TestSkillRank();
    };    
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Database : DatabaseT<Database, implementation::Database>
    {
    };
}
