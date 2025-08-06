#pragma once
#include "JsonParser.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct JsonParser
    {
        JsonParser() = default;

        static int32_t GetNamedInt32(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);

        static hstring TryGetNamedString(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);
        static winrt::Windows::Foundation::IReference<int32_t> TryGetNamedInt32(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);

        static winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array, winrt::MonsterHunterWilds::JsonValueTransformer const& transformer);
        static winrt::Windows::Foundation::Collections::IVector<int32_t> ParseNamedInt32Array(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);

        static winrt::Windows::Foundation::IInspectable TryParseNamedObject(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key, winrt::MonsterHunterWilds::JsonObjectTransformer const& transformer);
        static winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> TryParseNamedArray(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key, winrt::MonsterHunterWilds::JsonValueTransformer const& transformer);
        static winrt::Windows::Foundation::Collections::IVector<int32_t> TryParseNamedInt32Array(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);
        
        static winrt::MonsterHunterWilds::WeaponSpecial ParseWeaponSpecial(winrt::Windows::Data::Json::IJsonValue const& json_value);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> ParseWeaponSpecials(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::MonsterHunterWilds::Weapon ParseWeapon(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Weapon> ParseWeapons(winrt::Windows::Data::Json::JsonArray const& json_array);
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct JsonParser : JsonParserT<JsonParser, implementation::JsonParser>
    {
    };
}
