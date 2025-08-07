#pragma once
#include "EffectWeakness.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct EffectWeakness : EffectWeaknessT<EffectWeakness>
    {
        static winrt::MonsterHunterWilds::MonsterWeakness Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        EffectWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Effect const& effect);

        winrt::MonsterHunterWilds::Effect Effect();
        int32_t Id();
        int32_t Level();
        hstring Condition();
        winrt::MonsterHunterWilds::WeaknessKind Kind();

    private:
        winrt::MonsterHunterWilds::Effect effect_;
        int32_t id_;
        int32_t level_;
        hstring condition_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct EffectWeakness : EffectWeaknessT<EffectWeakness, implementation::EffectWeakness>
    {
    };
}
