#include "pch.h"
#include "EffectResistance.h"
#include "EffectResistance.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterResistance EffectResistance::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::EffectResistance{
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"condition"),
            winrt::MonsterHunterWilds::EnumMap::EffectMap(json_object.GetNamedString(L"effect"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> EffectResistance::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::EffectResistance::Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
		);
    }

    EffectResistance::EffectResistance(int32_t id, hstring const& condition, winrt::MonsterHunterWilds::Effect const& effect)
		: id_{ id }, condition_{ condition }, kind_{ winrt::MonsterHunterWilds::ResistanceKind::Effect }, effect_{ effect }
    {
        
    }

    winrt::MonsterHunterWilds::Effect EffectResistance::Effect()
    {
		return effect_;
    }

    int32_t EffectResistance::Id()
    {
        return id_;
    }

    hstring EffectResistance::Condition()
    {
        return condition_;
    }

    winrt::MonsterHunterWilds::ResistanceKind EffectResistance::Kind()
    {
        return kind_;
    }
}
