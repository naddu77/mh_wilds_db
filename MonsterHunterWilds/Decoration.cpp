#include "pch.h"
#include "Decoration.h"
#include "Decoration.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Decoration Decoration::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            json_object.GetNamedString(L"name"),
            json_object.GetNamedString(L"description"),
            static_cast<int32_t>(json_object.GetNamedNumber(L"slot")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"rarity")),
            winrt::MonsterHunterWilds::EnumMap::DecorationKindMap(json_object.GetNamedString(L"kind")),
            ParseJsonArray(json_object.GetNamedArray(L"skills"), [](auto const& json_array) { return winrt::MonsterHunterWilds::SkillRank::Parse(json_array.GetObject()); }),
            winrt::MonsterHunterWilds::DecorationIcon::Parse(json_object.GetNamedObject(L"icon"))
        };
    }

    Decoration::Decoration(int32_t id, int32_t game_id, hstring const& name, hstring const& description, int32_t slot, int32_t rarity, winrt::MonsterHunterWilds::DecorationKind const& kind, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills, winrt::MonsterHunterWilds::DecorationIcon const& icon)
        : id_{ id }, game_id_{ game_id }, name_{ name }, description_{ description }, slot_{ slot }, rarity_{ rarity }, kind_{ kind }, skills_{ skills }, icon_{ icon }
    {

	}

    int32_t Decoration::Id()
    {
        return id_;
    }

    int32_t Decoration::GameId()
    {
        return game_id_;
    }

    hstring Decoration::Name()
    {
        return name_;
    }

    hstring Decoration::Description()
    {
        return description_;
    }

    int32_t Decoration::Slot()
    {
        return slot_;
    }

    int32_t Decoration::Rarity()
    {
        return rarity_;
    }

    winrt::MonsterHunterWilds::DecorationKind Decoration::Kind()
    {
        return kind_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Decoration::Skills()
    {
        return skills_;
    }

    winrt::MonsterHunterWilds::DecorationIcon Decoration::Icon()
    {
        return icon_;
    }
}
