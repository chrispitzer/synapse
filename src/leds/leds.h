#ifndef LEDS_H

    #define LEDS_H

    // these are my imports
    #include <Arduino.h>
    #define FASTLED_ALLOW_INTERRUPTS 0
    #include <FastLED.h>
    #include "map.h"

    // these are the functions inside of my file
    void ledSetup();

    // these are the data inside of my file
    extern CRGB leds1[];
    extern CRGB leds2[];
    extern CRGB leds3[];
    extern CRGB leds4[];
    extern CRGB leds5[];

#endif