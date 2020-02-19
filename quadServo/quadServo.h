#ifndef QUADSERVO_H
#define QUADSERVO_H

#include "Arduino.h"

class quadServo{
	private: 
		int minAngle = 0;
		int maxAngle = 0;
		int minPw = 0;
		int maxPw = 0;
		int homeAngle = 0;
		int homePw = 0;
		int servoPin = 0;
		int currentAngle = 0;
		int currentPw= 0;
		
	
	
	
	public: 
		quadServo(int servoPin,int minA, int maxA, int minPw, int maxPw,int homeA,int homePw);
		const int getMinAngle();
		const int getMaxAngle();
		const int getMinPw();
		const int getMaxPw();
		int getCurrentAngle();
		int getCurrentPw();
		
		int convertAngleToPw(int angle);
		int convertPwToAngle(int pw);
		bool moveToAngle(int angle,int  time = 1000);
		bool moveToPw(int pw, int time = 1000);
		bool groupMoveToAngle(int angle);
		bool groupMoveToPw(int pw);
		bool home(int time = 1000);
		bool groupHome();
	
	

};

#endif