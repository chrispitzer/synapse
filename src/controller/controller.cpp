#include "controller.h"

// listen to the sonars
// keep track of which sonars have just been triggered (maybe a list?)
// generate sporadic pulses

// synapse event log



// synapses are just pairs of blobs and sonars
struct synapse_t {
    blob_t blob;
    //sonar_t sonar;
};

struct synapse_trigger_event_t {
    // what sensor was triggered
    // when was it triggered
};

void generateSporadicPulses() {
    // determine probability of a pulse
    int probabilityOfPulse = 100;

    // if this result is anything but 0, don't do anything
    if (rand() % probabilityOfPulse != 0) {
        return;
    }

    orb_nucleus_pair_t pair = getRandomOrbNucleusPair();

    startPulsePair(pair.blobID, pair.nucleusID, 100, pair.delayFrameNumber);
}

// look for new events
    // loop over the sensors
    // ask questions of the sensors
    // look for sensors that are changing their values

void runController() {
    generateSporadicPulses();
}