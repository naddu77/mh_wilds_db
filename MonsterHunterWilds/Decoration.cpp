#include "pch.h"
#include "Decoration.h"
#include "Decoration.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Decoration Decoration::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
            json_object.GetNamedString(L"name"),
            json_object.GetNamedString(L"description"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"slot"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"rarity"),
            winrt::MonsterHunterWilds::EnumMap::DecorationKindMap(json_object.GetNamedString(L"kind")),
            winrt::MonsterHunterWilds::SkillRank::ParseJsonArray(json_object.GetNamedArray(L"skills")),           
            winrt::MonsterHunterWilds::DecorationIcon::Parse(json_object.GetNamedObject(L"icon"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Decoration> Decoration::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
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
