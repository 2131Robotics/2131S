int ComRumerFun(){
    Controller1.rumble(".");
    return 1;
}
bool CatapultSTS = false;
bool  CatapultSpinToControlEnabled =false;
int  CatapultPctSetting = 0;
int CatapultPosFromReleasedToCharged = 400;//right before Catapulting
bool R1Pressed = false;
bool CatapultCharged = false;
int CatapultDeg = 0;
int CatapultSpinToControlRunEnabled = false;
int CatapultPosFromChargedToReleased = 110;//right before slip tooth starts
void CatapultSMSPos(int Pct){
    if(Pct==0){
        CatapultMotor.stop();
        CatapultSTS=false;
    }
    else{
        CatapultSTS=true;
        CatapultMotor.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    }
}


void CatapultSpinTo(int Tar,bool SMS=true,bool Stop=true,bool Rel=false,int Pct=100,int Tal=10){
    if(Rel) Tar+=CatapultMotor.rotation(vex::rotationUnits::deg);
    // int Dir=SGN(Tar-CatapultMotor.rotation(vex::rotationUnits::deg));//only use if it can go both dir's
    int Dir=1;
    if(std::abs(CatapultMotor.rotation(vex::rotationUnits::deg)-Tar)>Tal && CatapultSpinToControlRunEnabled){//outside of tal
        CatapultSpinToControlEnabled=true;
        //Dir=SGN(Tar-CatapultMotor.rotation(vex::rotationUnits::deg));//only use if it can go both dir's
        CatapultPctSetting=Pct*Dir;//set the motor to spin in the correct direction
    }
    else if(CatapultSpinToControlEnabled){//if in tar zone and was enabled; fist not enabled
        CatapultPctSetting=0;
        CatapultSpinToControlEnabled=false;//toggle
        if(Stop)    CatapultSpinToControlRunEnabled=false;//stop after it has been hit
    }
    if(SMS) CatapultSMSPos(CatapultPctSetting);
}
void CatapultChargeControlPos(){
    if(Controller1.ButtonR1.pressing() && !R1Pressed){
        R1Pressed=true;
        vex::task CompRumerTask(ComRumerFun);
        if(!CatapultCharged){
            CatapultDeg+=CatapultPosFromReleasedToCharged;
            CatapultSpinToControlRunEnabled=true;//enable Catapultspinto
            CatapultCharged=true;
        }
        else if(CatapultCharged){//if charged && the CatapultPos is not spining
            CatapultDeg+=CatapultPosFromChargedToReleased;
            CatapultSpinToControlRunEnabled=true;//enable Catapultspinto
            CatapultCharged=false;
        }
    }
    else if(!Controller1.ButtonR1.pressing() && R1Pressed)  R1Pressed=false;

    CatapultSpinTo(CatapultDeg,true);//spin motor to CatapultDeg && set motor to spin
}
void CatapultControlPos(){
    CatapultChargeControlPos();
}