#include "pch.h"
#include "MonsterSize.h"
#include "MonsterSize.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    winrt::MonsterHunterWilds::MonsterSize MonsterSize::Parse(winrt::Windows::Data::Json::JsonObject const& json_object)
    {
        return {
            json_object.GetNamedNumber(L"base"),
            json_object.GetNamedNumber(L"mini"),
            json_object.GetNamedNumber(L"silver"),
            json_object.GetNamedNumber(L"gold")
		};
    }

    MonsterSize::MonsterSize(double base, double mini, double silver, double gold)
		: base_{ base }, mini_{ mini }, silver_{ silver }, gold_{ gold }
    {
        
    }

    double MonsterSize::Base()
    {
		return base_;
    }

    double MonsterSize::Mini()
    {
        return mini_;
    }

    double MonsterSize::Siver()
    {
		return silver_;
    }

    double MonsterSize::Gold()
    {
		return gold_;
    }
}
