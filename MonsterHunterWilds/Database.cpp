#include "pch.h"
#include "Database.h"
#if __has_include("Database.g.cpp")
#include "Database.g.cpp"
#endif

#include "Util.h"

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

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetWeaponsAsync()
    {
        co_return co_await GetJsonArrayAsync(L"https://wilds.mhdb.io/ko/weapons");
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetArmorsAsync()
    {
        co_return co_await GetJsonArrayAsync(L"https://wilds.mhdb.io/ko/armor");
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetSkillsAsync()
    {
        co_return co_await GetJsonArrayAsync(L"https://wilds.mhdb.io/ko/skills");
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetCharmsAsync()
    {
        co_return co_await GetJsonArrayAsync(L"https://wilds.mhdb.io/ko/charms");
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Data::Json::JsonArray> Database::GetDecorationsAsync()
    {
        co_return co_await GetJsonArrayAsync(L"https://wilds.mhdb.io/ko/decorations");
    }

    winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Skill>> Database::ParseSkillsAsync()
    {
        auto skills_json_object{ co_await GetSkillsAsync() };
        auto skills{ ParseJsonArray(skills_json_object, [](auto const& json) { return Skill::Parse(json.GetObject()); }) };

        co_return winrt::single_threaded_vector<winrt::MonsterHunterWilds::Skill>(std::move(skills));
    }
}
