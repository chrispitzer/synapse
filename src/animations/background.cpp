#include "animations.h"

uint8_t gHue = 0; // rotating "base color" used by many of the patterns


void runBackground() {
    Serial.println("running BACKGROUND");

    Serial.println("myBlob: ");
    blob_t myBlob = getBlob(ALL_OF_STRIP_1);
    Serial.print(myBlob.numPixels);

    gHue+=85;  // slowly cycle the "base color" through the rainbow

    // FastLED's built-in rainbow generator
    fill_rainbow( leds1, myBlob.numPixels, gHue, 85);
    

}