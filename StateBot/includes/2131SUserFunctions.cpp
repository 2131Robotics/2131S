//------Manual Drive Controll------------//
    void IsDriveFippedControll(){
        if(Controller1.ButtonX.pressing() && DriveDirConBtnPressed==false){
            DriveDirConBtnPressed=true;
            DriveDirInverted=!DriveDirInverted;
        }
        if(!Controller1.ButtonX.pressing() && DriveDirConBtnPressed==true){
            DriveDirConBtnPressed=false;
        }
    }
    void MechDriveLock(){
        DriveBrakeType = vex::brakeType::hold;
        setMechDrivePower(0,0,0,0);

    }
    void ManualMechDriveCont(){
        IsDriveFippedControll();
        int LeftVirtJoy=Controller1.Axis3.value();
        int RightVirtJoy=Controller1.Axis2.value();
        int LeftHorJoy=Controller1.Axis4.value();
        int RightHorJoy=Controller1.Axis1.value();

        if(std::abs(LeftVirtJoy)<10)    LeftVirtJoy=0;
        if(std::abs(RightVirtJoy)<10)    RightVirtJoy=0;
        if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
        if(std::abs(RightHorJoy)<15)  RightHorJoy=0;
        
        if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
            if(!DriveDirInverted){
                // vex::task AutoCat(AutoCatapult);
                DriveMechPowerSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
            }
            if(DriveDirInverted){
                DriveMechPowerSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
            }
        }
        else{
            setMechDrivePower(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
        }        
    }
        void PlaceCap(){
            vex::task AtonDrive(Drive_Ramping);
                AtonDriveRamp(40,60);
                vex::task::sleep(100);
                // liftRotateFor(-600,50);
                vex::task::sleep(300);
                DriveRampingEnabled = false;
        }

    void DriveCont_LockContM(){
        IsDriveFippedControll();
        if(Controller1.ButtonB.pressing() && DriveLockConBtnPressed==false){
            DriveLockConBtnPressed=true;
            DriveLockInverted=!DriveLockInverted;
        }
        if(!Controller1.ButtonB.pressing() && DriveLockConBtnPressed==true){
            DriveLockConBtnPressed=false;
        }

        if(DriveLockInverted) MechDriveLock();
        else if(!DriveLockInverted) {
            DriveBrakeType = vex::brakeType::coast;
            ManualMechDriveCont();
        }
        if(Controller1.ButtonDown.pressing()){ //place cap
            if(DriveDirInverted){
            setDrivePower(30,30);
            }
        }
    }
/**/
//------Manual Intake Controll------------//
    void intakeControll(){
        if(!DriveDirInverted){
            if(Controller1.ButtonL1.pressing()) {
                setIntakePower(100);
            }   
            else if(Controller1.ButtonL2.pressing()) {
                setIntakePower(-100);
            }   
            else IntakeMotor.stop(vex::brakeType::coast);
        }
        else{}
    }

    void AutoIntakeCont(){
        if(Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==false){
            IntakeEnabledBtnPressed=true;
            IntakeEnabledInverted=!IntakeEnabledInverted;
        }
        if(!Controller1.ButtonA.pressing() && IntakeEnabledBtnPressed==true){
            IntakeEnabledBtnPressed=false;
        }

        if(IntakeEnabledInverted){ 
            AutoIntakeTaskEnabled=false;
            intakeControll();
        }
        if(!IntakeEnabledInverted) {
            vex::task AutoIn(Auto_Intaking);
            //AutoIntakeEnabled=false;

        }
    }
/**/
//------Manual Catapult Controll------------//
    void catapultControll(){
        if(!DriveDirInverted && posControl) CatapultChargeControlPos();
        if(!DriveDirInverted && !posControl){
            if(Controller1.ButtonR1.pressing()) {
                setCatapultPower(100);
            }  
            else CatapultMotor.stop(CatapultBrakeType);
        }
    }
/**/