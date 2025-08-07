#include "pch.h"
#include "ElementResistance.h"
#include "ElementResistance.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterResistance ElementResistance::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::ElementResistance{
			winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"condition"),
            winrt::MonsterHunterWilds::EnumMap::ElementMap(json_object.GetNamedString(L"element"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> ElementResistance::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    ElementResistance::ElementResistance(int32_t id, hstring condition, winrt::MonsterHunterWilds::Element const& element)
        : element_{ element }, id_{ id }, condition_{ condition }, kind_{ winrt::MonsterHunterWilds::ResistanceKind::Element }
    {

    }

    winrt::MonsterHunterWilds::Element ElementResistance::Element()
    {
		return element_;
    }

    int32_t ElementResistance::Id()
    {
        return id_;
    }

    hstring ElementResistance::Condition()
    {
        return condition_;
    }

    winrt::MonsterHunterWilds::ResistanceKind ElementResistance::Kind()
    {
        return kind_;
    }
}
