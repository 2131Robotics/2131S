#include "main.h"
#include "systems/catapult.hpp"
#include "systems/drive.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
#include "systems/config/vars.hpp"
namespace Catapult{
  void catapultmanual(){
    // when holding button, run motor
    if (btnCharge.isPressed()) {
      motor.moveVelocity(-100);
    }

    else{
      motor.moveVelocity(0);
    }
  }
  const int VStop=0;
  namespace OnOffCon{
  //vars
  const int ReleasedtoCharged=220;
  const int ChargedToReleased=140;
  double Target=0;
  bool Run=false;
  bool Enabled=false;
  //vars FUNCTIONS
  Controllers Controller=Controllers::NONE;
  bool DoubleShot=false;

  const int VMove=100;


  int V=VStop;
  bool Charged=false;

  void set_controller(Controllers c){
    Controller=c;
  }
  bool get_run(){
    return Run;
  }
  void set_run(bool r){
    Run=r;
  }
  int get_v(){
  return V;
}
  void set_v(int v){
  V=v;
}
  bool get_enabled(){
    return Enabled;
  }
  void set_enabled(bool e){
    Enabled=e;
  }
  double get_target(){
    return Target;
  }
  void set_target(double t){
    Target=t;
  }
  void set_targetRel(double t){
    Target+=t;
  }
  bool get_charged(){
  return Charged;
}
void set_charged(bool c){
  Charged=c;
}
  //methods
  void execute(){
    if(motor.getPosition()<get_target() && get_run()){//outside of tal
      set_controller(Controllers::POSITION);
      // Dir=SGN(Tar-Punchermotor.rotation(vex::rotationUnits::deg));
      set_v(VMove);//set the motor to spin in the correct direction
    }
    else if(get_controller()==Controllers::POSITION){//if in tar zone and was enabled; fist not enabled
      set_controller(Controllers::NONE);
      set_v(0);
      set_run(false);//stop after it has been hit
    }
  }
}
void Changer(){
  // ComRumerFun();
  if(!get_charged()){//Charging
    OnOffCon::set_targetRel(OnOffCon::ReleasedtoCharged);
    OnOffCon::set_run(true);
    OnOffCon::set_charged(true);
  }
  else if(get_charged()){//Fireing
    OnOffCon::set_targetRel(OnOffCon::ChargedToReleased);
    OnOffCon::set_run(true);
    OnOffCon::set_charged(false);
    // intake::automatic::balls::set_puncher(false);
    // intake::automatic::balls::set_overEnabled(false);
  }
}
void execute(){
  OnOffCon::execute();
  if(OnOffCon::get_controller()==Controllers::POSITION){
    motor.moveVelocity(OnOffCon::get_v());
  }
  else if(OnOffCon::get_controller()==Controllers::NONE){
    motor.moveVelocity(VStop);
  }
}
}
