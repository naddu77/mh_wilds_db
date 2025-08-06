#include "pch.h"
#include "ArmorSet.h"
#include "ArmorSet.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorSet ArmorSet::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            json_object.GetNamedString(L"name"),
            winrt::MonsterHunterWilds::JsonParser::ParseArmors(json_object.GetNamedArray(L"pieces")),
            winrt::MonsterHunterWilds::JsonParser::TryParseNamedObject(json_object, L"bonus", [](auto const& json_object) { return winrt::MonsterHunterWilds::ArmorSetBonus::Parse(json_object); }).as<winrt::MonsterHunterWilds::ArmorSetBonus>(),
            winrt::MonsterHunterWilds::ArmorSetBonus::TryParse(json_object, L"groupBonus")
        };
    }

    ArmorSet::ArmorSet(
        int32_t id,
        int32_t game_id,
        hstring const& name,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> const& pieces,
        winrt::MonsterHunterWilds::ArmorSetBonus const& bonus,
        winrt::MonsterHunterWilds::ArmorSetBonus const& group_bonus)
        : id_{ id }, game_id_{ game_id }, name_{ name }, pieces_{ pieces }, bonus_{ bonus }, group_bonus_{ group_bonus }
    {

    }

    int32_t ArmorSet::Id()
    {
        return id_;
    }

    int32_t ArmorSet::GameId()
    {
        return game_id_;
    }

    hstring ArmorSet::Name()
    {
        return name_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> ArmorSet::Pieces()
    {
        return pieces_;
    }

    winrt::MonsterHunterWilds::ArmorSetBonus ArmorSet::Bonus()
    {
        return bonus_;
    }

    winrt::MonsterHunterWilds::ArmorSetBonus ArmorSet::GroupBonus()
    {
        return group_bonus_;
    }
}
