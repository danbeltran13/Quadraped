/* We will make the quadruped stand up on its own 4 legs
  The values included in the leg constants files may not me upto date since they are a copy from the values of the leg calibration test
*/

//To access the values, the legs are classes which have their specific value. This is because all the values have the same name across all 4 legs. Therefore it is easier to access them using a class
#include "leg1Constants.h"
#include "leg2Constants.h"
#include "leg3Constants.h"
#include "leg4Constants.h"
#include <SoftwareSerial.h> // This is the serial to talk to the lynxmotion servo controller

leg1 frontRight;
leg2 bottomRight;
leg3 bottomLeft;
leg4 topLeft;

//We will need a serial connection so that we can talk to the lynxmotion
SoftwareSerial quadSerial(2, 3); // RX, TX

// This is how long it will take for the servo to move to the angle you gave it
int servoTime = 3000;


// This function will move the servo to the angle given
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
  Serial.println("Connected");

  // To make the quad stand up, we will have the shoulder, thign, and knee servos of each leg move to angle 90, 45, 90
  // We must first convert each of those angles to a PW value that the lynxmotion understands

  
  // Convert all the angles to PW
  
  // leg 1
  // Must convert the angles to a PW value for each servo
  int leg1Shoulder = map(90, frontRight.shoulderRangeMinAngle, frontRight.shoulderRangeMaxAngle, frontRight.shoulderRangeMinPw, frontRight.shoulderRangeMaxPw);
  int leg1Thigh =  map(45, frontRight.thighRangeMinAngle, frontRight.thighRangeMaxAngle, frontRight.thighRangeMinPw, frontRight.thighRangeMaxPw);
  int leg1Knee = map(90, frontRight.kneeRangeMinAngle, frontRight.kneeRangeMaxAngle, frontRight.kneeRangeMinPw, frontRight.kneeRangeMaxPw);

  // Leg 2 
  int leg2Shoulder = map(90, bottomRight.shoulderRangeMinAngle, bottomRight.shoulderRangeMaxAngle, bottomRight.shoulderRangeMinPw, bottomRight.shoulderRangeMaxPw);
  int leg2Thigh =  map(45, bottomRight.thighRangeMinAngle, bottomRight.thighRangeMaxAngle, bottomRight.thighRangeMinPw, bottomRight.thighRangeMaxPw);
  int leg2Knee = map(90, bottomRight.kneeRangeMinAngle, bottomRight.kneeRangeMaxAngle, bottomRight.kneeRangeMinPw, bottomRight.kneeRangeMaxPw);

  // Leg 3 
  int leg3Shoulder = map(90, bottomLeft.shoulderRangeMinAngle, bottomLeft.shoulderRangeMaxAngle, bottomLeft.shoulderRangeMinPw, bottomLeft.shoulderRangeMaxPw);
  int leg3Thigh =  map(45, bottomLeft.thighRangeMinAngle, bottomLeft.thighRangeMaxAngle, bottomLeft.thighRangeMinPw, bottomLeft.thighRangeMaxPw);
  int leg3Knee = map(90, bottomLeft.kneeRangeMinAngle, bottomLeft.kneeRangeMaxAngle, bottomLeft.kneeRangeMinPw, bottomLeft.kneeRangeMaxPw);

  // Leg 4
  int leg3Shoulder = map(90, bottomLeft.shoulderRangeMinAngle, bottomLeft.shoulderRangeMaxAngle, bottomLeft.shoulderRangeMinPw, bottomLeft.shoulderRangeMaxPw);
  int leg3Thigh =  map(45, bottomLeft.thighRangeMinAngle, bottomLeft.thighRangeMaxAngle, bottomLeft.thighRangeMinPw, bottomLeft.thighRangeMaxPw);
  int leg3Knee = map(90, bottomLeft.kneeRangeMinAngle, bottomLeft.kneeRangeMaxAngle, bottomLeft.kneeRangeMinPw, bottomLeft.kneeRangeMaxPw);




}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}
