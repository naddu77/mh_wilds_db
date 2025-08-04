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
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetWeaponsJsonAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetArmorsJsonAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetSkillsJsonAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetCharmsJsonAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetDecorationsJsonAsync();
        static winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill>> GetSkillsAsync();
    };    
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Database : DatabaseT<Database, implementation::Database>
    {
    };
}
