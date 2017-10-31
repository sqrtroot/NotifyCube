// NeoPixelFunLoop
// This example will move a trail of light around a series of pixels.
// A ring formation of pixels looks best.
// The trail will have a slowly fading tail.
//
// This will demonstrate the use of the RotateRight method.
//

#include <NeoPixelBus.h>
#include "animationEffects.h"

const uint16_t PixelCount = 8; // make sure to set this to the number of pixels in your strip

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount);
Animator<decltype(strip), PixelCount> animator(strip);
Blink b;

void setup() {
    Serial.begin(9600);
    strip.Begin();
    strip.Show();
    animator.setAnimation(&b);
}


void loop() {
    if (!animator.animationPlaying()) {
        animator.setAnimation(&b);
    }
    animator.update();
    delay(10);
}


