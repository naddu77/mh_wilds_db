#pragma once
#include "Charm.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Charm : CharmT<Charm>
    {
        Charm() = default;

        Charm(int32_t id, int32_t game_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> const& ranks);
        int32_t Id();
        int32_t GameId();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> Ranks();

    private:
        int32_t id_;
        int32_t game_id_;
		winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> ranks_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Charm : CharmT<Charm, implementation::Charm>
    {
    };
}
