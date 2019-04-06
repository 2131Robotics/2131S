#include "main.h"
#include "systems/catapult.hpp"
#include "systems/drive.hpp"
#include "systems/intake.hpp"
#include "systems/lift.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
#include "systems/config/vars.hpp"
bool charged = false;
namespace Catapult{
  void catapultmanual(){
    if (ChrgeBtn.isPressed()) {
      motor.moveVelocity(-100);
    }

    else{
      motor.moveVelocity(0);
    }
  }
  void AutoCatapult(){
    motor.tarePosition();
    if(ChrgeBtn.isPressed()){
      if(charged){
        charged = true;
        motor.moveAbsolute(320,100);
      }
      else if(charged){
        charged = false;
        motor.moveAbsolute(360,100);
        
      }


    }

  }


}
