#include "animations.h"

bool isPulseRunning = true;
bool isSpecialActionPotentialRunning = false;

void runAnimations() {
    runBackground();
    
    if (isPulseRunning){
        runPulses();
    }

    if (isSpecialActionPotentialRunning) {
        runActionPotential();
    }

    // send the 'leds' array out to the actual LED strip
    FastLED.show();  
    // insert a delay to keep the framerate modest
    FastLED.delay(700); 
    // do some periodic updates

}

