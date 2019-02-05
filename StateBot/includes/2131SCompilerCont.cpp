/*---------------------------------------------------------------------------*/
/*                              Pre Aton Control Task                        */
/*---------------------------------------------------------------------------*/
void PreAutonFun() {
    Brain.Screen.render(true,false);
    vex::task SmartPot(WhatAton);

        //wait for vex to not be a dumb
    while(MainAtonSelect.value(vex::percentUnits::pct)==0 && SecAtonSelect.value(vex::percentUnits::pct)==0){}
    LeftFMotor.setStopping(vex::brakeType::coast);
    LeftBMotor.setStopping(vex::brakeType::coast);
    RightFMotor.setStopping(vex::brakeType::coast);
    RightBMotor.setStopping(vex::brakeType::coast);
    
    LiftMotor.setStopping(vex::brakeType::brake);
    
    CatapultMotor.setStopping(vex::brakeType::coast);
    
    LiftMotor.resetRotation();
    LockMotor.resetRotation();
    CatapultMotor.resetRotation();
    LeftFMotor.resetRotation();
    LeftBMotor.resetRotation();
    RightFMotor.resetRotation();
    RightBMotor.resetRotation();
}

/*---------------------------------------------------------------------------*/
/*                              Aton Control Task                            */
/*---------------------------------------------------------------------------*/

void AtonFun() {
    vex::task AutoCat(AutoCatapult);
    vex::task AutoIn(Auto_Intaking);
    vex::task Debug(BrainScreenDebug);
    // AutoIntakeEnabled = false;

    vex::task AtonDrive(Drive_Ramping);

    LiftMotor.resetRotation();
    LockMotor.resetRotation();

<<<<<<< HEAD
    // LockRotateTo(-60)
    while(SecAtonSelect.value(vex::percentUnits::pct)== 100){}
    while(MainAtonSelect.value(vex::percentUnits::pct)==100) {}
    Brain.Screen.print("started");
    Brain.Screen.render();
=======
    // LockRotateTo(-60);
>>>>>>> e73abc0a58f4a554f7f297a46d7698daea578a26
    
    PotSelectors();
    //setDriveBrakeCoast();

}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

void UserContFun() {
<<<<<<< HEAD
    while(ChargeLightSensor.value(vex::percentUnits::pct)==0){}
    vex::task AutoCat(AutoCatapult);
    //vex::task AutoIn(Auto_Intaking);
=======

    vex::task AutoCat(AutoCatapult);
    vex::task AutoIn(Auto_Intaking);
>>>>>>> e73abc0a58f4a554f7f297a46d7698daea578a26

    // AutoIntakeEnabled = false;
    DriveRampingEnabled=false;
    MechDriveRampingEnabled=false;
            AutoIntakeOff = false;
    //vex::task Debug(BrainScreenDebug);

    while (true) {
        DriveCont_LockContM();
        AutoIntakeCont();
<<<<<<< HEAD
        //catapultControll();
        intakeControll();
=======
        //intakeControll();
        liftManualCont();
        LockJawCont();
        //catapultControll();
>>>>>>> e73abc0a58f4a554f7f297a46d7698daea578a26

        vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
    }
}
