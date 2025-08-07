#pragma once
#include "MonsterPart.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct MonsterPart : MonsterPartT<MonsterPart>
    {
        static winrt::MonsterHunterWilds::MonsterPart Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array);

        MonsterPart(int32_t id, winrt::MonsterHunterWilds::MonsterPartKind const& kind, winrt::Windows::Foundation::IReference<int32_t> health, winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> const& kinsect_essence, winrt::MonsterHunterWilds::DamageMultipliers const& multipliers);

        int32_t Id();
        winrt::MonsterHunterWilds::MonsterPartKind Kind();
        winrt::Windows::Foundation::IReference<int32_t> Health();
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> KinsectEssence();
        winrt::MonsterHunterWilds::DamageMultipliers Multipliers();

    private:
        int32_t id_;
        winrt::MonsterHunterWilds::MonsterPartKind kind_;
        winrt::Windows::Foundation::IReference<int32_t> health_;
        winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> kinsect_essence_;
	    winrt::MonsterHunterWilds::DamageMultipliers multipliers_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct MonsterPart : MonsterPartT<MonsterPart, implementation::MonsterPart>
    {
    };
}
