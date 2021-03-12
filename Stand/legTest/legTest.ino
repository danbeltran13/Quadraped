/* We will make the quadruped stand up on its own 4 legs
  The values included in the leg constants files may not me upto date since they are a copy from the values of the leg calibration test

  Servos on leg1 and leg2 are fliped,
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
int servoTime = 1500;

void moveStatement(int servo, int position)  {
  quadSerial.print("#");
  quadSerial.print(servo);
  quadSerial.print("P");
  quadSerial.print(position);

  Serial.print("#");
  Serial.print(servo);
  Serial.print("P");
  Serial.print(position);
}

// groupMove function moves all servos on a leg 
void groupMove(int legNumber, int shoulderAngle, int angleThigh, int angleKnee, int time) { 
  switch(legNumber){  
  case 1:
      moveStatement(frontRight.shoulderPin, frontRight.shoulderMove(shoulderAngle));
      moveStatement(frontRight.thighPin, frontRight.thighMove(angleThigh));
      moveStatement(frontRight.kneePin, frontRight.kneeMove(angleKnee));
      quadSerial.print("T");
      quadSerial.println(time);
      break;
  
    case 2:
      moveStatement(bottomRight.shoulderPin, bottomRight.shoulderMove(shoulderAngle));
      moveStatement(bottomRight.thighPin, bottomRight.thighMove(angleThigh));
      moveStatement(bottomRight.kneePin, bottomRight.kneeMove(angleKnee));
      quadSerial.print("T");
      quadSerial.println(time);
      break;
      
    case 3:
      moveStatement(bottomLeft.shoulderPin, bottomLeft.shoulderMove(shoulderAngle));
      moveStatement(bottomLeft.thighPin, bottomLeft.thighMove(angleThigh));
      moveStatement(bottomLeft.kneePin, bottomLeft.kneeMove(angleKnee));
      quadSerial.print("T");
      quadSerial.println(time);
      break;
      
    case 4:
      moveStatement(topLeft.shoulderPin, topLeft.shoulderMove(shoulderAngle));
      moveStatement(topLeft.thighPin, topLeft.thighMove(angleThigh));
      moveStatement(topLeft.kneePin, topLeft.kneeMove(angleKnee));
      quadSerial.print("T");
      quadSerial.println(time);
      break;
  }
  
}

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
  /*int leg1Shoulder = map(0, frontRight.shoulderRangeMinAngle, frontRight.shoulderRangeMaxAngle, frontRight.shoulderRangeMinPw, frontRight.shoulderRangeMaxPw);
    int leg1Thigh =  map(90, frontRight.thighRangeMinAngle, frontRight.thighRangeMaxAngle, frontRight.thighRangeMinPw, frontRight.thighRangeMaxPw);
    int leg1Knee = map(90, frontRight.kneeRangeMinAngle, frontRight.kneeRangeMaxAngle, frontRight.kneeRangeMinPw, frontRight.kneeRangeMaxPw);
  */

  // Leg 1
  groupMove(1, 0, 0, 0, servoTime);
  groupMove(2, 0, 0, 0, servoTime);
  groupMove(3, 0, 0, 0, servoTime);
  groupMove(4, 0, 0, 0, servoTime);
  delay(servoTime);
  groupMove(1, 90, 90, 90, servoTime);
  groupMove(2, 90, 90, 90, servoTime);
  groupMove(3, 90, 90, 90, servoTime);
  groupMove(4, 90, 90, 90, servoTime);
delay(servoTime);
    groupMove(1, 0, 0, 0, servoTime);
  groupMove(2, 0, 0, 0, servoTime);
  groupMove(3, 0, 0, 0, servoTime);
  groupMove(4, 0, 0, 0, servoTime);
delay(servoTime);
  groupMove(1, 90, 90, 90, servoTime);
  groupMove(2, 90, 90, 90, servoTime);
  groupMove(3, 90, 90, 90, servoTime);
  groupMove(4, 90, 90, 90, servoTime);
delay(servoTime);
    groupMove(1, 0, 0, 0, servoTime);
  groupMove(2, 0, 0, 0, servoTime);
  groupMove(3, 0, 0, 0, servoTime);
  groupMove(4, 0, 0, 0, servoTime);
delay(servoTime);
  groupMove(1, 90, 90, 90, servoTime);
  groupMove(2, 90, 90, 90, servoTime);
  groupMove(3, 90, 90, 90, servoTime);
  groupMove(4, 90, 90, 90, servoTime);

}
void loop() {
}
