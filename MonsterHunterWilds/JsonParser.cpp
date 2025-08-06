#include "pch.h"
#include "JsonParser.h"
#include "JsonParser.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    int32_t JsonParser::GetNamedInt32(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        return static_cast<int32_t>(json_object.GetNamedNumber(key));
    }

    hstring JsonParser::TryGetNamedString(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::String)
            {
                return named_value.GetString();
            }
        }

        return {};
    }

    winrt::Windows::Foundation::IReference<int32_t> JsonParser::TryGetNamedInt32(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Number)
            {
                return static_cast<int32_t>(named_value.GetNumber());
            }
        }

        return {};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> JsonParser::ParseJsonArray(
        winrt::Windows::Data::Json::JsonArray const& json_array,
        winrt::MonsterHunterWilds::JsonValueTransformer const& transformer)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform(transformer)
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> JsonParser::ParseNamedInt32Array(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        return winrt::single_threaded_vector(
            json_object.GetNamedArray(key)
            | std::views::transform([](auto const& json_value) { return static_cast<int32_t>(json_value.GetNumber()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::IInspectable JsonParser::TryParseNamedObject(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key, winrt::MonsterHunterWilds::JsonObjectTransformer const& transformer)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Object)
            {
                return std::invoke(transformer, named_value.GetObject());
            }
        }

        return {};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Foundation::IInspectable> JsonParser::TryParseNamedArray(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key, winrt::MonsterHunterWilds::JsonValueTransformer const& transformer)
    {
        if (json_object.HasKey(key))
        {           
            if (auto named_value{ json_object.GetNamedValue(key) }; 
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Array)
            {
                return ParseJsonArray(named_value.GetArray(), transformer);
            }
        }

        return {};
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> JsonParser::TryParseNamedInt32Array(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Array)
            {
                return winrt::single_threaded_vector(
                    json_object.GetNamedArray(key)
                    | std::views::transform([](auto const& json_value) { return static_cast<int32_t>(json_value.GetNumber()); })
                    | std::ranges::to<std::vector>()
                );
            }            
        }

        return {};
    }

    winrt::MonsterHunterWilds::WeaponSpecial JsonParser::ParseWeaponSpecial(winrt::Windows::Data::Json::IJsonValue const& json_value)
    {
        auto json_object{ json_value.GetObject() };
        auto kind{ json_object.GetNamedString(L"kind") };

        if (kind == L"element")
        {
            return winrt::MonsterHunterWilds::WeaponElement::Parse(json_object).as<winrt::MonsterHunterWilds::WeaponSpecial>();
        }
        else if (kind == L"status")
        {
            return winrt::MonsterHunterWilds::WeaponStatus::Parse(json_object).as<winrt::MonsterHunterWilds::WeaponSpecial>();
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", kind) };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::WeaponSpecial> JsonParser::ParseWeaponSpecials(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        auto specials{ json_object.GetNamedArray(L"specials") };

        return winrt::single_threaded_vector(
            specials
            | std::views::transform(&JsonParser::ParseWeaponSpecial)
            | std::ranges::to<std::vector>()
        );
    }

    winrt::MonsterHunterWilds::Weapon JsonParser::ParseWeapon(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        auto kind{ json_object.GetNamedString(L"kind") };
        auto weapon_kind{ winrt::MonsterHunterWilds::EnumMap::WeaponKindMap(kind) };

        switch (weapon_kind)
        {
        case winrt::MonsterHunterWilds::WeaponKind::Bow:
            return winrt::MonsterHunterWilds::Bow::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::ChargeBlade:
            return winrt::MonsterHunterWilds::ChargeBlade::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::DualBlades:
            return winrt::MonsterHunterWilds::DualBlades::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::GreatSword:
            return winrt::MonsterHunterWilds::GreatSword::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::Gunlance:
            return winrt::MonsterHunterWilds::Gunlance::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::Hammer:
            return winrt::MonsterHunterWilds::Hammer::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::HeavyBowgun:
            return winrt::MonsterHunterWilds::HeavyBowgun::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::HuntingHorn:
            return winrt::MonsterHunterWilds::HuntingHorn::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::InsectGlaive:
            return winrt::MonsterHunterWilds::InsectGlaive::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::Lance:
            return winrt::MonsterHunterWilds::Lance::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::LightBowgun:
            return winrt::MonsterHunterWilds::LightBowgun::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::LongSword:
            return winrt::MonsterHunterWilds::LongSword::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::SwitchAxe:
            return winrt::MonsterHunterWilds::SwitchAxe::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        case winrt::MonsterHunterWilds::WeaponKind::SwordShield:
            return winrt::MonsterHunterWilds::SwordShield::Parse(json_object).as<winrt::MonsterHunterWilds::Weapon>();

        default:
            break;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid Weapon Kind: {}", kind) };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> JsonParser::ParseArmors(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::Armor::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::ArmorSetBonusRank> JsonParser::ParseArmorSetBonusRanks(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::ArmorSetBonusRank::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> JsonParser::ParseSkillRanks(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::SkillRank::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::BowCoating> JsonParser::ParseBowCoatings(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        auto coatings{ json_object.GetNamedArray(L"coatings") };

        return winrt::single_threaded_vector(
            coatings
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::EnumMap::BowCoatingMap(json_value.GetString()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::LightBowgunAmmo> JsonParser::ParseLightBowgunAmmos(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        auto ammos{ json_object.GetNamedArray(L"ammo") };

        return winrt::single_threaded_vector(
            ammos
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::LightBowgunAmmo::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HeavyBowgunAmmo> JsonParser::ParseHeavyBowgunAmmos(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        auto ammos{ json_object.GetNamedArray(L"ammo") };

        return winrt::single_threaded_vector(
            ammos
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::HeavyBowgunAmmo::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }
}
