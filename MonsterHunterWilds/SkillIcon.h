#pragma once
#include "SkillIcon.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct SkillIcon : SkillIconT<SkillIcon>
    {
        static winrt::MonsterHunterWilds::SkillIcon Parse(winrt::Windows::Data::Json::JsonObject const& json_object);
        static winrt::MonsterHunterWilds::SkillIcon TryParse(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);

        SkillIcon(int32_t game_id, winrt::MonsterHunterWilds::SkillIconKind const& kind);

        int32_t GameId();
        winrt::MonsterHunterWilds::SkillIconKind Kind();

    private:
        int32_t game_id_;
		winrt::MonsterHunterWilds::SkillIconKind kind_;
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct SkillIcon : SkillIconT<SkillIcon, implementation::SkillIcon>
    {
    };
}
