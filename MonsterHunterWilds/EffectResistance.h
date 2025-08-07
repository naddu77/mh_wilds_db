#pragma once
#include "EffectResistance.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct EffectResistance : EffectResistanceT<EffectResistance>
    {
        static winrt::MonsterHunterWilds::MonsterResistance Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        EffectResistance(int32_t id, hstring const& condition, winrt::MonsterHunterWilds::Effect const& effect);

        winrt::MonsterHunterWilds::Effect Effect();
        int32_t Id();
        hstring Condition();
        winrt::MonsterHunterWilds::ResistanceKind Kind();

    private:
        winrt::MonsterHunterWilds::Effect effect_;
        int32_t id_;
		hstring condition_;
		winrt::MonsterHunterWilds::ResistanceKind kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct EffectResistance : EffectResistanceT<EffectResistance, implementation::EffectResistance>
    {
    };
}
