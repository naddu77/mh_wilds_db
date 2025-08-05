#include "pch.h"
#include "HuntingHornBubble.h"
#include "HuntingHornBubble.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HuntingHornBubble HuntingHornBubble::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"gameId")),
            winrt::MonsterHunterWilds::EnumMap::HuntingHornBubbleKindMap(L"kind"),
            json_object.GetNamedString(L"name")
        };
    }

    HuntingHornBubble::HuntingHornBubble(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::HuntingHornBubbleKind const& kind, hstring const& name)
        : id_{ id }
        , game_id_{ game_id }
        , kind_{ kind }
        , name_{ name }
    {
        
    }

    int32_t HuntingHornBubble::Id()
    {
        return id_;
    }

    int32_t HuntingHornBubble::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::HuntingHornBubbleKind HuntingHornBubble::Kind()
    {
        return kind_;
    }

    hstring HuntingHornBubble::Name()
    {
        return name_;
    }
}
