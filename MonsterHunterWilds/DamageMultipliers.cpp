#include "pch.h"
#include "DamageMultipliers.h"
#include "DamageMultipliers.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::DamageMultipliers DamageMultipliers::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            json_object.GetNamedNumber(L"slash"),
            json_object.GetNamedNumber(L"blunt"),
            json_object.GetNamedNumber(L"pierce"),
            json_object.GetNamedNumber(L"fire"),
            json_object.GetNamedNumber(L"water"),
            json_object.GetNamedNumber(L"thunder"),
            json_object.GetNamedNumber(L"ice"),
            json_object.GetNamedNumber(L"dragon"),
			json_object.GetNamedNumber(L"stun")
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::DamageMultipliers> DamageMultipliers::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    DamageMultipliers::DamageMultipliers(double slash, double blunt, double pierce, double fire, double water, double thunder, double ice, double dragon, double stun)
		: slash_{ slash }, blunt_{ blunt }, pierce_{ pierce }, fire_{ fire }, water_{ water }, thunder_{ thunder }, ice_{ ice }, dragon_{ dragon }, stun_{ stun }
    {
        
    }

    double DamageMultipliers::Slash()
    {
        return slash_;
    }

    double DamageMultipliers::Blunt()
    {
        return blunt_;
    }

    double DamageMultipliers::Pierce()
    {
        return pierce_;
    }

    double DamageMultipliers::Fire()
    {
        return fire_;
    }

    double DamageMultipliers::Water()
    {
        return water_;
    }

    double DamageMultipliers::Thunder()
    {
        return thunder_;
    }

    double DamageMultipliers::Ice()
    {
        return ice_;
    }

    double DamageMultipliers::Dragon()
    {
        return dragon_;
    }

    double DamageMultipliers::Stun()
    {
        return stun_;
    }
}
