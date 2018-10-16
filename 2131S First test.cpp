bool WristMotorConBtnPressed;
bool WristMotorInverted;

bool liftButtonWait;
int liftMode = 1;
int liftUserCpower = 100;

    vex::task DriveContRampTask(DriveContRamp);

LDR.RequestedPct = Controller1.Axis3.value();
            RDR.RequestedPct = Controller1.Axis2.value();  

class Ramping{
    public:
    int ChangePct=1;      //the amout of Pct change per loop
    int ChangeMsec=1;     //the amount of time inbetween loops

    int RequestedPct=0;   //used to request Pct value change
    int Pct=0;            //Pct output
    int MinUpPct=0;         //Used as moveing up StillSpeed
    int MinDownPct=0;       //Used as moving down StillSpeed
    int MaxPct=100;         //the max pct value

    Ramping();

    Ramping(int CP,int CM,int MaxP=100,int MinDP=0,int MinUP=0){
        //ChangePct,ChangeMsec,MaxPct
        ChangePct=CP;
        ChangeMsec=CM;
        MaxPct=MaxP;
        MinUpPct=MinUP;
        MinDownPct=MinDP;
    }

    void TaskRun(){
        if(RequestedPct>Pct){
            Pct=Pct+ChangePct;
        }
        else if(RequestedPct<Pct){
            Pct=Pct-ChangePct;
        }
        //limit Pct
        if(Pct>MaxPct)	Pct=MaxPct;
        if(Pct<-MaxPct)	Pct=-MaxPct;
        if(Pct>0 && Pct<MinUpPct) Pct=MinUpPct;
        if(Pct<0 && Pct>MinDownPct)    Pct=MinDownPct;
    }
};

void LMotorPowers(int rpm){
    //LeftFMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
    LeftBMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
}

void RMotorPowers(int rpm){
    // RightFMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
    RightBMotor.spin(vex::directionType::fwd,rpm, vex::velocityUnits::pct);
}

void DriveCont(int left, int right){
    LMotorPowers(left);
    RMotorPowers(right);
}

Ramping LDR(1,3);
Ramping RDR(1,3);

int DriveContRamp(){
    while(1){
        LDR.TaskRun();
        RDR.TaskRun();
        DriveCont(LDR.Pct, RDR.Pct);
        vex::task::sleep(RDR.ChangeMsec);
    }
}

void liftControll(){
    //Lift Control
    /*  if(Controller1.ButtonL1.pressing()) {
            LiftMotor.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        }   
        else if(Controller1.ButtonL2.pressing()) {
            LiftMotor.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        }   
        else LiftMotor.stop(vex::brakeType::hold);*/
    //----------------------Lift Controll------------------------//
    if(liftMode > 5)
        liftMode = 5;
    if(liftMode < 1)
        liftMode = 1;

    if(Controller1.ButtonL1.pressing() == false && Controller1.ButtonL2.pressing() == false)
        liftButtonWait=true;
    if(Controller1.ButtonL1.pressing() && liftButtonWait == true && liftMode <= 5){
        liftButtonWait=false;
        liftMode++;
    }

    if(Controller1.ButtonL2.pressing() && liftButtonWait == true && liftMode >= 1){
        liftButtonWait=false;
        liftMode--;
    }

    if(liftMode == 1)
        LiftMotor.rotateTo(0,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 2)
        LiftMotor.rotateTo(145,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 3)
        LiftMotor.rotateTo(400,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 4)
        LiftMotor.rotateTo(530,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
    if(liftMode == 5)
        LiftMotor.rotateTo(680,vex::rotationUnits::deg,liftUserCpower,vex::velocityUnits::pct);
}

void wirstControll(){
    if(Controller1.ButtonA.pressing() && WristMotorConBtnPressed==false){
        WristMotorConBtnPressed=true;
        WristMotor.startRotateFor(WristMotorInverted ? 180 : -180,vex::rotationUnits::deg,100,vex::velocityUnits::pct);
        WristMotorInverted=!WristMotorInverted;
    }
    if(!Controller1.ButtonA.pressing() && WristMotorConBtnPressed==true){
        WristMotorConBtnPressed=false;
    }
}

//pre
Brain.Screen.print("Setting Up...");
    //Controller1.Screen.print("Hi Trent! Initializing...");

    WristMotor.resetRotation();
    WristMotor.setStopping(vex::brakeType::brake);
    WristMotor.setTimeout(250,vex::timeUnits::msec);
    //LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    //RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    LiftMotor.setStopping(vex::brakeType::brake);
    PuncherMotor.setStopping(vex::brakeType::coast);
    IntakeMotor.setStopping(vex::brakeType::brake);

    LiftMotor.resetRotation();