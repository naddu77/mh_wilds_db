#pragma once
#include "HuntingHornSong.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HuntingHornSong : HuntingHornSongT<HuntingHornSong>
    {
        HuntingHornSong(int32_t id, int32_t effect_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> const& sequence, hstring const& name);
        
        int32_t Id();
        int32_t EffectId();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> Sequence();
        hstring Name();

    private:
        int32_t id_;
        int32_t effect_id_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> sequence_;
        hstring name_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HuntingHornSong : HuntingHornSongT<HuntingHornSong, implementation::HuntingHornSong>
    {
    };
}
