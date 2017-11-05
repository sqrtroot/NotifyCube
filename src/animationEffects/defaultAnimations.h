#pragma once

#include "animation.h"
#include "steppedAnimation.h"

Animation fill([](size_t &stepCounter, RgbColor *buffer, size_t length) {
    buffer[stepCounter] = RgbColor(255);
    stepCounter++;
    return stepCounter == length - 1;
});

SteppedAnimation<2> blink({
                                  std::make_pair(std::make_pair(0, 1),
                                                 [](size_t &stepCounter, RgbColor *buffer, size_t length) {
                                                     for (size_t i = 0; i < length; i++) {
                                                         buffer[i] = RgbColor(255);
                                                     }
                                                 }),
                                  std::make_pair(std::make_pair(1, 2),
                                                 [](size_t &stepCounter, RgbColor *buffer, size_t length) {
                                                     for (size_t i = 0; i < length; i++) {
                                                         buffer[i] = RgbColor(0);
                                                     }
                                                 }),
                          });
