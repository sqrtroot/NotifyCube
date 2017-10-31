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
Annimator annimator(strip);
Blink b<decltype(strip), 8>;

void setup() {
    strip.Begin();
    strip.Show();
    annimator.setAnnimation(&b, 100, b.stepL);
}


void loop() {
    annimator.update();
    if (!annimator.annimationRunning()) {
        annimator.setAnnimation(&b, 100, b.stepL);
    }
}


