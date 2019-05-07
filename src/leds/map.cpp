#include "map.h"

uint8_t ORB_1 = 0;
uint8_t ORB_2 = 1;
uint8_t ORB_3 = 2;
uint8_t ORB_4 = 3;
uint8_t ORB_5 = 4;
uint8_t ORB_6 = 5;
uint8_t ORB_7 = 6;
uint8_t ORB_8 = 7;
uint8_t ORB_9 = 8;
uint8_t ORB_10 = 9;
uint8_t ORB_11 = 10;
uint8_t ORB_12 = 11;
uint8_t ORB_13 = 12;
uint8_t ORB_14 = 13;
uint8_t ORB_15 = 14;
uint8_t ORB_16 = 15;
uint8_t ORB_17 = 16;
uint8_t ORB_18 = 17;
uint8_t ORB_19 = 18;
uint8_t ORB_20 = 19;
uint8_t ORB_21 = 20;
uint8_t ORB_22 = 21;
uint8_t NUCLEUS_1 = 22;
uint8_t NUCLEUS_2 = 23;
uint8_t NUCLEUS_3 = 24;
uint8_t NUCLEUS_4 = 25;
uint8_t NUCLEUS_5 = 26;
uint8_t NUCLEUS_6 = 27;
uint8_t NUCLEUS_7 = 28;
uint8_t NUCLEUS_8 = 29;
uint8_t AXON_1 = 30;
uint8_t AXON_2 = 31;
uint8_t ALL_OF_STRIP_1 = 32;

blob_data_t blobData[50] { 
    // numPixels, offset, stripID
     {24, 0, 1}, //orb1
     {24, 24, 1}, //orb2
     {24, 48, 1}, //orb3
     {24, 72, 1}, //orb4
     {24, 96, 1}, //orb5
     {24, 120, 1}, //orb6
     {24, 144, 1}, //orb7
     {24, 168, 1}, //orb8
     {24, 9, 1}, //orb9
     {24, 10, 1}, //orb10
     {24, 11, 1}, //orb11
     {24, 12, 1}, //orb12
     {24, 13, 1}, //orb13
     {24, 14, 1}, //orb14
     {24, 15, 1}, //orb15
     {24, 16, 1}, //orb16
     {24, 17, 1}, //orb17
     {24, 18, 1}, //orb18
     {24, 19, 1}, //orb19
     {24, 20, 1}, //orb20
     {24, 21, 1}, //orb21
     {24, 22, 1}, //orb22
     {24, 23, 1}, //nucleus1
     {24, 24, 1}, //nucleus2
     {24, 25, 1}, //nucleus3
     {24, 26, 1}, //nucleus4
     {24, 27, 1}, //nucleus5
     {24, 28, 1}, //nucleus6
     {24, 29, 1}, //nucleus7
     {24, 30, 1}, //nucleus8
     {150, 31, 1}, //axon1
     {150, 32, 1}, //axon2
     {192, 0, 1} // all of strip 1
    };

// looks at the details of the blob data and creates a blob
blob_t getBlob(uint8_t blobName){
    
    // strip is a pointer to a CRGB
    // all pointers can be treated like arrays
    CRGB *strip;
    blob_data_t thisBlobData = blobData[blobName];

    blob_t blob;
    blob.numPixels = thisBlobData.numPixels;

    switch (blobData[blobName].stripID)
    {
        case 1:
            strip = leds1;
            break;

        case 2:
            strip = leds2;
            break;

        case 3:
            strip = leds3;
            break;

        case 4:
            strip = leds4;
            break;
        
        case 5:
            strip = leds5;
            break;
    }

    // Since strip is a pointer, we can just add a number to it and it will
    // reference the memory location that is offset the distance down from its original address
    blob.leds = strip + thisBlobData.offset;
    
    return blob;
}
