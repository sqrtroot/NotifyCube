//
// Created by Robert on 5-11-2017.
//

#include "animation.h"

bool Animation::step(RgbColor *buffer, size_t length) {
    return func(stepCounter, buffer, length);
}

void Animation::reset() {
    stepCounter = 0;
}
