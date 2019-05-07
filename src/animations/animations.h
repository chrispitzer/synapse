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

    // these are the data inside of my file
    extern bool isPulseRunning;

#endif