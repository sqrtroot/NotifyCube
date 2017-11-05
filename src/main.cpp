// NeoPixelFunLoop
// This example will move a trail of light around a series of pixels.
// A ring formation of pixels looks best.
// The trail will have a slowly fading tail.
//
// This will demonstrate the use of the RotateRight method.
//

#include <NeoPixelBus.h>

#include <animationEffects/animator.h>
#include <animationEffects/defaultAnimations.h>


const uint16_t PixelCount = 12; // make sure to set this to the number of pixels in your strip

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount);
Animator<decltype(strip), PixelCount> animator(strip);


void setup() {
    Serial.begin(9600);
    strip.Begin();
    strip.Show();
    animator.setAnimation(&fill);
}


void loop() {
    animator.update();
    delay(100);
}


