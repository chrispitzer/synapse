#ifndef ANIMATIONS_H

    #define ANIMATIONS_H

    // these are my imports
    #include <Arduino.h>
    #include "../leds/leds.h"

    // these are the functions inside of my file
    void runAnimations();
    void runBackground();
    void runActionPotential();
    void runPulses();
    void setupPulseList();
    void startPulsePair(uint8_t startBlobID, uint8_t endBlobID, uint8_t brightness, uint16_t delay);

    // these are the data inside of my file
    extern bool isPulseRunning;

#endif