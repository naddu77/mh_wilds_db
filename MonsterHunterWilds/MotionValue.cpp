#include "pch.h"
#include "MotionValue.h"
#include "MotionValue.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MotionValue MotionValue::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::EnumMap::WeaponKindMap(json_object.GetNamedString(L"weapon")),
            winrt::MonsterHunterWilds::EnumMap::DamageKindMap(json_object.GetNamedString(L"damage")),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"stun"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"exhaust"),
            winrt::MonsterHunterWilds::JsonParser::ParseNamedInt32Array(json_object, L"hits")
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MotionValue> MotionValue::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) {
                return Parse(json_value.GetObject());
			})
            | std::ranges::to<std::vector>()
        );
    }

    MotionValue::MotionValue(int32_t id, hstring const& name, winrt::MonsterHunterWilds::WeaponKind const& weapon, winrt::MonsterHunterWilds::DamageKind const& damage, int32_t stun, int32_t exhaust, winrt::Windows::Foundation::Collections::IVector<int32_t> const& hits)
        : id_{ id }
		, name_{ name }
        , weapon_{ weapon }
        , damage_{ damage }
        , stun_{ stun }
        , exhaust_{ exhaust }
        , hits_{ hits }
    {
        
    }

    int32_t MotionValue::Id()
    {
		return id_;
    }

    hstring MotionValue::Name()
    {
		return name_;
    }

    winrt::MonsterHunterWilds::WeaponKind MotionValue::Weapon()
    {
		return weapon_;
    }

    winrt::MonsterHunterWilds::DamageKind MotionValue::Damage()
    {
		return damage_;
    }

    int32_t MotionValue::Stun()
    {
		return stun_;
    }

    int32_t MotionValue::Exhaust()
    {
		return exhaust_;
    }

    winrt::Windows::Foundation::Collections::IVector<int32_t> MotionValue::Hits()
    {
		return hits_;
    }
}
