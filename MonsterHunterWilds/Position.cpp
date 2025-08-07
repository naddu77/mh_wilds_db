#include "pch.h"
#include "Position.h"
#include "Position.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Position Position::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            json_object.GetNamedNumber(L"x"),
            json_object.GetNamedNumber(L"y"),
            json_object.GetNamedNumber(L"z")
		};
    }

    Position::Position(double x, double y, double z)
		: x_{ x }, y_{ y }, z_{ z }
    {
        
    }

    double Position::X()
    {
		return x_;
    }

    double Position::Y()
    {
		return y_;
    }

    double Position::Z()
    {
		return z_;
    }
}
