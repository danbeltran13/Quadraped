
class leg4 {
  public:
    //Shoulder
    const int shoulderPin = 10;

    const int shoulderRangeMinPw = 588;
    const int shoulderRangeMaxPw = 1919;
    const int shoulderRangeMinAngle = 0;
    const int shoulderRangeMaxAngle = 180 ;
    //Thigh
    const int thighPin = 11;

    const int thighRangeMinPw = 788;
    const int thighRangeMaxPw = 2095;
    const int thighRangeMinAngle = 0;
    const int thighRangeMaxAngle = 180;

    //Knee
    const int kneePin = 12;

    const int kneeRangeMinPw = 925;
    const int kneeRangeMaxPw = 2228;
    const int kneeRangeMinAngle = 0;
    const int kneeRangeMaxAngle = 180;

    int shoulderMove (int angle){ // angle to PW value for shoulder 
      return map(angle, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw);
    }
    int thighMove (int angle){ // angle to PW value for thigh
      return map(angle, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw);  
    }
    int kneeMove (int angle){ // angle to PW value for knee
      return map(angle, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);

    }
};
