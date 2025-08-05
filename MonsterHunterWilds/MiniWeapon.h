#pragma once
#include "MiniWeapon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MiniWeapon : MiniWeaponT<MiniWeapon>
    {
        static winrt::MonsterHunterWilds::MiniWeapon Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        MiniWeapon() = default;
        MiniWeapon(int32_t id, hstring const& name);

        int32_t Id();
        hstring Name();

    private:
        int32_t id_;
        hstring name_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MiniWeapon : MiniWeaponT<MiniWeapon, implementation::MiniWeapon>
    {
    };
}
