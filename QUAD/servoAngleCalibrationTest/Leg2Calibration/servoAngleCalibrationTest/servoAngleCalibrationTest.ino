
//Leg 2 Calibration, Will use leg 1 calibration test as a template.
#include "leg2Constants.h"
#include <SoftwareSerial.h>

SoftwareSerial quadSerial(2, 3); // RX, TX


// This is how long it will take for the servo to move to the angle you gave it
int servoTime = 3000;


void move(int servo, int position, int time) {
  quadSerial.print("#");
  quadSerial.print(servo);
  quadSerial.print("P");
  quadSerial.print(position);
  quadSerial.print("T");
  quadSerial.println(time);
  
  
  Serial.print("#");
  Serial.print(servo);
  Serial.print("P");
  Serial.print(position);
  Serial.print("T");
  Serial.println(time);
}



void setup() {
  // Begin Serial Connections Here, 
  Serial.begin(9600);
  quadSerial.begin(9600); // quadSerial connects to the linxmotion, we use this so that we dont have to unplug rx and tx wires everytime

  // We call moves functions so that we can hold servos stable as we test a servo, Dont use unless servo has been calibrated
  move(shoulderPin,1615,servoTime);//90
  move(thighPin,2020,servoTime);//180
  //move(kneePin,1230,servoTime);
  Serial.println("Connected");
}

void loop() {
    // BE CAREFULL, THERE IS LIMIT TO WHAT ANGLE YOU CAN ENTER SINCE WE ARE CALIBRATING AND MAY REQUIRE AN ANGLE DIFFRENT FROM (0,180)

    // We can change the angle of a servo (0,180) based on the serial input
   if (Serial.available() > 0) {

    // Receive the input, and convert value to an int 
    char buffer[] = {' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Receive up to 7 bytes
    while (!Serial.available()); // Wait for characters
    Serial.readBytesUntil('\n', buffer, 7);
    int value = atoi(buffer);
    
    int convertedValue;
    //Convert the (0,180) value entered in serial to a PW value that is used by the lynxmotion 
    //ONLY USE THIS MAP FUNCTION ON THE SERVO YOU NEED TO CONVERT   
   convertedValue = map(value, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);//Knee Convertion 
   //convertedValue = map(value, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); //thigh Convertion 
   //convertedValue = map(value, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw); //shoulder Convertion 


    // Print The value
    Serial.print("Angle READ: ");
    Serial.print(value);
    Serial.print(" Calculated PW: ");
    Serial.println(convertedValue);
    
    
    // Move the servo you are testing
    //move(shoulderPin, convertedValue, servoTime);
   // move(thighPin, convertedValue, servoTime);
      move(kneePin, convertedValue, servoTime);
    
  

  }
  delay(1000);
  

}
