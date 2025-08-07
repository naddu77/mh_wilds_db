#pragma once
#include "Camp.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Camp : CampT<Camp>
    {
        static winrt::MonsterHunterWilds::Camp Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Camp> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        Camp(int32_t id, hstring const& name, int32_t zone, int32_t floor, winrt::MonsterHunterWilds::Risk const& risk, winrt::MonsterHunterWilds::Position const& position);

        int32_t Id();
        hstring Name();
        int32_t Zone();
        int32_t Floor();
        winrt::MonsterHunterWilds::Risk Risk();
        winrt::MonsterHunterWilds::Position Position();

    private:
        int32_t id_;
        hstring name_;
        int32_t zone_;
        int32_t floor_;
        winrt::MonsterHunterWilds::Risk risk_;
		winrt::MonsterHunterWilds::Position position_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Camp : CampT<Camp, implementation::Camp>
    {
    };
}
