#include "main.h"
#include "systems/ramping.hpp"
#include "systems/drive.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/setup.hpp"

//------Manual Drive Controll------------//
namespace Drive{
  //------------Aton Drive Ramping---------------------//
  //A stands for aton.
  void ADrive(double Distance,int Pct,int EndWait,int Correction){
    //update ramping speed
    LFDR.ChangeMsec = 4;
    RFDR.ChangeMsec = 4;
    LBDR.ChangeMsec = 4;
    RBDR.ChangeMsec = 4;

    double Direction=sgn(Distance);
    int LFPowerSend=0;
    int LBPowerSend=0;
    int RFPowerSend=0;
    int RBPowerSend=0;
    //clear enc
    front_left_motor.tarePosition();
    back_left_motor.tarePosition();
    back_right_motor.tarePosition();
    front_right_motor.tarePosition();
    //is it there yet?
    while(std::abs(back_right_motor.getPosition())<std::abs(Distance)){
      double LEncValue=front_left_motor.getPosition();
      double REncValue=front_right_motor.getPosition();
      //straiten
      if(std::abs(LEncValue)>std::abs(REncValue)){
        LFPowerSend=Pct-Correction;
        LBPowerSend=Pct-Correction;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      else if(std::abs(LEncValue)<std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct-Correction;
        RBPowerSend=Pct-Correction;
      }
      else if(std::abs(LEncValue)==std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      //correct direction
      LFPowerSend=LFPowerSend*Direction;
      LBPowerSend=LBPowerSend*Direction;
      RFPowerSend=RFPowerSend*Direction;
      RBPowerSend=RBPowerSend*Direction;
      //send to SetDRpower
      SetDRMvel(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
      pros::delay(LFDR.ChangeMsec);
    }
    SetDRMvel(0,0,0,0);
    pros::delay(EndWait);
    front_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    back_left_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    front_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    back_right_motor.setBrakeMode(okapi::AbstractMotor::brakeMode::brake);
    pros::delay(EndWait);
    // MechDriveRelease();
  }

  void TimeDrive(int time, int power){
    back_left_motor.tarePosition();
    back_right_motor.tarePosition();
    front_left_motor.tarePosition();
    front_right_motor.tarePosition();

    DI(power,power);
    pros::delay(time);
    DI(0,0);
    while(LBDR.Pct!=0 || RBDR.Pct!=0){
      pros::delay(1);
    }
  }

  void ASlide(double Distance,int Pct,int EndWait,int Correction){
    //update ramping speed
    LFDR.ChangeMsec = 3;
    RFDR.ChangeMsec = 3;
    LBDR.ChangeMsec = 3;
    RBDR.ChangeMsec = 3;
    //calculate direction and set L & R PowerSend
    double Direction=sgn(Distance);
    int LFPowerSend=0;
    int LBPowerSend=0;
    int RFPowerSend=0;
    int RBPowerSend=0;
    //clear enc
    front_left_motor.tarePosition();
    back_left_motor.tarePosition();
    back_right_motor.tarePosition();
    front_right_motor.tarePosition();
    //is it there yet?
    while(std::abs(back_right_motor.getPosition())<std::abs(Distance)){
      double LEncValue=front_left_motor.getPosition();
      double REncValue=back_right_motor.getPosition();
      //straiten
      if(std::abs(LEncValue)>std::abs(REncValue)){
        LFPowerSend=Pct-Correction;
        LBPowerSend=Pct-Correction;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      else if(std::abs(LEncValue)<std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct-Correction;
        RBPowerSend=Pct-Correction;
      }
      else if(std::abs(LEncValue)==std::abs(REncValue)){
        LFPowerSend=Pct;
        LBPowerSend=Pct;
        RFPowerSend=Pct;
        RBPowerSend=Pct;
      }
      //correct direction
      if(Direction == 1){
        LFPowerSend=LFPowerSend;
        LBPowerSend=LBPowerSend*(-1);
        RFPowerSend=RFPowerSend*(-1);
        RBPowerSend=RBPowerSend;
      }
      if(Direction == -1){
        LFPowerSend=LFPowerSend*(-1);
        LBPowerSend=LBPowerSend;
        RFPowerSend=RFPowerSend;
        RBPowerSend=RBPowerSend*(-1);
      }
      //send to SetDRpower
      SetDRMvel(LFPowerSend,LBPowerSend,RFPowerSend,RBPowerSend);
      pros::delay(LBDR.ChangeMsec);
    }
    SetDRMvel(0,0,0,0);
    pros::delay(EndWait);
  }

  void SlideRecon(int time, int power, int dir){
    MechDriveRampingEnabled=false;
    setMechLFVel(power*dir);
    setMechLBVel(-power*dir);
    setMechRFVel(-power*dir);
    setMechRBVel(power*dir);

    pros::delay(time);

    setMechLFVel(0);
    setMechLBVel(0);
    setMechRFVel(0);
    setMechRBVel(0);

    pros::Task DriveRampingTask (Drive::Drive_Ramping,(void*)"PROS",
    TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");
  }

  void ATurn(double deg,int LPowerSend,int RPowerSend,int EndWait){
    //right 90 turn 6000
    //right 180 turn 12000
    //right 270 turn 18000
    //left 90 turn -6000
    //left 180 turn -12000
    //left 270 turn -18000
    //-left,+right
    int Dir=sgn(deg);
    deg=abs(deg)/12.56;
    LPowerSend=LPowerSend*Dir;
    RPowerSend=RPowerSend*Dir;

    back_left_motor.tarePosition();
    back_right_motor.tarePosition();
    front_left_motor.tarePosition();
    front_right_motor.tarePosition();

    double RFValue = std::abs(front_right_motor.getPosition());
    double RBValue = std::abs(back_right_motor.getPosition());
    double LFValue = std::abs(front_left_motor.getPosition());
    double LBValue = std::abs(back_left_motor.getPosition());
    double AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);

    while(AbsTurnRotationsAvg < std::abs(deg)){
      DI(LPowerSend,-RPowerSend);

      RFValue = std::abs(front_right_motor.getPosition());
      RBValue = std::abs(back_right_motor.getPosition());
      LFValue = std::abs(front_left_motor.getPosition());
      LBValue = std::abs(back_left_motor.getPosition());
      AbsTurnRotationsAvg = ((RFValue+RBValue+LFValue+LBValue)/4);

      pros::delay(1);
    }
    DI(0,0);
    MechDriveLock();
    pros::delay(EndWait);
    //DI(0,0);
    MechDriveRelease();
  }
}
