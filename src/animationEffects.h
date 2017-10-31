#pragma once

#include <cwchar>
#include <functional>
#include <internal/RgbColor.h>
#include <NeoPixelBus.h>

class Annimation {
private:
    size_t currentStep;
public:
    const size_t stepCount;

    virtual void reset() = 0;
    virtual bool step() = 0;
};

template<typename bus_t>
class Annimator {
    Annimation *annimation;
    bus_t &bus;
    size_t stepTime;
    size_t nextStep;
public:
    explicit Annimator(bus_t &bus) : bus(bus) {};

    void setAnnimation(Annimation *annimation, size_t duration, size_t steps) {
        annimation->reset();
        annimation->step();
        stepTime = duration / steps;
        nextStep = millis() + stepTime;
    }

    void update() {
        if (millis() > nextStep && annimation) {
            nextStep += stepTime;
            if (!annimation->step()) {
                annimation = nullptr;
            }
        }
    }

    bool annimationRunning() {
        return annimation == nullptr;
    }
};


