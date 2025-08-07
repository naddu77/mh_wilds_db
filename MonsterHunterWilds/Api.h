#pragma once
#include "Api.g.h"

namespace winrt::MonsterHunterWilds::implementation
{
    struct Api : ApiT<Api>
    {
        Api() = default;
        Api(hstring const& locale);

        hstring BaseUrl();
        hstring Locale();
        void Locale(hstring const& value);
        hstring ArmorUrl();
        hstring ArmorSetsUrl();
        hstring CharmsUrl();
        hstring DecorationsUrl();
        hstring ItemsUrl();
		hstring LocationsUrl();
		hstring MonstersUrl();
		hstring MotionValuesUrl();
        hstring SkillsUrl();
        hstring WeaponsUrl();

    private:
        winrt::hstring locale_{ L"ko" };
        winrt::hstring base_url_{ L"https://wilds.mhdb.io" };
    };
}

namespace winrt::MonsterHunterWilds::factory_implementation
{
    struct Api : ApiT<Api, implementation::Api>
    {
    };
}
