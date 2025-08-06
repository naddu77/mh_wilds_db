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
            winrt::MonsterHunterWilds::EnumMap::HuntingHornWaveKindMap(json_object.GetNamedString(L"kind")),
            json_object.GetNamedString(L"name")
        };
    }

    winrt::MonsterHunterWilds::HuntingHornWave HuntingHornWave::TryParse(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::Object)
            {
                return Parse(named_value.GetObject());
            }
        }

        return nullptr;
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
