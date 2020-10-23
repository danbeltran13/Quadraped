#include <SoftwareSerial.h>

SoftwareSerial quadSerial(2, 3); // RX, TX
//Once Servo is calibrated run this program to test the range,UPDATE VALUES FOR SERVO
/*
   Shoulder
  const int servoPin = 1;
  const int servoHome = 1500;
  const int servoMin = 980;
  const int servoMax = 2100;
  const int servoDelay = 100;
*/

//knee
const int servoPin = 3;
const int servoHome = 1900;
const int servoMin = 1300;
const int servoMax = 2500;
const int servoDelay = 100;


//1200
const int minPw = 1300;
const int maxPw = 2500;
const int minAngle=0;
const int maxAngle = 180;


int servoTime = 30;
int servoPw = servoHome;

void move(int servo, int position, int time) {
  quadSerial.print("#");
  quadSerial.print(servo);
  quadSerial.print("P");
  quadSerial.print(position);
  quadSerial.print("T");
  quadSerial.println(time);
}

void setup() {
  quadSerial.begin(9600);
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Connected");
  //move(servoPin,servoHome,servoTime);

}

void loop() {
  /*
    move(2,680,servoTime);
    // put your main code here, to run repeatedly:
    while(servoPw < servoMax){
      move(servoPin,servoPw,servoTime);
      servoPw += 100;
      delay(servoDelay);
    }
    servoPw = servoMax;
    delay(3000);

    while(servoPw > servoMin){
      move(servoPin,servoPw,servoTime);
      servoPw-= 100;
      delay(servoDelay);
    }
    delay(3000);
    servoPw = servoMin;

  */

  /*
    move(servoPin,servoMin,servoTime);
    delay(3000);
    move(servoPin,servoMax,servoTime);
    delay(3000);
  */

  if (Serial.available() > 0) {

    char buffer[] = {' ', ' ', ' ', ' ', ' ', ' ', ' '}; // Receive up to 7 bytes
    while (!Serial.available()); // Wait for characters
    Serial.readBytesUntil('\n', buffer, 7);
    int value = atoi(buffer);

    Serial.print("Angle READ: ");
    Serial.print(value);
    Serial.print(" Calculated PW: ");
    value = map(value, minAngle, maxAngle, minPw, maxPw);
    Serial.println(value);
    move(servoPin, value, servoTime);

  }
  delay(1000);

}
