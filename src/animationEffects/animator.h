#pragma once

#include <cwchar>
#include <internal/RgbColor.h>
#include "animation.h"


template<typename bus_t, size_t pixelCount>
class Animator {
    bus_t &bus;
    RgbColor pixels[pixelCount];
    Animation *currentAnimation;
public:
    explicit Animator(bus_t &bus) : bus(bus) {};

    void reset() {
        if (currentAnimation)
            currentAnimation->reset();
        for (size_t i = 0; i < pixelCount; i++) {
            pixels[i] = RgbColor(0);
        }
    }

    void setAnimation(Animation *animation) {
        reset();
        currentAnimation = animation;
        animation->reset();
    }

    void update() {
        if (currentAnimation) {
            if (currentAnimation->step(pixels, pixelCount)) {
                reset();
                currentAnimation = nullptr;
            }
            for (size_t i = 0; i < pixelCount; i++) {
                bus.SetPixelColor(i, pixels[i]);
            }
            bus.Show();
        }
    }

    bool animationPlaying() {
        return currentAnimation != nullptr;
    }
};

