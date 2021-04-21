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
      break;
  
    case 2:
      moveStatement(bottomRight.shoulderPin, bottomRight.shoulderMove(shoulderAngle));
      moveStatement(bottomRight.thighPin, bottomRight.thighMove(angleThigh));
      moveStatement(bottomRight.kneePin, bottomRight.kneeMove(angleKnee));
      break;
      
    case 3:
      moveStatement(bottomLeft.shoulderPin, bottomLeft.shoulderMove(shoulderAngle));
      moveStatement(bottomLeft.thighPin, bottomLeft.thighMove(angleThigh));
      moveStatement(bottomLeft.kneePin, bottomLeft.kneeMove(angleKnee));
      break;
      
    case 4:
      moveStatement(topLeft.shoulderPin, topLeft.shoulderMove(shoulderAngle));
      moveStatement(topLeft.thighPin, topLeft.thighMove(angleThigh));
      moveStatement(topLeft.kneePin, topLeft.kneeMove(angleKnee));
      
      break;
     
  }
   // Since we need to move multiple legs, the quad serial print statement needs to be removed in order to fill the serial with instructions from both legs;
    if (time >=  0){
      quadSerial.print("T");
      quadSerial.println(time);
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


void legwalkTest(int leg){ // walking motion for 1 leg 
  for (int i = 0; i < 4; i++){
    // groupMove(leg # , shoulder angle, thigh angle, knee angle, time)
    groupMove(leg, 90, 35 ,90, 250); // 
    delay (250);
    groupMove(leg, 90, 0, 0, 250); // 
    delay (250);
    groupMove(leg, 90, 35, 90, 250); // 
    delay (250);

  }
}

int delayS = 250;
void legWalkTest2(int leg){ // walking motion for 1 leg 
  for (int i = 0; i < 4; i++){
    // groupMove(leg # , shoulder angle, thigh angle, knee angle, time)

    // 3 motions 
    //  Extend Forward 
    groupMove(leg, 90, 80 ,110, delayS); //
    delay(250);
    
    // Extends Backwards
    groupMove(leg, 90, 10 ,130, delayS); // 
    delay(250);

    // Lifts Leg
    groupMove(leg, 90, 00 ,10, delayS); //
    delay(250);
    
  }
  groupMove(leg, 90, 35 ,90, delayS); // 
  delay(250);
}


void walkFunctionTest(int delayS){
   // A full walking cycle is, moveforward - movebackwards - lift leg
   int dontExecute = -10;
   // Move Thigh Back

   // Movement1  
   //  Legs 1 and 3 Extend Forward 
    groupMove(1, 90, 80 ,110, dontExecute); //
    groupMove(3, 90, 80 ,110, dontExecute); //

   // Legs 2  and 4 Move Backwards
    groupMove(2, 90, 40 ,130, dontExecute); // 
    groupMove(4, 90, 30 ,130, delayS); //   
    delay(delayS); 

   // Motion 2
    //  Legs 1 and 3 Extends Backwards
    groupMove(1, 90, 30 ,130, dontExecute); // 
   groupMove(3, 90, 30 ,130, dontExecute); //
    
    // Legs 2 and 4 are lifting legs
   groupMove(2, 90, 50 ,70, dontExecute); //
    groupMove(4, 90, 50 ,70, delayS); // 
    
   delay(delayS);

    // Motion 3
    // Legs 1 and 3 are lifting leg
    groupMove(1, 90, 50 ,70, dontExecute); //
    groupMove(3, 90, 50 ,70, dontExecute); //
   

    //  Legs 2 and 4 Extend Forward 
    groupMove(2, 90, 80 ,110, dontExecute); //
    groupMove(4, 90, 80 ,110, delayS); // 
    delay(delayS);
    
  //  Return Legs Home
 /* groupMove(1, 90, 45 ,120, dontExecute); // 
  groupMove(2, 90,  45 ,120, dontExecute); // 
  groupMove(3, 90,  45 ,120, dontExecute); // 
  groupMove(4, 90,  45 ,120, delayS); // 
  delay(delayS); */
  
  
}

void homePos(int delayS){
  int dontExecute = -10;
  groupMove(1, 95, 55 ,130, dontExecute); // 
  groupMove(2, 95,  55 ,130, dontExecute); // 
  groupMove(3, 95,  55 ,130, dontExecute); // 
  groupMove(4, 95,  55 ,130, delayS); // 
  delay(delayS); 
}
/*
void walkTest(){ // 
  legwalkTest(1); // the leg walk function will probably need to be rewritten to account for the delay within the function to group 2 diagonal legs together
  legwalkTest(3);
  delay (servoTime * 2); // a delay inbetween the diagonal leg movments
  legwalkTest(2);
  legwalkTest(4);
  
}

*/

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

  
  // Stand test  
   groupMove(1, 90, 45 ,120, servoTime);
   groupMove(2, 90, 45 ,120, servoTime);
   groupMove(3, 90, 45 ,120, servoTime);
   groupMove(4, 90, 45 ,120, servoTime);
   //legWalkTest2(1);

 
   for (int i = 0; i < 4; i++){
    walkFunctionTest(1000);
   }

   homePos(250);
    



}
void loop() {
}
