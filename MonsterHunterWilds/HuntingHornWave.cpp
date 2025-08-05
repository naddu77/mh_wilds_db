#include "pch.h"
#include "HuntingHornWave.h"
#include "HuntingHornWave.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HuntingHornWave HuntingHornWave::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            winrt::MonsterHunterWilds::EnumMap::HuntingHornWaveKindMap(L"kind"),
            json_object.GetNamedString(L"name")
        };
    }

    HuntingHornWave::HuntingHornWave(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::HuntingHornWaveKind const& kind, hstring const& name)
        : id_{ id }
        , game_id_{ game_id }
        , kind_{ kind }
        , name_{ name }
    {
        
    }

    int32_t HuntingHornWave::Id()
    {
        return id_;
    }

    int32_t HuntingHornWave::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::HuntingHornWaveKind HuntingHornWave::Kind()
    {
        return kind_;
    }

    hstring HuntingHornWave::Name()
    {
        return name_;
    }
}
