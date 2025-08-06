#include "pch.h"
#include "MiniArmorSet.h"
#include "MiniArmorSet.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MiniArmorSet MiniArmorSet::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            winrt::MonsterHunterWilds::JsonParser::TryGetNamedString(json_object, L"name")
        };
    }

    MiniArmorSet::MiniArmorSet(int32_t id, hstring const& name)
        : id_{ id }
        , name_{ name }
    {
        
    }

    int32_t MiniArmorSet::Id()
    {
        return id_;
    }

    hstring MiniArmorSet::Name()
    {
        return name_;
    }
}
