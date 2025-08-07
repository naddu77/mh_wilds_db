#include "pch.h"
#include "EnumMap.h"
#include "EnumMap.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Color EnumMap::ColorMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Color> const color_map{
            { L"white", winrt::MonsterHunterWilds::Color::White },
            { L"gray", winrt::MonsterHunterWilds::Color::Gray },
            { L"rose", winrt::MonsterHunterWilds::Color::Rose },
            { L"pink", winrt::MonsterHunterWilds::Color::Pink },
            { L"red", winrt::MonsterHunterWilds::Color::Red },
            { L"vermilion", winrt::MonsterHunterWilds::Color::Vermilion },
            { L"orange", winrt::MonsterHunterWilds::Color::Orange },
            { L"brown", winrt::MonsterHunterWilds::Color::Brown },
            { L"ivory", winrt::MonsterHunterWilds::Color::Ivory },
            { L"yellow", winrt::MonsterHunterWilds::Color::Yellow },
            { L"lemon", winrt::MonsterHunterWilds::Color::Lemon },
            { L"sage-green", winrt::MonsterHunterWilds::Color::SageGreen },
            { L"moss-green", winrt::MonsterHunterWilds::Color::MossGreen },
            { L"green", winrt::MonsterHunterWilds::Color::Green },
            { L"emerald", winrt::MonsterHunterWilds::Color::Emerald },
            { L"sky", winrt::MonsterHunterWilds::Color::Sky },
            { L"blue", winrt::MonsterHunterWilds::Color::Blue },
            { L"ultramarine", winrt::MonsterHunterWilds::Color::Ultramarine },
            { L"blue-purple", winrt::MonsterHunterWilds::Color::BluePurple },
            { L"purple", winrt::MonsterHunterWilds::Color::Purple },
            { L"dark-purple", winrt::MonsterHunterWilds::Color::DarkPurple },
        };

        if (auto found{ color_map.find(str) };
            found != std::end(color_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::ItemIconKind EnumMap::ItemIconKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::ItemIconKind> item_icon_kind_map{
            { L"ammo-basic", winrt::MonsterHunterWilds::ItemIconKind::AmmoBasic },
            { L"ammo-heavy", winrt::MonsterHunterWilds::ItemIconKind::AmmoHeavy },
            { L"ammo-slug", winrt::MonsterHunterWilds::ItemIconKind::AmmoSlug },
            { L"ammo-special", winrt::MonsterHunterWilds::ItemIconKind::AmmoSpecial },
            { L"ammo-utility", winrt::MonsterHunterWilds::ItemIconKind::AmmoUtility },
            { L"armor-sphere", winrt::MonsterHunterWilds::ItemIconKind::ArmorSphere },
            { L"barrel", winrt::MonsterHunterWilds::ItemIconKind::Barrel },
            { L"binoculars", winrt::MonsterHunterWilds::ItemIconKind::Binoculars },
            { L"bomb", winrt::MonsterHunterWilds::ItemIconKind::Bomb },
            { L"bone", winrt::MonsterHunterWilds::ItemIconKind::Bone },
            { L"bug", winrt::MonsterHunterWilds::ItemIconKind::Bug },
            { L"camping-kit", winrt::MonsterHunterWilds::ItemIconKind::CampingKit },
            { L"capture-net", winrt::MonsterHunterWilds::ItemIconKind::CaptureNet },
            { L"certificate", winrt::MonsterHunterWilds::ItemIconKind::Certificate },
            { L"claw", winrt::MonsterHunterWilds::ItemIconKind::Claw },
            { L"coin", winrt::MonsterHunterWilds::ItemIconKind::Coin },
            { L"cooking-cheese", winrt::MonsterHunterWilds::ItemIconKind::CookingCheese },
            { L"cooking-egg", winrt::MonsterHunterWilds::ItemIconKind::CookingEgg },
            { L"cooking-garlic", winrt::MonsterHunterWilds::ItemIconKind::CookingGarlic },
            { L"cooking-mushroom", winrt::MonsterHunterWilds::ItemIconKind::CookingMushroom },
            { L"cooking-shellfish", winrt::MonsterHunterWilds::ItemIconKind::CookingShellfish },
            { L"crystal", winrt::MonsterHunterWilds::ItemIconKind::Crystal },
            { L"curative", winrt::MonsterHunterWilds::ItemIconKind::Curative },
            { L"drug", winrt::MonsterHunterWilds::ItemIconKind::Drug },
            { L"egg", winrt::MonsterHunterWilds::ItemIconKind::Egg },
            { L"extract", winrt::MonsterHunterWilds::ItemIconKind::Extract },
            { L"fishing-rod", winrt::MonsterHunterWilds::ItemIconKind::FishingRod },
            { L"fish", winrt::MonsterHunterWilds::ItemIconKind::Fish },
            { L"gem", winrt::MonsterHunterWilds::ItemIconKind::Gem },
            { L"grill", winrt::MonsterHunterWilds::ItemIconKind::Grill },
            { L"hide", winrt::MonsterHunterWilds::ItemIconKind::Hide },
            { L"honey", winrt::MonsterHunterWilds::ItemIconKind::Honey },
            { L"mantle", winrt::MonsterHunterWilds::ItemIconKind::Mantle },
            { L"meat", winrt::MonsterHunterWilds::ItemIconKind::Meat },
            { L"medulla", winrt::MonsterHunterWilds::ItemIconKind::Medulla },
            { L"mushroom", winrt::MonsterHunterWilds::ItemIconKind::Mushroom },
            { L"mystery-artian", winrt::MonsterHunterWilds::ItemIconKind::MysteryArtian },
            { L"mystery-decoration", winrt::MonsterHunterWilds::ItemIconKind::MysteryDecoration },
            { L"mystery-material", winrt::MonsterHunterWilds::ItemIconKind::MysteryMaterial },
            { L"nut", winrt::MonsterHunterWilds::ItemIconKind::Nut },
            { L"ore", winrt::MonsterHunterWilds::ItemIconKind::Ore },
            { L"phial", winrt::MonsterHunterWilds::ItemIconKind::Phial },
            { L"pill", winrt::MonsterHunterWilds::ItemIconKind::Pill },
            { L"plant", winrt::MonsterHunterWilds::ItemIconKind::Plant },
            { L"plate", winrt::MonsterHunterWilds::ItemIconKind::Plate },
            { L"poop", winrt::MonsterHunterWilds::ItemIconKind::Poop },
            { L"potion", winrt::MonsterHunterWilds::ItemIconKind::Potion },
            { L"powder", winrt::MonsterHunterWilds::ItemIconKind::Powder },
            { L"question", winrt::MonsterHunterWilds::ItemIconKind::Question },
            { L"scale", winrt::MonsterHunterWilds::ItemIconKind::Scale },
            { L"seed", winrt::MonsterHunterWilds::ItemIconKind::Seed },
            { L"shell", winrt::MonsterHunterWilds::ItemIconKind::Shell },
            { L"skull", winrt::MonsterHunterWilds::ItemIconKind::Skull },
            { L"slinger-ammo", winrt::MonsterHunterWilds::ItemIconKind::SlingerAmmo },
            { L"smoke", winrt::MonsterHunterWilds::ItemIconKind::Smoke },
            { L"sprout", winrt::MonsterHunterWilds::ItemIconKind::Sprout },
            { L"tail", winrt::MonsterHunterWilds::ItemIconKind::Tail },
            { L"trap", winrt::MonsterHunterWilds::ItemIconKind::Trap },
            { L"trap-tool", winrt::MonsterHunterWilds::ItemIconKind::TrapTool },
            { L"unknown",  winrt::MonsterHunterWilds::ItemIconKind::Unknown },
            { L"voucher", winrt::MonsterHunterWilds::ItemIconKind::Voucher },
            { L"web", winrt::MonsterHunterWilds::ItemIconKind::Web },
            { L"whetstone", winrt::MonsterHunterWilds::ItemIconKind::Whetstone },
            { L"wing", winrt::MonsterHunterWilds::ItemIconKind::Wing },
            { L"knife", winrt::MonsterHunterWilds::ItemIconKind::Knife },
        };

        if (auto found{ item_icon_kind_map.find(str) };
            found != std::end(item_icon_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::SkillKind EnumMap::SkillKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::SkillKind> skill_kind_map{
            { L"armor", winrt::MonsterHunterWilds::SkillKind::Armor },
            { L"weapon", winrt::MonsterHunterWilds::SkillKind::Weapon },
            { L"set", winrt::MonsterHunterWilds::SkillKind::Set },
            { L"group", winrt::MonsterHunterWilds::SkillKind::Group }
        };

        if (auto found{ skill_kind_map.find(str) };
            found != std::end(skill_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::SkillIconKind EnumMap::SkillIconKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::SkillIconKind> skill_icon_kind_map{
            { L"affinity", winrt::MonsterHunterWilds::SkillIconKind::Affinity },
            { L"attack", winrt::MonsterHunterWilds::SkillIconKind::Attack },
            { L"defense", winrt::MonsterHunterWilds::SkillIconKind::Defense },
            { L"element", winrt::MonsterHunterWilds::SkillIconKind::Element },
            { L"gathering", winrt::MonsterHunterWilds::SkillIconKind::Gathering },
            { L"group", winrt::MonsterHunterWilds::SkillIconKind::Group },
            { L"handicraft", winrt::MonsterHunterWilds::SkillIconKind::Handicraft },
            { L"health", winrt::MonsterHunterWilds::SkillIconKind::Health },
            { L"item", winrt::MonsterHunterWilds::SkillIconKind::Item },
            { L"offense", winrt::MonsterHunterWilds::SkillIconKind::Offense },
            { L"ranged", winrt::MonsterHunterWilds::SkillIconKind::Ranged },
            { L"set", winrt::MonsterHunterWilds::SkillIconKind::Set },
            { L"stamina", winrt::MonsterHunterWilds::SkillIconKind::Stamina },
            { L"utility", winrt::MonsterHunterWilds::SkillIconKind::Utility }
        };

        if (auto found{ skill_icon_kind_map.find(str) };
            found != std::end(skill_icon_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Element EnumMap::ElementMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Element> element_map{
            { L"fire", winrt::MonsterHunterWilds::Element::Fire },
            { L"water", winrt::MonsterHunterWilds::Element::Water },
            { L"ice", winrt::MonsterHunterWilds::Element::Ice },
            { L"thunder", winrt::MonsterHunterWilds::Element::Thunder },
            { L"dragon", winrt::MonsterHunterWilds::Element::Dragon }
        };

        if (auto found{ element_map.find(str) };
            found != std::end(element_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Status EnumMap::StatusMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Status> status_map{
            { L"poison", winrt::MonsterHunterWilds::Status::Poison },
            { L"sleep", winrt::MonsterHunterWilds::Status::Sleep },
            { L"paralysis", winrt::MonsterHunterWilds::Status::Paralysis },
            { L"stun", winrt::MonsterHunterWilds::Status::Stun },
            { L"blastblight", winrt::MonsterHunterWilds::Status::Blastblight }
        };

        if (auto found{ status_map.find(str) };
            found != std::end(status_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Effect EnumMap::EffectMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Effect> effect_map{
            { L"noise", winrt::MonsterHunterWilds::Effect::Noise },
            { L"flash", winrt::MonsterHunterWilds::Effect::Flash },
            { L"stun", winrt::MonsterHunterWilds::Effect::Stun },
            { L"exhaust", winrt::MonsterHunterWilds::Effect::Exhaust }
        };

        if (auto found{ effect_map.find(str) };
            found != std::end(effect_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
	}

    winrt::MonsterHunterWilds::ArmorKind EnumMap::ArmorKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::ArmorKind> const armor_kind_map{
            { L"head", winrt::MonsterHunterWilds::ArmorKind::Head },
            { L"chest", winrt::MonsterHunterWilds::ArmorKind::Chest },
            { L"arms", winrt::MonsterHunterWilds::ArmorKind::Arms },
            { L"waist", winrt::MonsterHunterWilds::ArmorKind::Waist },
            { L"legs", winrt::MonsterHunterWilds::ArmorKind::Legs }
        };

        if (auto found{ armor_kind_map.find(str) };
            found != std::end(armor_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Rank EnumMap::RankMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Rank> const rank_map{
            { L"low", winrt::MonsterHunterWilds::Rank::Low },
            { L"high", winrt::MonsterHunterWilds::Rank::High },
            { L"master", winrt::MonsterHunterWilds::Rank::Master }
        };

        if (auto found{ rank_map.find(str) };
            found != std::end(rank_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::DecorationKind EnumMap::DecorationKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::DecorationKind> const decoration_kind_map{
            { L"weapon", winrt::MonsterHunterWilds::DecorationKind::Weapon },
            { L"armor", winrt::MonsterHunterWilds::DecorationKind::Armor }
        };

        if (auto found{ decoration_kind_map.find(str) };
            found != std::end(decoration_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Elderseal EnumMap::EldersealMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Elderseal> const elderseal_map{
            { L"low", winrt::MonsterHunterWilds::Elderseal::Low },
            { L"average", winrt::MonsterHunterWilds::Elderseal::Average },
            { L"high", winrt::MonsterHunterWilds::Elderseal::High }
        };

        if (auto found{ elderseal_map.find(str) };
            found != std::end(elderseal_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::Elderseal> EnumMap::TryEldersealMap(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::String)
            {
                return EldersealMap(named_value.GetString());
            }
        }

        return {};
    }

    winrt::MonsterHunterWilds::WeaponKind EnumMap::WeaponKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::WeaponKind> const weapon_kind_map{
            { L"bow", winrt::MonsterHunterWilds::WeaponKind::Bow },
            { L"hunting-horn", winrt::MonsterHunterWilds::WeaponKind::HuntingHorn },
            { L"charge-blade", winrt::MonsterHunterWilds::WeaponKind::ChargeBlade },
            { L"insect-glaive", winrt::MonsterHunterWilds::WeaponKind::InsectGlaive },
            { L"dual-blades", winrt::MonsterHunterWilds::WeaponKind::DualBlades },
            { L"lance", winrt::MonsterHunterWilds::WeaponKind::Lance },
            { L"great-sword", winrt::MonsterHunterWilds::WeaponKind::GreatSword },
            { L"light-bowgun", winrt::MonsterHunterWilds::WeaponKind::LightBowgun },
            { L"gunlance", winrt::MonsterHunterWilds::WeaponKind::Gunlance },
            { L"long-sword", winrt::MonsterHunterWilds::WeaponKind::LongSword },
            { L"hammer", winrt::MonsterHunterWilds::WeaponKind::Hammer },
            { L"switch-axe", winrt::MonsterHunterWilds::WeaponKind::SwitchAxe },
            { L"heavy-bowgun", winrt::MonsterHunterWilds::WeaponKind::HeavyBowgun },
            { L"sword-shield", winrt::MonsterHunterWilds::WeaponKind::SwordShield }
        };

        if (auto found{ weapon_kind_map.find(str) };
            found != std::end(weapon_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::ChargeBladePhial EnumMap::ChargeBladePhialMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::ChargeBladePhial> const charge_blade_phial_map{
            { L"element", winrt::MonsterHunterWilds::ChargeBladePhial::Element },
            { L"impact", winrt::MonsterHunterWilds::ChargeBladePhial::Impact }
        };

        if (auto found{ charge_blade_phial_map.find(str) };
            found != std::end(charge_blade_phial_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::SwitchAxePhial EnumMap::SwitchAxePhialMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::SwitchAxePhial> const switch_axe_phial_map{
           { L"power", winrt::MonsterHunterWilds::SwitchAxePhial::Power },
           { L"element", winrt::MonsterHunterWilds::SwitchAxePhial::Element },
           { L"dragon", winrt::MonsterHunterWilds::SwitchAxePhial::Dragon },
           { L"exhaust", winrt::MonsterHunterWilds::SwitchAxePhial::Exhaust },
           { L"paralyze", winrt::MonsterHunterWilds::SwitchAxePhial::Parayze },
           { L"poison", winrt::MonsterHunterWilds::SwitchAxePhial::Poison }
        };

        if (auto found{ switch_axe_phial_map.find(str) };
            found != std::end(switch_axe_phial_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::HuntingHornNote EnumMap::HuntingHornNoteMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::HuntingHornNote> const hunting_horn_note_map{
           { L"purple", winrt::MonsterHunterWilds::HuntingHornNote::Purple },
           { L"red", winrt::MonsterHunterWilds::HuntingHornNote::Red },
           { L"orange", winrt::MonsterHunterWilds::HuntingHornNote::Orange },
           { L"yellow", winrt::MonsterHunterWilds::HuntingHornNote::Yellow },
           { L"green", winrt::MonsterHunterWilds::HuntingHornNote::Green },
           { L"blue", winrt::MonsterHunterWilds::HuntingHornNote::Blue },
           { L"aqua", winrt::MonsterHunterWilds::HuntingHornNote::Aqua },
           { L"white", winrt::MonsterHunterWilds::HuntingHornNote::White },
        };

        if (auto found{ hunting_horn_note_map.find(str) };
            found != std::end(hunting_horn_note_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::HuntingHornBubbleKind EnumMap::HuntingHornBubbleKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::HuntingHornBubbleKind> const hunting_horn_bubble_kind_map{
           { L"evasion", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Evasion },
           { L"damage", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Damage },
           { L"regen", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Regen },
           { L"defense", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Defense },
           { L"stamina", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Stamina },
           { L"immunity", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Immunity }
        };

        if (auto found{ hunting_horn_bubble_kind_map.find(str) };
            found != std::end(hunting_horn_bubble_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::AmmoKind EnumMap::AmmoKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::AmmoKind> const ammo_kind_map{
            { L"normal",    winrt::MonsterHunterWilds::AmmoKind::Normal },
            { L"pierce",    winrt::MonsterHunterWilds::AmmoKind::Pierce },
            { L"spread",    winrt::MonsterHunterWilds::AmmoKind::Spread },
            { L"slicing",   winrt::MonsterHunterWilds::AmmoKind::Slicing },
            { L"sticky",    winrt::MonsterHunterWilds::AmmoKind::Sticky },
            { L"cluster",   winrt::MonsterHunterWilds::AmmoKind::Cluster },
            { L"wyvern",    winrt::MonsterHunterWilds::AmmoKind::Wyvern },
            { L"poison",    winrt::MonsterHunterWilds::AmmoKind::Poison },
            { L"paralysis", winrt::MonsterHunterWilds::AmmoKind::Paralysis },
            { L"sleep",     winrt::MonsterHunterWilds::AmmoKind::Sleep },
            { L"flaming",   winrt::MonsterHunterWilds::AmmoKind::Flaming },
            { L"water",     winrt::MonsterHunterWilds::AmmoKind::Water },
            { L"freeze",    winrt::MonsterHunterWilds::AmmoKind::Freeze },
            { L"thunder",   winrt::MonsterHunterWilds::AmmoKind::Thunder },
            { L"dragon",    winrt::MonsterHunterWilds::AmmoKind::Dragon },
            { L"recover",   winrt::MonsterHunterWilds::AmmoKind::Recover },
            { L"demon",     winrt::MonsterHunterWilds::AmmoKind::Demon },
            { L"armor",     winrt::MonsterHunterWilds::AmmoKind::Armor },
            { L"exhaust",   winrt::MonsterHunterWilds::AmmoKind::Exhaust },
            { L"tranq",     winrt::MonsterHunterWilds::AmmoKind::Tranq },
        };

        if (auto found{ ammo_kind_map.find(str) };
            found != ammo_kind_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::HuntingHornWaveKind EnumMap::HuntingHornWaveKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::HuntingHornWaveKind> const hunting_horn_wave_kind_map{
            { L"blunt",    winrt::MonsterHunterWilds::HuntingHornWaveKind::Blunt },
            { L"slash",    winrt::MonsterHunterWilds::HuntingHornWaveKind::Slash },
            { L"fire",     winrt::MonsterHunterWilds::HuntingHornWaveKind::Fire },
            { L"water",    winrt::MonsterHunterWilds::HuntingHornWaveKind::Water },
            { L"thunder",  winrt::MonsterHunterWilds::HuntingHornWaveKind::Thunder },
            { L"ice",      winrt::MonsterHunterWilds::HuntingHornWaveKind::Ice },
            { L"dragon",   winrt::MonsterHunterWilds::HuntingHornWaveKind::Dragon },
            { L"poison",   winrt::MonsterHunterWilds::HuntingHornWaveKind::Poison },
            { L"paralyze", winrt::MonsterHunterWilds::HuntingHornWaveKind::Paralyze },
            { L"sleep",    winrt::MonsterHunterWilds::HuntingHornWaveKind::Sleep },
            { L"blast",    winrt::MonsterHunterWilds::HuntingHornWaveKind::Blast },
        };

        if (auto found{ hunting_horn_wave_kind_map.find(str) };
            found != hunting_horn_wave_kind_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::BowCoating EnumMap::BowCoatingMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::BowCoating> const bow_coating_map{
            { L"close-range", winrt::MonsterHunterWilds::BowCoating::CloseRange },
            { L"power",       winrt::MonsterHunterWilds::BowCoating::Power },
            { L"pierce",      winrt::MonsterHunterWilds::BowCoating::Pierce },
            { L"paralysis",   winrt::MonsterHunterWilds::BowCoating::Paralysis },
            { L"poison",      winrt::MonsterHunterWilds::BowCoating::Poison },
            { L"sleep",       winrt::MonsterHunterWilds::BowCoating::Sleep },
            { L"blast",       winrt::MonsterHunterWilds::BowCoating::Blast },
            { L"exhaust",     winrt::MonsterHunterWilds::BowCoating::Exhaust },
        };

        if (auto found = bow_coating_map.find(str);
            found != bow_coating_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::GunlanceShell EnumMap::GunlanceShellMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::GunlanceShell> const gunlance_shell_map{
            { L"normal", winrt::MonsterHunterWilds::GunlanceShell::Normal },
            { L"wide",   winrt::MonsterHunterWilds::GunlanceShell::Wide },
            { L"long",   winrt::MonsterHunterWilds::GunlanceShell::Long },
        };

        if (auto found = gunlance_shell_map.find(str);
            found != gunlance_shell_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::LightBowgunSpecialAmmo EnumMap::LightBowgunSpecialAmmoMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::LightBowgunSpecialAmmo> const light_bowgun_special_ammo_map{
            { L"wyvernblast", winrt::MonsterHunterWilds::LightBowgunSpecialAmmo::Wyvernblast },
            { L"adhesive",    winrt::MonsterHunterWilds::LightBowgunSpecialAmmo::Adhesive },
        };

        if (auto found = light_bowgun_special_ammo_map.find(str);
            found != light_bowgun_special_ammo_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::Risk EnumMap::RiskMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Risk> const risk_map{
            { L"safe", winrt::MonsterHunterWilds::Risk::Safe },
            { L"insecure", winrt::MonsterHunterWilds::Risk::Insecure },
            { L"dangerous", winrt::MonsterHunterWilds::Risk::Dangerous }
        };

        if (auto found{ risk_map.find(str) };
            found != risk_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
	}

    winrt::MonsterHunterWilds::MonsterKind EnumMap::MonsterKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::MonsterKind> const monster_kind_map{
            { L"small", winrt::MonsterHunterWilds::MonsterKind::Small },
            { L"large", winrt::MonsterHunterWilds::MonsterKind::Large }
        };

        if (auto found{ monster_kind_map.find(str) };
            found != monster_kind_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
	}

    winrt::MonsterHunterWilds::Species EnumMap::SpeciesMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::Species> const species_map{
            { L"flying-wyvern",  winrt::MonsterHunterWilds::Species::FlyingWyvern },
            { L"fish",           winrt::MonsterHunterWilds::Species::Fish },
            { L"herbivore",      winrt::MonsterHunterWilds::Species::Herbivore },
            { L"lynian",         winrt::MonsterHunterWilds::Species::Lynian },
            { L"neopteron",      winrt::MonsterHunterWilds::Species::Neopteron },
            { L"carapaceon",     winrt::MonsterHunterWilds::Species::Carapaceon },
            { L"fanged-beast",   winrt::MonsterHunterWilds::Species::FangedBeast },
            { L"bird-wyvern",    winrt::MonsterHunterWilds::Species::BirdWyvern },
            { L"piscine-wyvern", winrt::MonsterHunterWilds::Species::PiscineWyvern },
            { L"leviathan",      winrt::MonsterHunterWilds::Species::Leviathan },
            { L"brute-wyvern",   winrt::MonsterHunterWilds::Species::BruteWyvern },
            { L"fanged-wyvern",  winrt::MonsterHunterWilds::Species::FangedWyvern },
            { L"amphibian",      winrt::MonsterHunterWilds::Species::Amphibian },
            { L"temnoceran",     winrt::MonsterHunterWilds::Species::Temnoceran },
            { L"snake-wyvern",   winrt::MonsterHunterWilds::Species::SnakeWyvern },
            { L"elder-dragon",   winrt::MonsterHunterWilds::Species::ElderDragon },
            { L"cephalopod",     winrt::MonsterHunterWilds::Species::Cephalopod },
            { L"construct",      winrt::MonsterHunterWilds::Species::Construct },
            { L"wingdrake",      winrt::MonsterHunterWilds::Species::Wingdrake },
            { L"demi-elder",     winrt::MonsterHunterWilds::Species::DemiElder },
        };

        if (auto found{ species_map.find(str) };
            found != species_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::RewardConditionKind EnumMap::RewardConditionKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::RewardConditionKind> const reward_condition_kind_map{
            { L"carve", winrt::MonsterHunterWilds::RewardConditionKind::Carve },
            { L"carve-severed", winrt::MonsterHunterWilds::RewardConditionKind::CarveSevered },
            { L"endemic-capture", winrt::MonsterHunterWilds::RewardConditionKind::EndemicCapture },
            { L"target-reward", winrt::MonsterHunterWilds::RewardConditionKind::TargetReward },
            { L"broken-part", winrt::MonsterHunterWilds::RewardConditionKind::BrokenPart },
            { L"wound-destroyed", winrt::MonsterHunterWilds::RewardConditionKind::WoundDestroyed },
            { L"carve-rotten", winrt::MonsterHunterWilds::RewardConditionKind::CarveRotten },
            { L"slinger-gather", winrt::MonsterHunterWilds::RewardConditionKind::SlingerGather },
            { L"carve-rotten-severed", winrt::MonsterHunterWilds::RewardConditionKind::CarveRottenSevered },
            { L"tempered-wound-destroyed", winrt::MonsterHunterWilds::RewardConditionKind::TemperedWoundDestroyed },
            { L"carve-crystallized", winrt::MonsterHunterWilds::RewardConditionKind::CarveCrystallized },
        };

        if (auto found = reward_condition_kind_map.find(str);
            found != reward_condition_kind_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::MonsterPartKind EnumMap::MonsterPartKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::MonsterPartKind> const monster_part_kind_map{
            { L"neck", winrt::MonsterHunterWilds::MonsterPartKind::Neck },
            { L"left-front-leg", winrt::MonsterHunterWilds::MonsterPartKind::LeftFrontLeg },
            { L"head", winrt::MonsterHunterWilds::MonsterPartKind::Head },
            { L"right-wing-arm-wear", winrt::MonsterHunterWilds::MonsterPartKind::RightWingArmWear },
            { L"left-wing-arm-wear", winrt::MonsterHunterWilds::MonsterPartKind::LeftWingArmWear },
            { L"head-wear", winrt::MonsterHunterWilds::MonsterPartKind::HeadWear },
            { L"left-wing-arm-hide", winrt::MonsterHunterWilds::MonsterPartKind::LeftWingArmHide },
            { L"right-wing-arm-hide", winrt::MonsterHunterWilds::MonsterPartKind::RightWingArmHide },
            { L"left-wing-arm", winrt::MonsterHunterWilds::MonsterPartKind::LeftWingArm },
            { L"head-hide", winrt::MonsterHunterWilds::MonsterPartKind::HeadHide },
            { L"right-wing-arm", winrt::MonsterHunterWilds::MonsterPartKind::RightWingArm },
            { L"left-hind-leg", winrt::MonsterHunterWilds::MonsterPartKind::LeftHindLeg },
            { L"right-hind-leg", winrt::MonsterHunterWilds::MonsterPartKind::RightHindLeg },
            { L"torso", winrt::MonsterHunterWilds::MonsterPartKind::Torso },
            { L"right-front-leg", winrt::MonsterHunterWilds::MonsterPartKind::RightFrontLeg },
            { L"tail", winrt::MonsterHunterWilds::MonsterPartKind::Tail },
            { L"tail-hair", winrt::MonsterHunterWilds::MonsterPartKind::TailHair },
            { L"left-wing", winrt::MonsterHunterWilds::MonsterPartKind::LeftWing },
            { L"right-leg", winrt::MonsterHunterWilds::MonsterPartKind::RightLeg },
            { L"hide", winrt::MonsterHunterWilds::MonsterPartKind::Hide },
            { L"right-wing", winrt::MonsterHunterWilds::MonsterPartKind::RightWing },
            { L"left-leg", winrt::MonsterHunterWilds::MonsterPartKind::LeftLeg },
            { L"right-nail", winrt::MonsterHunterWilds::MonsterPartKind::RightNail },
            { L"petal", winrt::MonsterHunterWilds::MonsterPartKind::Petal },
            { L"left-nail", winrt::MonsterHunterWilds::MonsterPartKind::LeftNail },
            { L"poisonous-thorn", winrt::MonsterHunterWilds::MonsterPartKind::PoisonousThorn },
            { L"mantle", winrt::MonsterHunterWilds::MonsterPartKind::Mantle },
            { L"stomach", winrt::MonsterHunterWilds::MonsterPartKind::Stomach },
            { L"left-wing-legs", winrt::MonsterHunterWilds::MonsterPartKind::LeftWingLegs },
            { L"antennae", winrt::MonsterHunterWilds::MonsterPartKind::Antennae },
            { L"right-wing-legs", winrt::MonsterHunterWilds::MonsterPartKind::RightWingLeg },
            { L"back", winrt::MonsterHunterWilds::MonsterPartKind::Back },
            { L"right-wing-blade", winrt::MonsterHunterWilds::MonsterPartKind::RightWingBlade },
            { L"left-wing-blade", winrt::MonsterHunterWilds::MonsterPartKind::LeftWingBlade },
            { L"ass", winrt::MonsterHunterWilds::MonsterPartKind::Ass },
            { L"tongue", winrt::MonsterHunterWilds::MonsterPartKind::Tongue },
            { L"dorsal-fin", winrt::MonsterHunterWilds::MonsterPartKind::DorsalFin },
            { L"nose", winrt::MonsterHunterWilds::MonsterPartKind::Nose },
            { L"tail-tip", winrt::MonsterHunterWilds::MonsterPartKind::TailTip },
            { L"right-front-arm", winrt::MonsterHunterWilds::MonsterPartKind::RightFrontArm },
            { L"left-hind-arm", winrt::MonsterHunterWilds::MonsterPartKind::LeftHindArm },
            { L"left-side-arm", winrt::MonsterHunterWilds::MonsterPartKind::LeftSideArm },
            { L"umbrella", winrt::MonsterHunterWilds::MonsterPartKind::Umbrella },
            { L"mouth", winrt::MonsterHunterWilds::MonsterPartKind::Mouth },
            { L"tentacle", winrt::MonsterHunterWilds::MonsterPartKind::Tentacle },
            { L"right-side-arm", winrt::MonsterHunterWilds::MonsterPartKind::RightSideArm },
            { L"left-front-arm", winrt::MonsterHunterWilds::MonsterPartKind::LeftFrontArm },
            { L"right-hind-arm", winrt::MonsterHunterWilds::MonsterPartKind::RightHindArm },
            { L"waterfilm-tail", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmTail },
            { L"waterfilm-left-body", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmLeftBody },
            { L"waterfilm-left-front-leg", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmLeftFrontLeg },
            { L"waterfilm-right-head", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmRightHead },
            { L"waterfilm-right-front-leg",winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmRightFrontLeg },
            { L"waterfilm-right-tail", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmRightTail },
            { L"waterfilm-left-tail", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmLeftTail },
            { L"waterfilm-left-head", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmLeftHead },
            { L"waterfilm-right-body", winrt::MonsterHunterWilds::MonsterPartKind::WaterfilmRightBody },
            { L"frozen-bigcore-after", winrt::MonsterHunterWilds::MonsterPartKind::FrozenBigcoreAfter },
            { L"frozen-core-waist", winrt::MonsterHunterWilds::MonsterPartKind::FrozenCoreWaist },
            { L"frozen-bigcore-before", winrt::MonsterHunterWilds::MonsterPartKind::FrozenBigcoreBefore },
            { L"chest", winrt::MonsterHunterWilds::MonsterPartKind::Chest },
            { L"hind-legs", winrt::MonsterHunterWilds::MonsterPartKind::HindLegs },
            { L"front-legs", winrt::MonsterHunterWilds::MonsterPartKind::FrontLegs }
        };

        if (auto found{ monster_part_kind_map.find(str) };
            found != monster_part_kind_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::MonsterHunterWilds::KinsectEssence EnumMap::KinsectEssenceMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::KinsectEssence> const kinsect_essence_map{
            { L"white", winrt::MonsterHunterWilds::KinsectEssence::White },
            { L"orange", winrt::MonsterHunterWilds::KinsectEssence::Orange },
            { L"red", winrt::MonsterHunterWilds::KinsectEssence::Red },
            { L"green", winrt::MonsterHunterWilds::KinsectEssence::Green }
        };

        if (auto found{ kinsect_essence_map.find(str) };
            found != kinsect_essence_map.end())
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }

    winrt::Windows::Foundation::IReference<winrt::MonsterHunterWilds::KinsectEssence> EnumMap::TryKinsectEssenceMap(winrt::Windows::Data::Json::JsonObject const& json_object, hstring const& key)
    {
        if (json_object.HasKey(key))
        {
            if (auto named_value{ json_object.GetNamedValue(key) };
                named_value.ValueType() == winrt::Windows::Data::Json::JsonValueType::String)
            {
                return KinsectEssenceMap(named_value.GetString());
            }
        }

        return {};
    }

    winrt::MonsterHunterWilds::DamageKind EnumMap::DamageKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::DamageKind> const damage_kind_map{
            { L"severing", winrt::MonsterHunterWilds::DamageKind::Servering },
            { L"blunt",     winrt::MonsterHunterWilds::DamageKind::Blunt },
            { L"projectile",    winrt::MonsterHunterWilds::DamageKind::Projectile }
        };

        if (auto found{ damage_kind_map.find(str) };
            found != std::end(damage_kind_map))
        {
            return found->second;
        }

        throw winrt::hresult_invalid_argument{ std::format(L"Invalid argument: {}", str) };
    }
}
