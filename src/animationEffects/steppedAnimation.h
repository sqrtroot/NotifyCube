#pragma once

#include "animation.h"
#include <cwchar>
#include <internal/RgbColor.h>

template<size_t T>
class SteppedAnimation : public Animation {
private:
    using range   = std::pair<size_t, size_t>;
    using func_t = void (*)(size_t&, RgbColor *, size_t);
    std::array <std::pair<range, func_t>, T> funcs;


public:
    SteppedAnimation(std::array <std::pair<range, func_t>, T> funcs) :
            Animation(),
            funcs(funcs) {}

    bool step(RgbColor *buffer, size_t length) override {
        for (auto i: funcs) {
            if (i.first.first >= stepCounter && i.first.second < stepCounter) {
                i.second(stepCounter, buffer, length);
                stepCounter++;
                return false;
            }
        }
        stepCounter++;
        return true;
    }
};


