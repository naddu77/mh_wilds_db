#include "pch.h"
#include "HuntingHornSong.h"
#include "HuntingHornSong.g.cpp"

#include "Util.h"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::HuntingHornSong HuntingHornSong::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"id")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"effectId")),
            ParseJsonArray(json_object.GetNamedArray(L"sequence"), [](auto const& json_value) { return winrt::MonsterHunterWilds::EnumMap::HuntingHornNoteMap(json_value.GetString()); }),
            json_object.GetNamedString(L"name")
        };
    }

    HuntingHornSong::HuntingHornSong(int32_t id, int32_t effect_id, winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> const& sequence, hstring const& name)
        : id_{ id }
        , effect_id_{ effect_id }
        , sequence_{ sequence }
        , name_{ name }
    {
        
    }

    int32_t HuntingHornSong::Id()
    {
        return id_;
    }

    int32_t HuntingHornSong::EffectId()
    {
        return effect_id_;
    }

    winrt::Windows::Foundation::Collections::IVector<winrt::MonsterHunterWilds::HuntingHornNote> HuntingHornSong::Sequence()
    {
        return sequence_;
    }

    hstring HuntingHornSong::Name()
    {
        return name_;
    }
}
