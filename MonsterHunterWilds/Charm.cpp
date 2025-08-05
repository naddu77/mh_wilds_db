#include "pch.h"
#include "Charm.h"
#include "Charm.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Charm Charm::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            ParseJsonArray(json_object.GetNamedArray(L"ranks"), [](auto const& r) { return winrt::MonsterHunterWilds::CharmRank::Parse(r.GetObject()); })
        };
    }

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
