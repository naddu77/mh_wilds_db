#pragma once
#include "MiniArmorSet.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MiniArmorSet : MiniArmorSetT<MiniArmorSet>
    {
        static winrt::MonsterHunterWilds::MiniArmorSet Parse(winrt::Windows::Data::Json::JsonObject const& json_object);        

        MiniArmorSet(int32_t id, hstring const& name);

        int32_t Id();
        hstring Name();

    private:
        int32_t id_;
        hstring name_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MiniArmorSet : MiniArmorSetT<MiniArmorSet, implementation::MiniArmorSet>
    {
    };
}
