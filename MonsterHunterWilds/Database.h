#pragma once

#include "Database.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Database : DatabaseT<Database>
    {
        Database() = default;
        Database(winrt::hstring const& locale);

        winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> GetVersionAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetJsonArrayAsync(winrt::hstring url);
        winrt::Windows::Foundation::IAsyncAction SaveUrlToFile(winrt::hstring url, winrt::hstring file_name);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetWeaponsJsonAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetArmorsJsonAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetSkillsJsonAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetCharmsJsonAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> GetDecorationsJsonAsync();
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill>> GetSkillsAsync();

    private:
        Api api;
    };    
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Database : DatabaseT<Database, implementation::Database>
    {
    };
}
