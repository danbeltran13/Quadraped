const int potPin= A0;
const int change= 10;
const int maxPw = 2500;
const int minPw = 500;
const int servoPin = 3;
const int timePos = 30;
int counter = 500;


/*# <ch> P <pw> S <spd> T <time> <cr> <- println()*/
// Moves servo with given arguments
void move(int servo, int position, int time) {
  Serial.print("#");
  Serial.print(servo);
  Serial.print(" P");
  Serial.print(position);
  Serial.print(" T");
  Serial.println(time);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(analogRead(potPin) > 700){
    if(counter <= minPw ){
      counter = minPw;
      
    }else{
        counter-=change;
    }
    move(3,counter,timePos);
  }if(analogRead(potPin) < 300){
    if(counter >= maxPw){
      counter = maxPw;
    
    }else{

    counter+=change;
    }
    move(3,counter,timePos);
  }
  Serial.println(counter);
  delay(300);
  
}
