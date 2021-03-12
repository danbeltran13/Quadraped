
class leg3 {
  public:
    //Shoulder
    const int shoulderPin = 7;

    const int shoulderRangeMinPw = 930;
    const int shoulderRangeMaxPw = 2300;
    const int shoulderRangeMinAngle = 0;
    const int shoulderRangeMaxAngle = 180 ;
    //Thigh;
    const int thighPin = 8;


    const int thighRangeMinPw = 1051;
    const int thighRangeMaxPw = 2368;
    const int thighRangeMinAngle = 0;
    const int thighRangeMaxAngle = 180;

    //Knee
    const int kneePin = 9;

    const int kneeRangeMinPw = 862;
    const int kneeRangeMaxPw = 2130;
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
