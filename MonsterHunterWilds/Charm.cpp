#include "pch.h"
#include "Charm.h"
#include "Charm.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Charm::Charm(int32_t id, int32_t game_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> const& ranks)
        : id_{ id }, game_id_{ game_id }, ranks_{ ranks }
    {

	}

    int32_t Charm::Id()
    {
        return id_;
    }

    int32_t Charm::GameId()
    {
        return game_id_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::CharmRank> Charm::Ranks()
    {
        return ranks_;
    }
}
