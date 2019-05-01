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

void ledSetup() {

    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds1, NUM_LEDS);
    FastLED.setBrightness( BRIGHTNESS );
}

