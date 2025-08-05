#pragma once
#include "HuntingHornBubble.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HuntingHornBubble : HuntingHornBubbleT<HuntingHornBubble>
    {
        static winrt::MonsterHunterWilds::HuntingHornBubble Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        HuntingHornBubble(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::HuntingHornBubbleKind const& kind, hstring const& name);

        int32_t Id();
        int32_t GameId();
        winrt::MonsterHunterWilds::HuntingHornBubbleKind Kind();
        hstring Name();

    private:
        int32_t id_;
        int32_t game_id_;
        winrt::MonsterHunterWilds::HuntingHornBubbleKind kind_;
        hstring name_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HuntingHornBubble : HuntingHornBubbleT<HuntingHornBubble, implementation::HuntingHornBubble>
    {
    };
}
