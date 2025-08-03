#include "pch.h"
#include "HuntingHornMelody.h"
#include "HuntingHornMelody.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
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
