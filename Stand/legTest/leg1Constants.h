
#include <SoftwareSerial.h>
class leg1 {

  public:
    //Shoulder
    const int shoulderPin = 1; // location on servo controller

    const int shoulderRangeMinPw = 1448;
    const int shoulderRangeMaxPw = 2100;
    const int shoulderRangeMinAngle = 90;
    const int shoulderRangeMaxAngle = 180 ;

    //Thigh
    const int thighPin = 2; // location on servo controller

    const int thighRangeMinPw = 649;
    const int thighRangeMaxPw = 1979;
    const int thighRangeMinAngle = 0;
    const int thighRangeMaxAngle = 180;

    //Knee
    const int kneePin = 3; // location on servo controller

    const int kneeRangeMinPw = 1230;
    const int kneeRangeMaxPw = 2492;
    const int kneeRangeMinAngle = 0;
    const int kneeRangeMaxAngle = 170;

    int shoulderMove (int angle){ // angle to PW value for shoulder 
      return map(angle, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw);
    }
    int thighMove (int angle){ // angle to PW value for thigh
      return map(180 - angle, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); // 180 - angle is used here for keeping angle 0 consistent with all legs
    }
    int kneeMove (int angle){ // angle to PW value for knee
      return map(angle, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);

    }
    //void moveserial(int servo, int position, int time, SoftwareSerial quadSerial);
      // 
    
    

};
