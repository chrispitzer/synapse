#include "animations.h"

#define MAX_NUM_OF_PULSES 20

// list of currently active pulses
// - frameNum - what frame each of them are on
// - blobID
// - brightness
struct active_pulse_t {
    uint8_t blobID;
    uint8_t brightness;
    uint16_t frameNumber;
};

// list of future pulses
// - same stuff as above but add in how many frames in the future it is
struct future_pulse_t {
    uint8_t blobID;
    uint8_t brightness;
    uint16_t delayFrameNumber;
};

active_pulse_t activePulses[MAX_NUM_OF_PULSES] = {};
future_pulse_t futurePulses[MAX_NUM_OF_PULSES] = {};
uint8_t numberOfActivePulses = 0;
uint8_t numberOfFuturePulses = 0;

void createActivePulse(uint8_t blobID, uint8_t brightness) {
    if (numberOfActivePulses == MAX_NUM_OF_PULSES) {
        return;
    } 

    activePulses[numberOfActivePulses].blobID = blobID;
    activePulses[numberOfActivePulses].brightness = brightness;
    activePulses[numberOfActivePulses].frameNumber = 0;

    // add 1 to this because we're adding one right now
    numberOfActivePulses++;
}

void createFuturePulse(uint8_t blobID, uint8_t brightness, uint16_t delay) {
    if (numberOfFuturePulses == MAX_NUM_OF_PULSES) {
        return;
    }

    futurePulses[numberOfFuturePulses].blobID = blobID;
    futurePulses[numberOfFuturePulses].brightness = brightness;
    futurePulses[numberOfFuturePulses].delayFrameNumber = delay;

    numberOfFuturePulses++;
}

// addAPulse function that sets up a new pulse animation
void startPulse(uint8_t startBlobID, uint8_t endBlobID, uint8_t brightness, uint16_t delay) {
    // delay is milliseconds
    createActivePulse(startBlobID, brightness);
    createFuturePulse(endBlobID, brightness, delay);
}

// this file runs one frame of each of the active pulses
void runPulse() {
    Serial.println("running PULSE");

}