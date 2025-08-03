#pragma once

#include <ranges>
#include <optional>
#include <vector>

template <typename T>
inline auto constexpr always_false{ false };

winrt::hstring TryGetNamedString(winrt::Windows::Data::Json::JsonObject const& json_object, winrt::hstring const& key);

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
