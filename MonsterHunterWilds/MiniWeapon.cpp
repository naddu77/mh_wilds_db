#include "pch.h"
#include "MiniWeapon.h"
#include "MiniWeapon.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MiniWeapon MiniWeapon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            json_object.GetNamedString(L"name")
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MiniWeapon> MiniWeapon::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    MiniWeapon::MiniWeapon(int32_t id, hstring const& name)
        : id_{ id }
        , name_{ name }
    {
        
    }
    
    int32_t MiniWeapon::Id()
    {
        return id_;
    }

    hstring MiniWeapon::Name()
    {
        return name_;
    }
}
