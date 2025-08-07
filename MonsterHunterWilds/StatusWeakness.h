#pragma once
#include "StatusWeakness.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct StatusWeakness : StatusWeaknessT<StatusWeakness>
    {
        static winrt::MonsterHunterWilds::MonsterWeakness Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        StatusWeakness(int32_t id, int32_t level, hstring const& condition, winrt::MonsterHunterWilds::Status const& status);

        winrt::MonsterHunterWilds::Status Status();
        int32_t Id();
        int32_t Level();
        hstring Condition();
        winrt::MonsterHunterWilds::WeaknessKind Kind();

    private:
        winrt::MonsterHunterWilds::Status status_;
        int32_t id_;
        int32_t level_;
		hstring condition_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct StatusWeakness : StatusWeaknessT<StatusWeakness, implementation::StatusWeakness>
    {
    };
}
