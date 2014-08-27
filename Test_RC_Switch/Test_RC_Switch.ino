#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {

  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(38); //10
  
}

void loop() {
  mySwitch.switchOn("10000", 5);
  

  // Wait a second
  delay(2000);
  
  // Switch off
  mySwitch.switchOff("10000", 5);
  
  
  // Wait another second
  delay(2000);
  
}
