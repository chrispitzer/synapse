#include "sonar.h"

// sonar log length is the amount of readings a sonar will be working with
// keep this under 255
#define SONAR_LOG_LENGTH 100 
#define NUMBER_OF_SENSORS 5
#define TRIGGER_DISTANCE 30 //cm
#define UNTRIGGER_DISTANCE 50 //cm

struct sonar_t {
  uint8_t triggerPin;
  uint8_t echoPin;
  // uint16_t currentDistance; - this is just distanceLog[distanceLogCursor]
  uint16_t distanceLog[SONAR_LOG_LENGTH];
  uint8_t distanceLogCursor;
  bool isTriggered;
};

// name and position in sonars array
uint8_t SONAR_1 = 0;
uint8_t SONAR_2 = 1;
uint8_t SONAR_3 = 2;
uint8_t SONAR_4 = 3;
uint8_t SONAR_5 = 4;

sonar_t sonars[NUMBER_OF_SENSORS] {
  //trigger, echo, distanceLog, distanceLogCursor, isTriggered
  {23, 17, {}, 0, false},  // sonar 1
  {19, 16, {}, 0, false},  // sonar 2
  {18, 8, {}, 0, false},   // sonar 3
  {5, 7, {}, 0, false},    // sonar 4
  {4, 6, {}, 0, false}     // sonar 5
};

void logSonarReading(sonar_t sonar, uint16_t distance) {
  // add distance to the sonar's log array
  sonar.distanceLog[sonar.distanceLogCursor] = distance;

  // if cursor is at the end of the log, return it to the beginning
  if (sonar.distanceLogCursor >= SONAR_LOG_LENGTH) {
    sonar.distanceLogCursor = 0;
  } else { // else, advance the cursor position
    sonar.distanceLogCursor += 1;
  }
}

// note - not necessary?
void getChangeInDistance(sonar_t sonar, uint8_t numberOfReadings) {
  // this should give you the change in distance for a given sonar, but it's flexible
  // small number of readings = change in sonar just for the last moment
  // large number of readings = change over the last several seconds
}

//TODO: this is probably crap, I copied it from stack overflow
float getRunningAverage(sonar_t sonar) {
  // this looks at the last _x_ readings and give you the average of them
    uint16_t sum = 0;
    float avg = 0.0;  //or double for higher precision
    for (int i = 0; i < SONAR_LOG_LENGTH; ++i)
    {
        sum += sonars[i].distanceLog[sonars[i].distanceLogCursor];
    }
    
    avg = ((uint16_t)sum)/SONAR_LOG_LENGTH; //or cast sum to double before division
    return avg;
}

void triggerSonar(sonar_t sonar) {
  float avg = getRunningAverage(sonar);

    if (avg <= TRIGGER_DISTANCE) {
      // trigger sensor
      sonar.isTriggered = true;
      // add trigger event to sonar event log?
      // or should the controller keep track of this?
    }

    if (avg >= UNTRIGGER_DISTANCE) {
      // un-trigger sensor
      sonar.isTriggered = false;
    }
}


// assign trigger pin and echo pin modes for all sonars
void setupSonar() {
  for(uint8_t i = 0; i < NUMBER_OF_SENSORS; i++)
  {
    pinMode(sonars[i].triggerPin, OUTPUT);
    pinMode(sonars[i].echoPin, INPUT);
  } 
}

void runSonar() {
  // Note: this goes through each sonar one at a time. How to parallelize?
  // Maybe have two "for" statements?
  for(uint8_t i = 0; i < NUMBER_OF_SENSORS; i++)
  {
    uint16_t duration; 
    uint16_t distance;
    digitalWrite(sonars[i].triggerPin, LOW);  
    delayMicroseconds(2); 
    
    digitalWrite(sonars[i].triggerPin, HIGH);
    delayMicroseconds(10); 
    
    digitalWrite(sonars[i].triggerPin, LOW);
    
    // pulsein watches for the pin to go from a low value to a high value, 
    // starts timing, and then stops when the values goes low again
    duration = pulseIn(sonars[i].echoPin, HIGH);

    // converts reading to distance in centimeters
    distance = (duration/2) / 29.1;

    // add distance to the sonar's log
    logSonarReading(sonars[i], distance);

    // TODO: would this be the place to check the running average and 
    // change the state of the sonar?
    

    
  }
}