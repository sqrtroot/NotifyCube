#include "animationEffects.h"


bool Blink::step(RgbColor *pixels, size_t pixelCount) {
    switch (stepCounter++) {
        case 0:
            for (size_t i = 0; i < pixelCount; i++) {
                pixels[i] = RgbColor(255);
            }
            return false;
        case 1:
            for (size_t i = 0; i < pixelCount; i++) {
                pixels[i] = RgbColor(0);
            }
            return true;
        default:
            return true;
    }

}

