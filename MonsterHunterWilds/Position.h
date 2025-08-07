#pragma once
#include "Position.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Position : PositionT<Position>
    {
        static winrt::MonsterHunterWilds::Position Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        Position(double x, double y, double z);

        double X();
        double Y();
        double Z();

    private:
        double x_;
        double y_;
	    double z_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Position : PositionT<Position, implementation::Position>
    {
    };
}
