#pragma once
#include "ElementResistance.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ElementResistance : ElementResistanceT<ElementResistance>
    {
        static winrt::MonsterHunterWilds::MonsterResistance Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        ElementResistance(int32_t id, hstring condition, winrt::MonsterHunterWilds::Element const& element);

        int32_t Id();
        hstring Condition();
        winrt::MonsterHunterWilds::ResistanceKind Kind();
        winrt::MonsterHunterWilds::Element Element();

    private:
		winrt::MonsterHunterWilds::Element element_;
        int32_t id_;
        hstring condition_;
		winrt::MonsterHunterWilds::ResistanceKind kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ElementResistance : ElementResistanceT<ElementResistance, implementation::ElementResistance>
    {
    };
}
