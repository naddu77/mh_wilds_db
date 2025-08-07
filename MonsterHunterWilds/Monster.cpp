#include "pch.h"
#include "Monster.h"
#include "Monster.g.cpp"

import std;

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::Monster Monster::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"id"),
            winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"gameId"),
			winrt::MonsterHunterWilds::EnumMap::MonsterKindMap(json_object.GetNamedString(L"kind")),
			winrt::MonsterHunterWilds::EnumMap::SpeciesMap(json_object.GetNamedString(L"species")),
			json_object.GetNamedString(L"name"),
			winrt::MonsterHunterWilds::MonsterSize::Parse(json_object.GetNamedObject(L"size")),
			json_object.GetNamedString(L"description"),
			json_object.GetNamedString(L"features"),
			json_object.GetNamedString(L"tips"),
			winrt::MonsterHunterWilds::JsonParser::GetNamedInt32(json_object, L"baseHealth"),
			winrt::MonsterHunterWilds::Location::ParseJsonArray(json_object.GetNamedArray(L"locations")),
			winrt::MonsterHunterWilds::JsonParser::ParseMonsterResistances(json_object.GetNamedArray(L"resistances")),
			winrt::MonsterHunterWilds::JsonParser::ParseMonsterWeaknesses(json_object.GetNamedArray(L"weaknesses")),
			winrt::MonsterHunterWilds::MonsterReward::ParseJsonArray(json_object.GetNamedArray(L"rewards")),
			winrt::MonsterHunterWilds::MonsterPart::ParseJsonArray(json_object.GetNamedArray(L"parts"))
        };
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Monster> Monster::ParseJsonArray(winrt::Windows::Data::Json::JsonArray const& json_array)
    {
        return winrt::single_threaded_vector(
            json_array
            | std::views::transform([](winrt::Windows::Data::Json::IJsonValue const& value) {
                return winrt::MonsterHunterWilds::Monster::Parse(value.GetObject());
			})
			| std::ranges::to<std::vector>()
        );
    }

    Monster::Monster(int32_t id, int32_t game_id, winrt::MonsterHunterWilds::MonsterKind const& kind, winrt::MonsterHunterWilds::Species const& species, hstring const& name, winrt::MonsterHunterWilds::MonsterSize const& size, hstring const& description, hstring const& features, hstring const& tips, int32_t base_health, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> const& locations, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> const& resistances, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> const& weaknesses, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> const& rewards, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> const& parts)
        : id_{ id }
		, game_id_{ game_id }
		, kind_{ kind }
		, species_{ species }
		, name_{ name }
		, size_{ size }
		, description_{ description }
		, features_{ features }
		, tips_{ tips }
		, base_health_{ base_health }
		, locations_{ locations }
		, resistances_{ resistances }
		, weaknesses_{ weaknesses }
		, rewards_{ rewards }
        , parts_{ parts }
    {

	}

    int32_t Monster::Id()
    {
		return id_;
    }

    int32_t Monster::GameId()
    {
        return game_id_;
    }

    winrt::MonsterHunterWilds::MonsterKind Monster::Kind()
    {
        return kind_;
    }

    winrt::MonsterHunterWilds::Species Monster::Species()
    {
        return species_;
    }

    hstring Monster::Name()
    {
        return name_;
    }

    winrt::MonsterHunterWilds::MonsterSize Monster::Size()
    {
        return size_;
    }

    hstring Monster::Description()
    {
        return description_;
    }

    hstring Monster::Features()
    {
        return features_;
    }

    hstring Monster::Tips()
    {
        return tips_;
    }

    int32_t Monster::BaseHealth()
    {
        return base_health_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::Location> Monster::Locations()
    {
        return locations_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterResistance> Monster::Resistances()
    {
        return resistances_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterWeakness> Monster::Weaknesses()
    {
        return weaknesses_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterReward> Monster::Rewards()
    {
        return rewards_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::MonsterPart> Monster::Parts()
    {
        return parts_;
    }
}
