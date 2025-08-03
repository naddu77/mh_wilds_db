#include "pch.h"
#include "Util.h"

winrt::hstring TryGetNamedString(winrt::Windows::Data::Json::JsonObject const& json_object, winrt::hstring const& key)
{
    if (json_object.HasKey(key))
    {
        auto named_value{ json_object.GetNamedValue(key) };

        return named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::String
            ? named_value.GetString()
            : winrt::hstring{};
    }

    return {};
}
