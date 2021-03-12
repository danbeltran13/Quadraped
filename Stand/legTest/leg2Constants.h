

class leg2 {
  public:
    //Shoulder
    const int shoulderPin = 4;

    const int shoulderRangeMinPw = 930;
    const int shoulderRangeMaxPw = 2300;
    const int shoulderRangeMinAngle = 0;
    const int shoulderRangeMaxAngle = 180 ;

    //Thigh
    const int thighPin = 5;


    const int thighRangeMinPw = 660;
    const int thighRangeMaxPw = 2020;
    const int thighRangeMinAngle = 0;
    const int thighRangeMaxAngle = 180;

    //Knee
    const int kneePin = 6;

    const int kneeRangeMinPw = 934;
    const int kneeRangeMaxPw = 2239;
    const int kneeRangeMinAngle = 0;
    const int kneeRangeMaxAngle = 180;

    int shoulderMove (int angle){ // angle to PW value for shoulder 
      return map(angle, shoulderRangeMinAngle, shoulderRangeMaxAngle, shoulderRangeMinPw, shoulderRangeMaxPw);
    }
    int thighMove (int angle){ // angle to PW value for thigh
      return map(180 - angle, thighRangeMinAngle, thighRangeMaxAngle, thighRangeMinPw, thighRangeMaxPw); // 180 - angle is used here for keeping angle 0 consistent with all legs
    }
    int kneeMove (int angle){ // angle to PW value for knee
      return map(angle, kneeRangeMinAngle, kneeRangeMaxAngle, kneeRangeMinPw, kneeRangeMaxPw);

    }

};
