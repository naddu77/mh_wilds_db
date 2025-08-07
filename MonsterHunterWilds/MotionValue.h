#pragma once
#include "MotionValue.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MotionValue : MotionValueT<MotionValue>
    {
        static winrt::MonsterHunterWilds::MotionValue Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MotionValue> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        MotionValue(int32_t id, hstring const& name, winrt::MonsterHunterWilds::WeaponKind const& weapon, winrt::MonsterHunterWilds::DamageKind const& damage, int32_t stun, int32_t exhaust, winrt::Windows::Foundation::Collections::IVector<int32_t> const& hits);

        int32_t Id();
        hstring Name();
        winrt::MonsterHunterWilds::WeaponKind Weapon();
        winrt::MonsterHunterWilds::DamageKind Damage();
        int32_t Stun();
        int32_t Exhaust();
        winrt::Windows::Foundation::Collections::IVector<int32_t> Hits();

    private:
        int32_t id_;
		hstring name_;
        winrt::MonsterHunterWilds::WeaponKind weapon_;
        winrt::MonsterHunterWilds::DamageKind damage_;
        int32_t stun_;
        int32_t exhaust_;
		winrt::Windows::Foundation::Collections::IVector<int32_t> hits_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MotionValue : MotionValueT<MotionValue, implementation::MotionValue>
    {
    };
}
