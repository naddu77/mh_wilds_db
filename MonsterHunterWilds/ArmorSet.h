#pragma once
#include "ArmorSet.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct ArmorSet : ArmorSetT<ArmorSet>
    {
        ArmorSet(int32_t id, int32_t game_id, hstring const& name, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> const& bonuses, winrt::MonsterHunterWilds::ArmorSetBonus const& bonus, winrt::MonsterHunterWilds::ArmorSetBonus const& group_bonus);
        
        int32_t Id();
        int32_t GameId();
        hstring Name();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> Bonuses();
        winrt::MonsterHunterWilds::ArmorSetBonus Bonus();
        winrt::MonsterHunterWilds::ArmorSetBonus GroupBonus();

    private:
        int32_t id_;
        int32_t game_id_;
        hstring name_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Armor> bonuses_;
        winrt::MonsterHunterWilds::ArmorSetBonus bonus_;
        winrt::MonsterHunterWilds::ArmorSetBonus group_bonus_;
    };
}
namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct ArmorSet : ArmorSetT<ArmorSet, implementation::ArmorSet>
    {
    };
}
