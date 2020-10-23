#include "leg1Constants.h"
#include <SoftwareSerial.h>

SoftwareSerial quadSerial(2, 3); // RX, TX



int servoTime = 1500;


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
  // put your setup code here, to run once:
  Serial.begin(9600);
  quadSerial.begin(9600);
  move(shoulderPin,shoulderHomePw,servoTime);
  //move(thighPin,1979,servoTime);
  move(kneePin,1230,servoTime);
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Serial.available() > 0) {

    char buffer[] = {' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Receive up to 7 bytes
    while (!Serial.available()); // Wait for characters
    Serial.readBytesUntil('\n', buffer, 7);
    int value = atoi(buffer);

    Serial.print("Angle READ: ");
    Serial.print(value);
    Serial.print(" Calculated PW: ");
    int value2 = value;
   //value = map(value, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);Knee Convertion 
   value = map(value2, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); //thigh Convertion 
   //value = map(value, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw); //shoulder Convertion 
    Serial.println(value);
    
    //move(shoulderPin, value, servoTime);
    move(thighPin, value, servoTime);
    
  

  }
  delay(1000);
  

}
