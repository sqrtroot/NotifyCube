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

    void setAnimation(Animation *animation) {
        currentAnimation = animation;
        animation->reset();
    }

    void update() {
        if (currentAnimation) {
            if (currentAnimation->step(pixels, pixelCount)) {
                currentAnimation = nullptr;
            }
            for (size_t i = 0; i < pixelCount; i++) {
                Serial.print("Drawing pixel ");
                Serial.print(i);
                Serial.print(" With values: ");
                Serial.print(pixels[i].R);
                Serial.print(',');
                Serial.print(pixels[i].G);
                Serial.print(',');
                Serial.print(pixels[i].B);
                Serial.println();
                bus.SetPixelColor(i, pixels[i]);
            }
            bus.Show();
        }
    }

    bool animationPlaying() {
        return currentAnimation != nullptr;
    }
};

