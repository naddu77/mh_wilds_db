#pragma once
#include "StatusResistance.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct StatusResistance : StatusResistanceT<StatusResistance>
    {
        static winrt::MonsterHunterWilds::MonsterResistance Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        StatusResistance(int32_t id, hstring condition, winrt::MonsterHunterWilds::Status const& status);

        winrt::MonsterHunterWilds::Status Status();
        int32_t Id();
        hstring Condition();
        winrt::MonsterHunterWilds::ResistanceKind Kind();

    private:
		winrt::MonsterHunterWilds::Status status_;
		int32_t id_;
		hstring condition_;
        winrt::MonsterHunterWilds::ResistanceKind kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct StatusResistance : StatusResistanceT<StatusResistance, implementation::StatusResistance>
    {
    };
}
