#pragma once
#include "HuntingHornMelody.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HuntingHornMelody : HuntingHornMelodyT<HuntingHornMelody>
    {
        HuntingHornMelody(int32_t id, int32_t game_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> const& notes, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> const& songs);
        
        int32_t Id();
        int32_t GameId();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> Notes();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> Songs();

    private:
        int32_t id_;
        int32_t game_id_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> notes_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornSong> songs_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HuntingHornMelody : HuntingHornMelodyT<HuntingHornMelody, implementation::HuntingHornMelody>
    {
    };
}
