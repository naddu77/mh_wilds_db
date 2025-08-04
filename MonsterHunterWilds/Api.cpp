#include "pch.h"
#include "Api.h"
#include "Api.g.cpp"

namespace winrt::MonsterHunterWilds::implementation
{
    Api::Api(hstring const& locale)
        : locale_{ locale }
    {
        
    }

    hstring Api::BaseUrl()
    {
        return base_url_;
    }

    hstring Api::Locale()
    {
        return locale_;
    }

    void Api::Locale(hstring const& value)
    {
        locale_ = value;
    }

    hstring Api::ArmorUrl()
    {
        return std::format(L"{}/{}/armor", base_url_, locale_).c_str();
    }

    hstring Api::ArmorSetsUrl()
    {
        return std::format(L"{}/{}/armor/sets", base_url_, locale_).c_str();
    }

    hstring Api::CharmsUrl()
    {
        return std::format(L"{}/{}/charms", base_url_, locale_).c_str();
    }

    hstring Api::DecorationsUrl()
    {
        return std::format(L"{}/{}/decorations", base_url_, locale_).c_str();
    }

    hstring Api::ItemsUrl()
    {
        return std::format(L"{}/{}/items", base_url_, locale_).c_str();
    }

    hstring Api::SkillsUrl()
    {
        return std::format(L"{}/{}/skills", base_url_, locale_).c_str();
    }

    hstring Api::WeaponsUrl()
    {
        return std::format(L"{}/{}/weapons", base_url_, locale_).c_str();
    }
}
