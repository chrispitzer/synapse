#ifndef MAP_H

    #define MAP_H

    // these are my imports
    #include <Arduino.h>
    #include "leds.h"

    // these are my structs

    // this is the data describing where a blob is located in an led strip
    struct blob_data_t {
        uint16_t numPixels;
        uint16_t offset;
        uint16_t stripID;
    };

    // this is the blob structure itself
    struct blob_t {
        uint16_t numPixels;
        CRGB *leds;
    };



    // these are the data inside of my file
    extern uint8_t ORB_1;
    extern uint8_t ORB_2;
    extern uint8_t ORB_3;
    extern uint8_t ORB_4;
    extern uint8_t ORB_5;
    extern uint8_t ORB_6;
    extern uint8_t ORB_7;
    extern uint8_t ORB_8;
    extern uint8_t ORB_9;
    extern uint8_t ORB_10;
    extern uint8_t ORB_11;
    extern uint8_t ORB_12;
    extern uint8_t ORB_13;
    extern uint8_t ORB_14;
    extern uint8_t ORB_15;
    extern uint8_t ORB_16;
    extern uint8_t ORB_17;
    extern uint8_t ORB_18;
    extern uint8_t ORB_19;
    extern uint8_t ORB_20;
    extern uint8_t ORB_21;
    extern uint8_t ORB_22;
    extern uint8_t NUCLEUS_1;
    extern uint8_t NUCLEUS_2;
    extern uint8_t NUCLEUS_3;
    extern uint8_t NUCLEUS_4;
    extern uint8_t NUCLEUS_5;
    extern uint8_t NUCLEUS_6;
    extern uint8_t NUCLEUS_7;
    extern uint8_t NUCLEUS_8;
    extern uint8_t AXON_1;
    extern uint8_t AXON_2;
    extern uint8_t ALL_OF_STRIP_1;

    extern blob_data_t blobData[];

    // these are the functions inside of my file
    blob_t getBlob(uint8_t);




#endif