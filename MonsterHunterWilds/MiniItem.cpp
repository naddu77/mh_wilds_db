#include "pch.h"
#include "MiniItem.h"
#include "MiniItem.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MiniItem MiniItem::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
           winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
           json_object.GetNamedString(L"name")
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniItem> MiniItem::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    MiniItem::MiniItem(int32_t id, hstring const& name)
        : id_{ id }
        , name_{ name }
    {
        
    }

    int32_t MiniItem::Id()
    {
        return id_;
    }

    hstring MiniItem::Name()
    {
        return name_;
    }
}
