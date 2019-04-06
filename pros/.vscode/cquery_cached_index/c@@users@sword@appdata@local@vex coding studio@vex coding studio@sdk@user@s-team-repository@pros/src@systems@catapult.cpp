#include "main.h"
#include "systems/catapult.hpp"
#include "systems/drive.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
#include "systems/config/vars.hpp"
bool IsCharged = false;
namespace Catapult{
  void catapultmanual(){
    // when holding button, run motor
    if (ChrgeBtn.isPressed()) {
      motor.moveVelocity(-100);
    }

    else{
      motor.moveVelocity(0);
    }
  }
  void AutoCatapult(){
    //when button gets pressed set to position.
    motor.tarePosition();
    if(ChrgeBtn.isPressed()){
      if(IsCharged){
        IsCharged = true;
        motor.moveAbsolute(320,100);
      }
      else if(IsCharged){
        IsCharged = false;
        motor.moveAbsolute(360,100);
      }
      else{


      }



    }

  }


}
