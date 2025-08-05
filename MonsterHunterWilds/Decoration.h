#pragma once
#include "Decoration.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Decoration : DecorationT<Decoration>
    {
        static winrt::MonsterHunterWilds::Decoration Parse(winrt::Windows::Data::Json::JsonObject const& json_object);

        Decoration(int32_t id, int32_t game_id, hstring const& name, hstring const& description, int32_t slot, int32_t rarity, winrt::MonsterHunterWilds::DecorationKind const& kind, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> const& skills, winrt::MonsterHunterWilds::DecorationIcon const& icon);
        
        int32_t Id();
        int32_t GameId();
        hstring Name();
        hstring Description();
        int32_t Slot();
        int32_t Rarity();
        winrt::MonsterHunterWilds::DecorationKind Kind();
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> Skills();
        winrt::MonsterHunterWilds::DecorationIcon Icon();

    private:
        int32_t id_;
        int32_t game_id_;
        hstring name_;
        hstring description_;
        int32_t slot_;
        int32_t rarity_;
        winrt::MonsterHunterWilds::DecorationKind kind_;
        winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::SkillRank> skills_;
		winrt::MonsterHunterWilds::DecorationIcon icon_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Decoration : DecorationT<Decoration, implementation::Decoration>
    {
    };
}
