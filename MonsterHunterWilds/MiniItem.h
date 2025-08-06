#pragma once
#include "MiniItem.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MiniItem : MiniItemT<MiniItem>
    {
        MiniItem(int32_t id, hstring const& name);

        static winrt::MonsterHunterWilds::MiniItem Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        int32_t Id();
        hstring Name();

    private:
        int32_t id_;
        hstring name_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MiniItem : MiniItemT<MiniItem, implementation::MiniItem>
    {
    };
}
