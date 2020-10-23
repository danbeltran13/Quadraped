#include "leg1Constants.h"
#include <SoftwareSerial.h>

SoftwareSerial quadSerial(2, 3); // RX, TX

int servoTime = 1000;


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


void moveGroup(int servo, int position){
  quadSerial.print("#");
  quadSerial.print(servo);
  quadSerial.print("P");
  quadSerial.print(position);


}

void setup() {
  // put your setup code here, to run once:
    // put your setup code here, to run once:
  Serial.begin(9600);
  quadSerial.begin(9600);
  move(shoulderPin,shoulderHomePw,servoTime);
  //move(thighPin,1979,servoTime);
  //move(kneePin,1230,servoTime);
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:

  int value1 =90;
  int value2 =0;
   
   value2 = map(value2, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);//Knee Convertion 
   value1 = map(value1, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); //thigh Convertion 
   //value = map(value, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw); //shoulder Convertion 
 
    
    moveGroup(kneePin, value2);
    moveGroup(thighPin,value1);
    quadSerial.print("T");
    quadSerial.println(servoTime);

    delay(1000);
//Other value
     value1 =0;
  value2 =90;
   
   value2 = map(value2, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);//Knee Convertion 
   value1 = map(value1, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); //thigh Convertion 
   //value = map(value, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw); //shoulder Convertion 
 
    
    moveGroup(kneePin, value2);
    moveGroup(thighPin,value1);
    quadSerial.print("T");
    quadSerial.println(servoTime);
    delay(1000);

}
