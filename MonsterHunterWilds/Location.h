#pragma once
#include "Location.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Location : LocationT<Location>
    {
        static winrt::MonsterHunterWilds::Location Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        Location(int32_t id, int32_t gameId, hstring const& name, int32_t zoneCount, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> const& camps);

        int32_t Id();
        int32_t GameId();
        hstring Name();
        int32_t ZoneCount();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> Camps();

    private:
        int32_t id_;
        int32_t game_id_;
        hstring name_;
        int32_t zone_count_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> camps_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Location : LocationT<Location, implementation::Location>
    {
    };
}
