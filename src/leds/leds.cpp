#include "leds.h"


#define DATA_PIN 18 //signal pin 
#define NUM_LEDS 26 //number of LEDs in your strip
#define BRIGHTNESS 80  //brightness  (max 254) 
#define LED_TYPE WS2812  //
#define COLOR_ORDER BGR
#define FRAMES_PER_SECOND  120

CRGB leds1[NUM_LEDS]; //TODO: put actual number of LEDs in this strip
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void ledSetup() {

    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds1, NUM_LEDS);
    FastLED.setBrightness( BRIGHTNESS );
}

void ledLoop() {

    Serial.println("myBlob: ");
    blob_t myBlob = getBlob(ORB_5);
    Serial.print(myBlob.numPixels);

    // FastLED's built-in rainbow generator
    fill_rainbow( leds1, NUM_LEDS, gHue, 85);
    // send the 'leds' array out to the actual LED strip
    FastLED.show();  
    // insert a delay to keep the framerate modest
    FastLED.delay(700); 
    // do some periodic updates

    gHue+=85;  // slowly cycle the "base color" through the rainbow

}

void affectLeds() {
    fill_solid(leds1, NUM_LEDS, CRGB(0,220,125));
    FastLED.delay(100);
}
