#include <Arduino.h>
#include "sonar/sonar.h"
#include "leds/leds.h"


void coreOneLoop() {
    ledLoop();
}

void coreZeroLoop() {
  readSensors();
}


void coreTask( void * pvParameters ) {
  while(true){
    coreZeroLoop();
  }
}


void setup() {
  Serial.begin(9600);

  ledSetup();
  sonarSetup();


  // This will run some stuff on core "0".
  xTaskCreatePinnedToCore(
    coreTask,   /* Function to implement the task */
    "coreTask", /* Name of the task */
    10000,      /* Stack size in words */
    NULL,       /* Task input parameter */
    0,          /* Priority of the task */
    NULL,       /* Task handle. */
    0);         /* Core where the task should run */

}


void loop() {
  coreOneLoop();
}
