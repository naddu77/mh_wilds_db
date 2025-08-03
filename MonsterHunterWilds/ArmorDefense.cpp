#include "pch.h"
#include "ArmorDefense.h"
#include "ArmorDefense.g.cpp"


namespace winrt::MonsterHunterWilds::implementation
{
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
