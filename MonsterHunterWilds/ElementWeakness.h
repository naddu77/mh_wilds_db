#pragma once
#include "ElementWeakness.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ElementWeakness : ElementWeaknessT<ElementWeakness>
    {
        static winrt::MonsterHunterWilds::MonsterWeakness Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        ElementWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Element const& element);

        winrt::MonsterHunterWilds::Element Element();
        int32_t Id();
        int32_t Level();
        hstring Condition();
        winrt::MonsterHunterWilds::WeaknessKind Kind();

    private:
        winrt::MonsterHunterWilds::Element element_;
        int32_t id_;
        int32_t level_;
        hstring condition_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ElementWeakness : ElementWeaknessT<ElementWeakness, implementation::ElementWeakness>
    {
    };
}
