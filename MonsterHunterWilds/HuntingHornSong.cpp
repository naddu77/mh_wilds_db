#include "pch.h"
#include "HuntingHornSong.h"
#include "HuntingHornSong.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
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
