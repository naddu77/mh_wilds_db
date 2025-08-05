#pragma once
#include "Sharpness.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Sharpness : SharpnessT<Sharpness>
    {
        static winrt::MonsterHunterWilds::Sharpness Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        Sharpness() = default;
        Sharpness(int32_t red, int32_t orange, int32_t yellow, int32_t green, int32_t blue, int32_t white, int32_t purple);

        int32_t Red();
        int32_t Orange();
        int32_t Yellow();
        int32_t Green();
        int32_t Blue();
        int32_t White();
        int32_t Purple();

    private:
        int32_t red_;
        int32_t orange_;
        int32_t yellow_;
        int32_t green_;
        int32_t blue_;
        int32_t white_;
        int32_t purple_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Sharpness : SharpnessT<Sharpness, implementation::Sharpness>
    {
    };
}
