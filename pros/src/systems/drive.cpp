#include "main.h"
#include "systems/config/vars.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/setup.hpp"
#include "systems/config/controller.hpp"
namespace Drive{
  void IsDriveFlippedControll(){

    if(DriveToggle.changed()){ // when the button changes
      if(DriveToggle.isPressed()){ //when it is pressed
        DriveDirInverted=!DriveDirInverted;
      }
      else{

      }
    }
    else if(DriveToggle.isPressed()){ //if your holding the button do this

    }
    else{ //default state

    }
  }
  void MechDriveLock(){
    front_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    back_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    front_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
    back_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);

    setMechDriveVel(0,0,0,0);
  }
  void MechDriveRelease(){
    front_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    back_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    front_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
    back_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::coast);
  }

  void ManualMechDriveCont(){
    int LeftVirtJoy=master_controller.getAnalog(okapi::ControllerAnalog::leftY)*200;
    int RightVirtJoy=master_controller.getAnalog(okapi::ControllerAnalog::rightY)*200;
    int LeftHorJoy=master_controller.getAnalog(okapi::ControllerAnalog::leftX)*200;
    int RightHorJoy=master_controller.getAnalog(okapi::ControllerAnalog::rightX)*200;



    if(std::abs(LeftVirtJoy)<5)    LeftVirtJoy=0;
    if(std::abs(RightVirtJoy)<5)    RightVirtJoy=0;
    if(std::abs(LeftHorJoy)<15)  LeftHorJoy=0;
    if(std::abs(RightHorJoy)<15)  RightHorJoy=0;

    if(LeftVirtJoy!=0 || RightVirtJoy!=0 || LeftHorJoy!=0 || RightHorJoy!=0){
      if(!DriveDirInverted){
        // vex::task AutoCat(AutoCatapult);
        DriveMechVelSend(LeftVirtJoy,RightVirtJoy,LeftHorJoy,RightHorJoy);
      }
      if(DriveDirInverted){
        DriveMechVelSend(-RightVirtJoy,-LeftVirtJoy,-RightHorJoy,-LeftHorJoy);
      }
    }
    else if(DriveDirInverted && Lift::BtnUp.isPressed() &&
    Lift::motor.get_position() > 420){
      setDriveVel(50,50);
    }
    else{
      setMechDriveVel(0,0,0,0);//Last loop before disableing; used to release drivemanualcontrol
    }
  }

  void DriveCont_LockContM(){


    if(HoldToggle.changed()){ // when the button changes
      if(HoldToggle.isPressed()){ //when it is pressed
        DriveLockInverted=!DriveLockInverted;
      }
      else{

      }
    }
    else if(HoldToggle.isPressed()){ //if your holding the button do this

    }
    else{ //default state

    }

    if(DriveLockInverted) MechDriveLock();
    else if(!DriveLockInverted) {
      MechDriveRelease();
      ManualMechDriveCont();
    }

  }
}
