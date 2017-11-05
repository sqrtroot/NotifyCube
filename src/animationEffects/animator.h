#pragma once

#include <cwchar>
#include <internal/RgbColor.h>
#include <assert.h>
#include "animation.h"


template<typename bus_t, size_t pixelCount>
class Animator {
    bus_t &bus;
    RgbColor pixels[pixelCount];
    Animation *currentAnimation;
    size_t count = 0;
public:
    explicit Animator(bus_t &bus) : bus(bus) {};

    void reset() {
        if (currentAnimation) {
            currentAnimation->reset();
        }
        for (size_t i = 0; i < pixelCount; i++) {
            pixels[i] = RgbColor(0);
        }
    }

    void setAnimation(Animation *animation, size_t count) {
        assert(animation != nullptr);
        currentAnimation = animation;
        this->count = count;
        reset();
    }

    void update() {
        if (currentAnimation) {
            if (currentAnimation->step(pixels, pixelCount)) {
                if (--count > 0) {
                    reset();
                } else {
                    reset();
                    currentAnimation = nullptr;
                }
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

