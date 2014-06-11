/*
  Hobbytronics LCD Backpack RX Demo
  
  We use Software Serial so the program upload doesn't interfere with the LCD
 
  This example code is in the public domain.
 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

unsigned long currentTime;
unsigned long cloopTime;
unsigned long counter=0;
unsigned char pdelay=1;

// We can create up to 8 of our own characters to display
// Here we define 2 characters to be uploaded
byte ht_logo[8] = {
  B10100,
  B10100,
  B11111,
  B10110,
  B10110,
  B00010,
  B00010,
};
byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {

  // Need to give LCD and backpack time to initialise (Different LCD's vary)
  delay(800);   
   
  mySerial.begin(9600);
   
  // Set display 20x4  
  mySerial.write(5);
  mySerial.write(4);
  mySerial.write(20);
  mySerial.write(0xFF); 
  
  // Create HT character in position 0 (0 - 7)
  mySerial.write(64);
  mySerial.write((byte) 0);
  for (int i=0; i<8; i++) {
    mySerial.write((byte) ht_logo[i]);
  } 
  mySerial.write(0xFF); 
  
  // Create Smiley character in position 1 (0 - 7)
  mySerial.write(64);
  mySerial.write((byte) 1);
  for (int i=0; i<8; i++) {
    mySerial.write((byte) smiley[i]);
  } 
  mySerial.write(0xFF);   
  
  // Clear Display  
  mySerial.write(4);
  mySerial.write(0xFF);   
  
  // Set backlight on bright
  mySerial.write(7);
  mySerial.write(250);  
  mySerial.write(0xFF);   
  
  // Print single character - HT Character
  mySerial.write(10);
  mySerial.write((byte) 0);
  mySerial.write(0xFF);  
  
  // Print Hello
  mySerial.write(1);
  mySerial.print(" Hello ");
  mySerial.write(0xFF);  
  
  // Print single character - Smiley Character
  mySerial.write(10);
  mySerial.write((byte) 1);
  mySerial.write(0xFF); 
  
  // Move to line 2 column 1
  mySerial.write(2);
  mySerial.write(2);
  mySerial.write(1);  
  mySerial.write(0xFF); 
 
  // Print Hobbytronics
  mySerial.write(1);
  mySerial.print("Hobbytronics");  
  mySerial.write(0xFF);   
  
  currentTime = millis();
  cloopTime = currentTime;   
}

void loop() {
  
   currentTime = millis();
    
   if(currentTime >= (cloopTime + 1000)){   
   
      // Move to line 1 column 10
      mySerial.write(2);
      mySerial.write(1);
      mySerial.write(10);  
      mySerial.write(0xFF);   
   
      // Create right justified counter text
      char ascii[32];
      sprintf(ascii,"%7.0d",counter);
      
      mySerial.write(1);
      mySerial.print(ascii);     
      mySerial.write(0xFF);      

      counter++; 
      cloopTime = currentTime;  // Updates cloopTime
   }         
}
