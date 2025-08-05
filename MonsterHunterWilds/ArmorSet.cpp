#include "pch.h"
#include "ArmorSet.h"
#include "ArmorSet.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorSet ArmorSet::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            json_object.GetNamedString(L"name"),
            ParseJsonArray(json_object.GetNamedArray(L"pieces"), [](auto const& piece) { return winrt::MonsterHunterWilds::Armor(Armor::Parse(piece.GetObject())); }),
            ArmorSetBonus::Parse(json_object.GetNamedObject(L"bonus")),
            ArmorSetBonus::Parse(json_object.GetNamedObject(L"groupBonus"))
        };
    }

    ArmorSet::ArmorSet(int32_t id, int32_t game_id, hstring const& name, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> const& bonuses, winrt::MonsterHunterWilds::ArmorSetBonus const& bonus, winrt::MonsterHunterWilds::ArmorSetBonus const& group_bonus)
        : id_{ id }, game_id_{ game_id }, name_{ name }, bonuses_{ bonuses }, bonus_{ bonus }, group_bonus_{ group_bonus }
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

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> ArmorSet::Bonuses()
    {
        return bonuses_;
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
