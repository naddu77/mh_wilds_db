#pragma once
#include "MonsterSize.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MonsterSize : MonsterSizeT<MonsterSize>
    {
        static winrt::MonsterHunterWilds::MonsterSize Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        MonsterSize(double base, double mini, double silver, double gold);

        double Base();
        double Mini();
        double Siver();
        double Gold();

	private:
        double base_;
        double mini_;
        double silver_;
		double gold_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MonsterSize : MonsterSizeT<MonsterSize, implementation::MonsterSize>
    {
    };
}
