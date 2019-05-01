#include "sonar.h"

#define TRIGGER 0
#define ECHO    21
int distanceFromSonarA;

// This is where the code to read the sonar will go eventually
void readSensors() {
    long duration, distance;
    digitalWrite(TRIGGER, LOW);  
    delayMicroseconds(2); 
    
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10); 
    
    digitalWrite(TRIGGER, LOW);
    
    // pulsein watches for the pin to go from a low value to a high value, 
    // starts timing, and then stops when the values goes low again
    duration = pulseIn(ECHO, HIGH);
    distance = (duration/2) / 29.1;
    distanceFromSonarA = distance;
    
    Serial.print(distance);
    Serial.println(" cm");
    delay(20);
}



void sonarSetup() {
  
  Serial.begin (9600);
  // configure these specific pins as either inputs or outputs
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

