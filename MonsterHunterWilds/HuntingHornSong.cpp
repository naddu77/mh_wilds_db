#include "pch.h"
#include "HuntingHornSong.h"
#include "HuntingHornSong.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HuntingHornSong HuntingHornSong::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"effectId"),
            winrt::single_threaded_vector(
                json_object.GetNamedArray(L"sequence")
                | std::views::transform([](auto const& json_value) { return winrt::MonsterHunterWilds::EnumMap::HuntingHornNoteMap(json_value.GetString()); })
                | std::ranges::to<std::vector>()
            ),
            json_object.GetNamedString(L"name")
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> HuntingHornSong::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](auto const& json_value) { return Parse(json_value.GetObject()); })
            | std::ranges::to<std::vector>()
        );
    }

    HuntingHornSong::HuntingHornSong(int32_t id, int32_t effect_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> const& sequence, hstring const& name)
        : id_{ id }
        , effect_id_{ effect_id }
        , sequence_{ sequence }
        , name_{ name }
    {
        
    }

    int32_t HuntingHornSong::Id()
    {
        return id_;
    }

    int32_t HuntingHornSong::EffectId()
    {
        return effect_id_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> HuntingHornSong::Sequence()
    {
        return sequence_;
    }

    hstring HuntingHornSong::Name()
    {
        return name_;
    }
}
