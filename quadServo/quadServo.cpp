
#include "quadServo.h"	
#include "Arduino.h"
		
		
		
quadServo::quadServo(int servoPin,int minA, int maxA, int minPw, int maxPw,int homeA,int homePw){
	Serial.begin(9600);
	this ->servoPin = servoPin;
	this ->minAngle = minA;
	this ->maxAngle = maxA;
	this ->minPw = minPw;
	this ->maxPw = maxPw;
	this ->homeAngle = homeA;
	this ->homePw = homePw;
	
	
}
const int quadServo:: getMinAngle(){
	return this ->minAngle;
}
const int quadServo::getMaxAngle(){
	return this ->maxAngle;
}
const int quadServo::getMinPw(){
	return this ->minPw;
}
const int quadServo::getMaxPw(){
	return this ->maxPw;
}
int quadServo::getCurrentAngle(){
	return this -> currentAngle;
}
int quadServo::getCurrentPw(){
	return this ->currentPw;
}
		
int quadServo::convertAngleToPw(int angle){
	return map(angle,this->minAngle,this->maxAngle,this->minPw,this->maxPw);
}
int quadServo::convertPwToAngle(int pw){
	return map(pw,this->minPw,this->maxPw,this->minAngle,this->maxAngle);
}

bool quadServo::moveToAngle(int angle, int time ){
	
	if(minAngle <= angle && angle <= maxAngle){
		int pw = convertAngleToPw(angle);
		Serial.print('#');
		Serial.print(this->servoPin);
		Serial.print('P');
		Serial.print(pw);
		Serial.print('T');
		Serial.print(time);
		Serial.println();	
		this -> currentAngle = angle;
		this -> currentPw = pw;
		return true;
	}
	
	return false;
}
bool quadServo::moveToPw(int pw, int time){	
	if(minPw <=  pw && pw <= maxPw){
		int angle = convertPwToAngle(pw);
		Serial.print('#');
		Serial.print(this->servoPin);
		Serial.print('P');
		Serial.print(pw);
		Serial.print('T');
		Serial.print(time);
		Serial.println();	
		this -> currentAngle = angle;
		this -> currentPw = pw;
		return true;
	}
	
	return false;
	
}
bool quadServo::groupMoveToAngle(int angle){
		if(minAngle <= angle && angle <= maxAngle){
		int pw = convertAngleToPw(angle);
		Serial.print('#');
		Serial.print(this->servoPin);
		Serial.print('P');
		Serial.print(pw);
		this -> currentAngle = angle;
		this -> currentPw = pw;
		return true;
	}
	
	return false;
}

bool quadServo::groupMoveToPw(int pw){
		if(minPw <=  pw && pw <= maxPw){
		int angle = convertPwToAngle(pw);
		Serial.print('#');
		Serial.print(this->servoPin);
		Serial.print('P');
		Serial.print(pw);	
		this -> currentAngle = angle;
		this -> currentPw = pw;
		return true;
	}
	
	return false;
}
bool quadServo::home(int time){
	return moveToPw(this->homePw, time);
}
bool quadServo::groupHome(){
	return groupMoveToPw(this->homePw);
}