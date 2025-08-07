#pragma once
#include "Monster.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Monster : MonsterT<Monster>
    {
        static winrt::MonsterHunterWilds::Monster Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Monster> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        Monster(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::MonsterKind const& kind, winrt::MonsterHunterWilds::Species const& species, hstring const& name, winrt::MonsterHunterWilds::MonsterSize const& size, hstring const& description, hstring const& features, hstring const& tips, int32_t base_health, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> const& locations, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> const& resistances, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> const& weaknesses, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> const& rewards, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> const& parts);

        int32_t Id();
        int32_t GameId();
        winrt::MonsterHunterWilds::MonsterKind Kind();
        winrt::MonsterHunterWilds::Species Species();
        hstring Name();
        winrt::MonsterHunterWilds::MonsterSize Size();
        hstring Description();
        hstring Features();
        hstring Tips();
        int32_t BaseHealth();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> Locations();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> Resistances();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> Weaknesses();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> Rewards();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> Parts();

    private:
        int32_t id_;
        int32_t game_id_;
        winrt::MonsterHunterWilds::MonsterKind kind_;
        winrt::MonsterHunterWilds::Species species_;
        hstring name_;
        winrt::MonsterHunterWilds::MonsterSize size_;
        hstring description_;
        hstring features_;
        hstring tips_;
        int32_t base_health_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> locations_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> resistances_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> weaknesses_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> rewards_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> parts_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Monster : MonsterT<Monster, implementation::Monster>
    {
    };
}
