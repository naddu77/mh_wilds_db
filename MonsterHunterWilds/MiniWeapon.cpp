#include "pch.h"
#include "MiniWeapon.h"
#include "MiniWeapon.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MiniWeapon MiniWeapon::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            json_object.GetNamedString(L"name")
        };
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
