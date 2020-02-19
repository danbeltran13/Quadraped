#include <quadServo.h>

//Map functions in library might break if bounds are not correct
 //(int servoPin,int minA, int maxA, int minPw, int maxPw,int homeA,int homePw)
 quadServo thighServo(1,0,180,1229,2484,1,1600);
 quadServo kneeServo(3,0,180,1229,2484,1,1600);
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connected");
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
  thighServo.groupHome();
  kneeServo.groupHome();
  Serial.println("T2500");
  delay(3000);

  thighServo.groupMoveToPw(2000);
  kneeServo.groupMoveToPw(2000);
  Serial.println("T2500");
  delay(3000);
  

}
