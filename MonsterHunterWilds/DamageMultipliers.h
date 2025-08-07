#pragma once
#include "DamageMultipliers.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct DamageMultipliers : DamageMultipliersT<DamageMultipliers>
    {
        static winrt::MonsterHunterWilds::DamageMultipliers Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::DamageMultipliers> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        DamageMultipliers(double slash, double blunt, double pierce, double fire, double water, double thunder, double ice, double dragon, double stun);

        double Slash();
        double Blunt();
        double Pierce();
        double Fire();
        double Water();
        double Thunder();
        double Ice();
        double Dragon();
        double Stun();

    private:
		double slash_;
		double blunt_;
		double pierce_;
		double fire_;
		double water_;
		double thunder_;
		double ice_;
		double dragon_;
		double stun_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct DamageMultipliers : DamageMultipliersT<DamageMultipliers, implementation::DamageMultipliers>
    {
    };
}
