#pragma once
#include "EnumMap.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct EnumMap
    {
        static winrt::MonsterHunterWilds::Color ColorMap(hstring const& str);
        static winrt::MonsterHunterWilds::ItemIconKind ItemIconKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::SkillKind SkillKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::SkillIconKind SkillIconKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::Element ElementMap(hstring const& str);
        static winrt::MonsterHunterWilds::Status StatusMap(hstring const& str);
		static winrt::MonsterHunterWilds::Effect EffectMap(hstring const& str);
        static winrt::MonsterHunterWilds::ArmorKind ArmorKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::Rank RankMap(hstring const& str);
        static winrt::MonsterHunterWilds::DecorationKind DecorationKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::Elderseal EldersealMap(hstring const& str);
        static winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> TryEldersealMap(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);
        static winrt::MonsterHunterWilds::WeaponKind WeaponKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::ChargeBladePhial ChargeBladePhialMap(hstring const& str);
        static winrt::MonsterHunterWilds::SwitchAxePhial SwitchAxePhialMap(hstring const& str);
        static winrt::MonsterHunterWilds::HuntingHornNote HuntingHornNoteMap(hstring const& str);
        static winrt::MonsterHunterWilds::HuntingHornBubbleKind HuntingHornBubbleKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::AmmoKind AmmoKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::HuntingHornWaveKind HuntingHornWaveKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::BowCoating BowCoatingMap(hstring const& str);
        static winrt::MonsterHunterWilds::GunlanceShell GunlanceShellMap(hstring const& str);
        static winrt::MonsterHunterWilds::LightBowgunSpecialAmmo LightBowgunSpecialAmmoMap(hstring const& str);
		static winrt::MonsterHunterWilds::Risk RiskMap(hstring const& str);
		static winrt::MonsterHunterWilds::MonsterKind MonsterKindMap(hstring const& str);
		static winrt::MonsterHunterWilds::Species SpeciesMap(hstring const& str);
		static winrt::MonsterHunterWilds::RewardConditionKind RewardConditionKindMap(hstring const& str);
		static winrt::MonsterHunterWilds::MonsterPartKind MonsterPartKindMap(hstring const& str);
        static winrt::MonsterHunterWilds::KinsectEssence KinsectEssenceMap(hstring const& str);
		static winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> TryKinsectEssenceMap(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key);
		static winrt::MonsterHunterWilds::DamageKind DamageKindMap(hstring const& str);
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct EnumMap : EnumMapT<EnumMap, implementation::EnumMap>
    {
    };
}
