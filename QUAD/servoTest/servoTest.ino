/* This program is used to determine the range and center of a servo, this is basically just a test.
  Up and Down pad keys will be used */

// This is the library used to control the ps2 controller, must have this library installed
#include<PS2X_lib.h> 

//Creates a ps2 controller object
PS2X ps2;

//Helps identify that status of the connection between the controller and arduino
int error =0;
// identifies what controller it has found
byte type = 0;
// This is used to vibrate the controller 
byte vibrate = 0;
// Position tracks the location of the servo, its current value represent the center
int posServo = 1857;
// how much to change position
int incServo = 5;

// Motor pin location from the servo controller board
const int servoPin = 3;
// How long it will take to move to new location
int servoTime = 10;

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
  //Will use serial to communicate
  Serial.begin(9600);
  // setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  error = ps2.config_gamepad(8,9,10,11,true,true);

  // Checks the status of the controller using error bit, might take a few seconds
  // for controller to connect, make sure the controller is on before starting program
    if(error == 0)
  {
    Serial.println("Found Controller, configured successful");
  }
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
 // type variable is the controller type, should only need ps2 controller
  type = ps2.readType();
  switch(type)
  {
    case 0:
      Serial.println("Unknown Controller type");
      break;
      // This is the one we want
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
  }
  

}

void loop() {
    /* ORIGINAL COMMENT 
    You must Read Gamepad to get new values
    Read GamePad and set vibration values
    ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
    if you don't enable the rumble, use ps2x.read_gamepad(); with no values
    you should call this at least once a second
  */

  // Skip loop if no controller found, must restart program, reconnect arduino
  if(error == 1){
      Serial.println("No Controller Found, ending program");
      return;
  }

  // Here checks the status of the controller, for example, what is pressed
  // Must first check if the controller is a ps2 controller
  if(type == 1){
    //Sets the controller to vibrate at the set speed, 0 if at start
    ps2.read_gamepad(false,vibrate);

  // List of buttons: PSB_START, PSB_SELECT, PSB_PAD_UP, PSB_PAD_RIGHT, PSB_PAD_LEFT
  // PSB_PAD_DOWN, PSB_L3, PSB_R3, PSB_L2, PSB_R2, PSB_GREEN, PSB_RED, PSB_PINK
  // PSB_BLUE, PSB_L1, PSB_R1

  //Will check if up or down pad keys are being held down, changes the power variable accordingly 
  if(ps2.Button(PSB_PAD_UP)){
    Serial.print("Increasing position: ");
    Serial.println(posServo);
    //This is the increment 
    posServo += incServo;
    // Moves servo
    //move(servoPin,posServo,servoTime);
    
  }
  if(ps2.Button(PSB_PAD_DOWN)){
    Serial.print("Decreasing position: ");
    Serial.println(posServo);
    //This is the increment 
    posServo -= incServo;
    // Moves Servo
    //move(servoPin,posServo,servoTime);
  
  }

    Serial.print("Lx: ");
    Serial.print(ps2.Analog(PSS_LX));
    Serial.print(" ly: ");
    Serial.print(ps2.Analog(PSS_LY));
    Serial.print("Rx: ");
    Serial.print(ps2.Analog(PSS_RX));
    Serial.print(" Ry: ");
    Serial.println(ps2.Analog(PSS_RY));
    


    
  }
 
  // Adding a small delay to the loop
  delay(500);
}
