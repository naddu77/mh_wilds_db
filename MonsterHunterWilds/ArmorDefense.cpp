#include "pch.h"
#include "ArmorDefense.h"
#include "ArmorDefense.g.cpp"


namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::ArmorDefense ArmorDefense::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            static_cast<int32_t>(json_object.GetNamedNumber(L"base")),
            static_cast<int32_t>(json_object.GetNamedNumber(L"max"))
        };
    }

    ArmorDefense::ArmorDefense(int32_t base, int32_t max)
        : base_{ base }, max_{ max }
    {
	}

    int32_t ArmorDefense::Base()
    {
        return base_;
    }

    int32_t ArmorDefense::Max()
    {
        return max_;
    }
}
