#pragma once
#include "ArmorResistances.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorResistances : ArmorResistancesT<ArmorResistances>
    {
        static winrt::MonsterHunterWilds::ArmorResistances Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ArmorResistances(int32_t fire, int32_t water, int32_t ice, int32_t thunder, int32_t dragon);

        int32_t Fire();
        int32_t Water();
        int32_t Ice();
        int32_t Thunder();
        int32_t Dragon();

    private:
        int32_t fire_;
        int32_t water_;
        int32_t ice_;
        int32_t thunder_;
		int32_t dragon_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorResistances : ArmorResistancesT<ArmorResistances, implementation::ArmorResistances>
    {
    };
}
