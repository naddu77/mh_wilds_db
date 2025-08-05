#pragma once
#include "HuntingHornWave.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct HuntingHornWave : HuntingHornWaveT<HuntingHornWave>
    {
        static winrt::MonsterHunterWilds::HuntingHornWave Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        HuntingHornWave(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::HuntingHornWaveKind const& kind, hstring const& name);

        int32_t Id();
        int32_t GameId();
        winrt::MonsterHunterWilds::HuntingHornWaveKind Kind();
        hstring Name();

    private:
        int32_t id_;
        int32_t game_id_;
        winrt::MonsterHunterWilds::HuntingHornWaveKind kind_;
        hstring name_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct HuntingHornWave : HuntingHornWaveT<HuntingHornWave, implementation::HuntingHornWave>
    {
    };
}
