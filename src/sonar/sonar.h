#ifndef SONAR_H

    #define SONAR_H

    // these are my imports
    #include <Arduino.h>

    // these are the functions inside of my sonar file
    void readSensors();
    void sonarSetup();

    // these are the data inside of my sonar file
    extern int distanceFromSonarA;

#endif