
const int Time=40;
//Shoulder
const int shoulderPin = 1;
const int shoulderHome = 1500;
const int shoulderTo = 1800;

//Thigh
const int thighPin = 2;
const int thighHome = 1500;
const int thighTo = 2100;

//Knee
const int kneePin = 3;
const int kneeHome = 1900;
const int kneeTo = 800;

void allHome(){
  move(shoulderPin,shoulderHome,Time);
  move(thighPin,thighHome,Time);
  move(kneePin,kneeHome,Time);
}

void allMove(){
  move(shoulderPin,shoulderTo,Time);
  move(thighPin,thighTo,Time);
  move(kneePin,kneeTo,Time);

}

void move(int servo, int position, int time) {
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
  Serial.println("Connected");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HOME");
  allHome();
  delay(3000);
  Serial.println("MOVE");
  allMove();
  delay(3000);
  

}
