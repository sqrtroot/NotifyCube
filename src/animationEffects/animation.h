//
// Created by Robert on 5-11-2017.
//
#pragma once

#include <cwchar>
#include <internal/RgbColor.h>

class Animation {
protected:
    size_t stepCounter = 0;
    /**
     * Type for step function
     * @arg step size
     * @arg color buffer
     * @arg buffer length
     * @return true if there is no animation left
     */
    using func_t = bool (*)(size_t&, RgbColor *, size_t);
    const func_t func = nullptr;

    Animation() = default;

public:
    explicit Animation(func_t func) : func(func) {}

    virtual bool step(RgbColor *buffer, size_t length);;

    void reset();

};

