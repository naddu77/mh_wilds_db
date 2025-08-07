#include "pch.h"
#include "ElementWeakness.h"
#include "ElementWeakness.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterWeakness ElementWeakness::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return winrt::MonsterHunterWilds::ElementWeakness{
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"level"),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"condition"),
            winrt::MonsterHunterWilds::EnumMap::ElementMap(json_object.GetNamedString(L"element"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> ElementWeakness::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](winrt::Windows::Data::Json::IJsonValue const& value) {
                return winrt::MonsterHunterWilds::ElementWeakness::Parse(value.GetObject());
			})
			| std::ranges::to<std::vector>()
        );
    }

    ElementWeakness::ElementWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Element const& element)
		: id_{ id }, level_{ level }, condition_{ condition }, element_{ element }
    {
        
    }    

    winrt::MonsterHunterWilds::Element ElementWeakness::Element()
    {
		return element_;
    }

    int32_t ElementWeakness::Id()
    {
        return id_;
    }

    int32_t ElementWeakness::Level()
    {
		return level_;
    }

    hstring ElementWeakness::Condition()
    {
		return condition_;
    }

    winrt::MonsterHunterWilds::WeaknessKind ElementWeakness::Kind()
    {
		return winrt::MonsterHunterWilds::WeaknessKind::Element;
    }
}
