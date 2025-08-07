#include "pch.h"
#include "MonsterPart.h"
#include "MonsterPart.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterPart MonsterPart::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::EnumMap::MonsterPartKindMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedInt32(json_object, L"health"),
			winrt::MonsterHunterWilds::EnumMap::TryKinsectEssenceMap(json_object, L"kinsectEssence"),
            winrt::MonsterHunterWilds::DamageMultipliers::Parse(json_object.GetNamedObject(L"multipliers"))
		};
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> MonsterPart::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector<winrt::MonsterHunterWilds::MonsterPart>(
            json_array
            | std::views::transform([](winrt::Windows::Data::Json::IJsonValue const& value) { return winrt::MonsterHunterWilds::MonsterPart::Parse(value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    MonsterPart::MonsterPart(
        int32_t id,
        winrt::MonsterHunterWilds::MonsterPartKind const& kind,
        winrt::Windows::Foundation::IReference<int32_t> health,
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> const& kinsect_essence,
        winrt::MonsterHunterWilds::DamageMultipliers const& multipliers)
		: id_{ id }, kind_{ kind }, health_{ health }, kinsect_essence_{ kinsect_essence }, multipliers_{ multipliers }
    {
        
    }

    int32_t MonsterPart::Id()
    {
		return id_;
    }

    winrt::MonsterHunterWilds::MonsterPartKind MonsterPart::Kind()
    {
		return kind_;
    }

    winrt::Windows::Foundation::IReference<int32_t> MonsterPart::Health()
    {
		return health_;
    }

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> MonsterPart::KinsectEssence()
    {
		return kinsect_essence_;
    }

    winrt::MonsterHunterWilds::DamageMultipliers MonsterPart::Multipliers()
    {
		return multipliers_;
    }
}
