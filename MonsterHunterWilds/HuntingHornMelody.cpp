#include "pch.h"
#include "HuntingHornMelody.h"
#include "HuntingHornMelody.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HuntingHornMelody HuntingHornMelody::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            ParseJsonArray(json_object.GetNamedArray(L"notes"), [](auto const& json_value) { return winrt::MonsterHunterWilds::EnumMap::HuntingHornNoteMap(json_value.GetString()); }),
            ParseJsonArray(json_object.GetNamedArray(L"songs"), [](auto const& json_value) { return winrt::MonsterHunterWilds::HuntingHornSong::Parse(json_value.GetObject()); })
        };
    }

    HuntingHornMelody::HuntingHornMelody(
        int32_t id,
        int32_t game_id,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> const& notes,
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> const& songs)
        : id_{ id }
        , game_id_{ game_id }
        , notes_{ notes }
        , songs_{ songs }
    {
        
    }

    int32_t HuntingHornMelody::Id()
    {
        return id_;
    }

    int32_t HuntingHornMelody::GameId()
    {
        return game_id_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> HuntingHornMelody::Notes()
    {
        return notes_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> HuntingHornMelody::Songs()
    {
        return songs_;
    }
}
