#include "pch.h"
#include "Database.h"
#if __has_include("Database.g.cpp")
#include "Database.g.cpp"
#endif

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> Database::GetVersionAsync()
    {
        winrt::Windows::Web::Http::HttpClient http_client;
        winrt::Windows::Foundation::Uri version_uri{ L"https://wilds.mhdb.io/version" };
        auto response{ co_await http_client.GetAsync(version_uri) };

        response.EnsureSuccessStatusCode();

        auto content{ co_await response.Content().ReadAsStringAsync() };
        auto json_object{ winrt::Windows::Data::Json::JsonObject::Parse(content) };
        auto version{ json_object.GetNamedString(L"version") };

        co_return version;
    }

    Database::Database(winrt::hstring const& locale)
        : api{ locale }
    {

    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetJsonArrayAsync(winrt::hstring url)
    {
        winrt::Windows::Web::Http::HttpClient http_client;
        winrt::Windows::Foundation::Uri uri{ url };
        auto response{ co_await http_client.GetAsync(uri) };

        response.EnsureSuccessStatusCode();

        auto content{ co_await response.Content().ReadAsStringAsync() };

        co_return winrt::Windows::Data::Json::JsonArray::Parse(content);
    }

    winrt::Windows::Foundation::IAsyncAction Database::SaveUrlToFile(winrt::hstring url, winrt::hstring file_name)
    {
		auto json_array{ co_await GetJsonArrayAsync(url) };
        auto skills_json{ json_array.Stringify() };
        auto documents_folder{ winrt::Windows::Storage::KnownFolders::DocumentsLibrary() };
        auto storage_file{ co_await documents_folder.CreateFileAsync(file_name, winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting) };

        co_await winrt::Windows::Storage::FileIO::WriteTextAsync(storage_file, skills_json);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetArmorsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.ArmorUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetArmorSetsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.ArmorSetsUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetCharmsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.CharmsUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetDecorationsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.DecorationsUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetItemsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.ItemsUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetSkillsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.SkillsUrl());
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetWeaponsJsonAsync()
    {
        co_return co_await GetJsonArrayAsync(api.WeaponsUrl());
    }


    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor>> Database::GetArmorsAsync()
    {
        auto json_array{ co_await GetArmorsJsonAsync() };

        co_return winrt::MonsterHunterWilds::Armor::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSet>> Database::GetArmorSetsAsync()
    {
        auto json_array{ co_await GetArmorSetsJsonAsync() };

        co_return winrt::MonsterHunterWilds::ArmorSet::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Charm>> Database::GetCharmsAsync()
    {
        auto json_array{ co_await GetCharmsJsonAsync() };

        co_return winrt::MonsterHunterWilds::Charm::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Decoration>> Database::GetDecorationsAsync()
    {
        auto json_array{ co_await GetDecorationsJsonAsync() };

        co_return winrt::MonsterHunterWilds::Decoration::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Item>> Database::GetItemsAsync()
    {
        auto json_array{ co_await GetItemsJsonAsync() };

        co_return winrt::MonsterHunterWilds::Item::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill>> Database::GetSkillsAsync()
    {
        auto json_array{ co_await GetSkillsJsonAsync() };

        co_return winrt::MonsterHunterWilds::Skill::ParseJsonArray(json_array);
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon>> Database::GetWeaponsAsync()
    {
        auto json_array{ co_await GetWeaponsJsonAsync() };

        co_return winrt::MonsterHunterWilds::JsonParser::ParseWeapons(json_array);
    }
}
