#pragma once
#include "ArmorDefense.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorDefense : ArmorDefenseT<ArmorDefense>
    {
        static winrt::MonsterHunterWilds::ArmorDefense Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        ArmorDefense(int32_t base, int32_t max);

        int32_t Base();
        int32_t Max();

	private:
        int32_t base_;
		int32_t max_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorDefense : ArmorDefenseT<ArmorDefense, implementation::ArmorDefense>
    {
    };
}
