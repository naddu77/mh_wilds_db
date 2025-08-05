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

    winrt::MonsterHunterWilds::WeaponKind EnumMap::WeaponKindMap(hstring const& str)
    {
        static std::unordered_map<winrt::hstring, winrt::MonsterHunterWilds::WeaponKind> const weapon_kind_map{
            { L"bow", winrt::MonsterHunterWilds::WeaponKind::Bow },
            { L"hunting-horn	", winrt::MonsterHunterWilds::WeaponKind::HuntingHorn },
            { L"charge-blade	", winrt::MonsterHunterWilds::WeaponKind::ChargeBlade },
            { L"insect-glaive", winrt::MonsterHunterWilds::WeaponKind::InsectGlaive },
            { L"dual-blades", winrt::MonsterHunterWilds::WeaponKind::DualBlades },
            { L"lance", winrt::MonsterHunterWilds::WeaponKind::Lance },
            { L"great-sword", winrt::MonsterHunterWilds::WeaponKind::Gunlance },
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
            { L"impact	", winrt::MonsterHunterWilds::ChargeBladePhial::Impact }
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
           { L"poison	", winrt::MonsterHunterWilds::SwitchAxePhial::Poison }
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
           { L"blue	", winrt::MonsterHunterWilds::HuntingHornNote::Blue },
           { L"aqua	", winrt::MonsterHunterWilds::HuntingHornNote::Aqua },
           { L"white	", winrt::MonsterHunterWilds::HuntingHornNote::White },
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
           { L"immunity	", winrt::MonsterHunterWilds::HuntingHornBubbleKind::Immunity }
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

}
