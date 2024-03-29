#include "animations.h"

#define MAX_NUM_OF_PULSES 40
#define DURATION_OF_PULSE 80 // 100 frames/second

// list of currently active pulses
// - frameNum - what frame each of them are on
// - blobID
// - brightness
struct pulse_t {
    uint8_t blobID;
    uint8_t brightness;
    uint16_t frameNumber;
    uint16_t delayFrameNumber;
    bool isFinished;
};

pulse_t pulses[MAX_NUM_OF_PULSES] = {};

uint8_t getIndexOfFirstAvailableFinishedPulse(){
    for(uint8_t i = 0; i < MAX_NUM_OF_PULSES; i++)
    {
        if (pulses[i].isFinished) {
            return i;
        }
    }
    // safety: if there's no room we overrite the first pulse
    return 0;
}

void createPulse(uint8_t blobID, uint8_t brightness, uint16_t delay) {
    uint8_t indexOfPulse = getIndexOfFirstAvailableFinishedPulse();

    pulses[indexOfPulse].blobID = blobID;
    pulses[indexOfPulse].brightness = brightness;
    pulses[indexOfPulse].frameNumber = 0;
    pulses[indexOfPulse].delayFrameNumber = delay;
    pulses[indexOfPulse].isFinished = false;
}

// addAPulse function that sets up a new pulse animation
void startPulsePair(uint8_t startBlobID, uint8_t endBlobID, uint8_t brightness, uint16_t delay) {
    // delay is milliseconds

    if (!isPulseRunning) {
        return;
    }
    
    createPulse(startBlobID, brightness, 0);
    createPulse(endBlobID, brightness, delay);
}

void runPulseAnimationFrame(pulse_t pulse){
    blob_t blob = getBlob(pulse.blobID);
    
    // fill leds of blob with a color
    // TODO: what color?
    fill_solid(blob.leds, blob.numPixels, CRGB(255,0,0));
}

void runPulses() {
    //loop through each pulse and animate a frame
    for(uint8_t i = 0; i < MAX_NUM_OF_PULSES; i++)
    {
        // if this pulse is done with its animation, skip it
        if (pulses[i].isFinished) {
            continue;
        }

        // if pulse is being delayed, count down delay
        if (pulses[i].delayFrameNumber > 0) {
            pulses[i].delayFrameNumber -= 1;
            continue;
        }

        // run animation
        runPulseAnimationFrame(pulses[i]);
        pulses[i].frameNumber += 1;

        // if pulse has reached its end, set it to done
        if (pulses[i].frameNumber >= DURATION_OF_PULSE) {
            pulses[i].isFinished = true;
        }
    }
}

void setupPulseList() {
    for(uint8_t i = 0; i < MAX_NUM_OF_PULSES; i++)
    {
        pulses[i].isFinished = true;
    }
}