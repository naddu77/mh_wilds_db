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
    template <typename T>
    inline auto constexpr always_false{ false };

    template <winrt::Windows::Data::Json::JsonValueType Type>
    auto TryGetValue(winrt::Windows::Data::Json::JsonObject const& json, winrt::hstring const& name)
    {
        if constexpr (Type == winrt::Windows::Data::Json::JsonValueType::String)
        {
            if (json.HasKey(name))
            {
                auto named_value{ json.GetNamedValue(name) };

                return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::String
                    ? std::optional{ named_value.GetString() }
                    : std::nullopt;
            }

            return std::optional<winrt::hstring>{};
        }
        else if constexpr (Type == winrt::Windows::Data::Json::JsonValueType::Number)
        {
            if (json.HasKey(name))
            {
                auto named_value{ json.GetNamedValue(name) };

                return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Number
                    ? std::optional{ named_value.GetNumber() }
                    : std::nullopt;
            }

            return std::optional<double>{};
        }
        else if constexpr (Type == winrt::Windows::Data::Json::JsonValueType::Boolean)
        {
            if (json.HasKey(name))
            {
                auto named_value{ json.GetNamedValue(name) };

                return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Boolean
                    ? std::optional{ named_value.GetBoolean() }
                    : std::nullopt;
            }

		    return std::optional<bool>{};
        }
        else if constexpr (Type == winrt::Windows::Data::Json::JsonValueType::Object)
        {
            if (json.HasKey(name))
            {
                auto named_value{ json.GetNamedValue(name) };

                return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Object
                    ? std::optional{ named_value.GetObject() }
                    : std::nullopt;
            }

		    return std::optional<winrt::Windows::Data::Json::JsonObject>{};
	    }
        else if constexpr (Type == winrt::Windows::Data::Json::JsonValueType::Array)
        {
            if (json.HasKey(name))
            {
                auto named_value{ json.GetNamedValue(name) };

                return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Array
                    ? std::optional{ named_value.GetArray() }
                    : std::nullopt;
            }

		    return std::optional<winrt::Windows::Data::Json::JsonArray>{};
        }
        else
        {
            static_assert(always_false<Type>, "Unsupported JsonValueType for TryGetValue");
        }
    }

    template <typename Func>
    auto ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& array, Func&& transformer)
    {
        return array
            | std::views::transform(transformer)
            | std::ranges::to<std::vector>();
    }

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

    SkillRank Database::TestSkillRank()
    {
        return SkillRank{
            18,
            {},
            L"",
            13
		};
    }
}
