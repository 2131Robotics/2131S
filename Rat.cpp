int ComRumerFun(){
    Controller1.rumble(".");
    return 1;
}
bool PuncherSTS = false;
bool  PuncherSpinToControlEnabled =false;
int  PuncherPctSetting = 0;
int PunPosFromReleasedToCharged = 250;//right before punching
bool XPressed = false;
bool PuncherCharged = false;
int PuncherDeg = 0;
int PuncherSpinToControlRunEnabled = false;
int PunPosFromChargedToReleased = 110;//right before slip tooth starts
void PuncherSMSPos(int Pct){
    if(Pct==0){
        PuncherMotor.stop();
        PuncherSTS=false;
    }
    else{
        PuncherSTS=true;
        PuncherMotor.spin(vex::directionType::fwd,Pct,vex::velocityUnits::pct);
    }
}


void PuncherSpinTo(int Tar,bool SMS=true,bool Stop=true,bool Rel=false,int Pct=100,int Tal=10){
    if(Rel) Tar+=PuncherMotor.rotation(vex::rotationUnits::deg);
    // int Dir=SGN(Tar-PuncherMotor.rotation(vex::rotationUnits::deg));//only use if it can go both dir's
    int Dir=1;
    if(std::abs(PuncherMotor.rotation(vex::rotationUnits::deg)-Tar)>Tal && PuncherSpinToControlRunEnabled){//outside of tal
        PuncherSpinToControlEnabled=true;
        //Dir=SGN(Tar-PuncherMotor.rotation(vex::rotationUnits::deg));//only use if it can go both dir's
        PuncherPctSetting=Pct*Dir;//set the motor to spin in the correct direction
    }
    else if(PuncherSpinToControlEnabled){//if in tar zone and was enabled; fist not enabled
        PuncherPctSetting=0;
        PuncherSpinToControlEnabled=false;//toggle
        if(Stop)    PuncherSpinToControlRunEnabled=false;//stop after it has been hit
    }
    if(SMS) PuncherSMSPos(PuncherPctSetting);
}
void PuncherChargeControlPos(){
    if(Controller1.ButtonX.pressing() && !XPressed){
        XPressed=true;
        vex::task CompRumerTask(ComRumerFun);
        if(!PuncherCharged){
            PuncherDeg+=PunPosFromReleasedToCharged;
            PuncherSpinToControlRunEnabled=true;//enable puncherspinto
            PuncherCharged=true;
        }
        else if(PuncherCharged){//if charged && the puncherPos is not spining
            PuncherDeg+=PunPosFromChargedToReleased;
            PuncherSpinToControlRunEnabled=true;//enable puncherspinto
            PuncherCharged=false;
        }
    }
    else if(!Controller1.ButtonX.pressing() && XPressed)  XPressed=false;

    PuncherSpinTo(PuncherDeg,true);//spin motor to puncherDeg && set motor to spin
}
void PuncherControlPos(){
    PuncherChargeControlPos();
}