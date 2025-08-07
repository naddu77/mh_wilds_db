#include "pch.h"
#include "EffectWeakness.h"
#include "EffectWeakness.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterWeakness EffectWeakness::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::EffectWeakness{
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"level"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"condition"),
            winrt::MonsterHunterWilds::EnumMap::EffectMap(json_object.GetNamedString(L"effect"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> EffectWeakness::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](winrt::Windows::Data::Json::IJsonValue const& value) {
                return winrt::MonsterHunterWilds::EffectWeakness::Parse(value.GetObject());
            })
            | std::ranges::to<std::vector>()
		);
    }

    EffectWeakness::EffectWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Effect const& effect)
        : id_{ id }, level_{ level }, condition_{ condition }, effect_{ effect }
    {
        
	}

    winrt::MonsterHunterWilds::Effect EffectWeakness::Effect()
    {
		return effect_;
    }

    int32_t EffectWeakness::Id()
    {
		return id_;
    }

    int32_t EffectWeakness::Level()
    {
		return level_;
    }

    hstring EffectWeakness::Condition()
    {
		return condition_;
    }

    winrt::MonsterHunterWilds::WeaknessKind EffectWeakness::Kind()
    {
		return winrt::MonsterHunterWilds::WeaknessKind::Effect;
    }
}
