#include "pch.h"
#include "Sharpness.h"
#include "Sharpness.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Sharpness Sharpness::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"red")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"orange")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"yellow")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"green")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"blue")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"white")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"purple"))
        };
    }

    Sharpness::Sharpness(int32_t red, int32_t orange, int32_t yellow, int32_t green, int32_t blue, int32_t white, int32_t purple)
        : red_{ red }
        , orange_{ orange }
        , yellow_{ yellow }
        , green_{ green }
        , blue_{ blue }
        , white_{ white }
        , purple_{ purple }
    {
        
    }

    int32_t Sharpness::Red()
    {
        return red_;
    }

    int32_t Sharpness::Orange()
    {
        return orange_;
    }

    int32_t Sharpness::Yellow()
    {
        return yellow_;
    }

    int32_t Sharpness::Green()
    {
        return green_;
    }

    int32_t Sharpness::Blue()
    {
        return blue_;
    }

    int32_t Sharpness::White()
    {
        return white_;
    }

    int32_t Sharpness::Purple()
    {
        return purple_;
    }
}
