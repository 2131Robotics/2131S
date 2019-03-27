#include "systems/lift.hpp"
#include "systems/config/controller.hpp"
#include "systems/config/motors.hpp"


namespace Lift{

  void lift(){
    {

      if (BtnUp.isPressed()) {
        motor.moveVelocity(200);
      }
      else if (BtnDown.isPressed()) {
        motor.moveVelocity(-200);

      }
      else{
        motor.moveVelocity(0);
        motor.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
      }

    }


  }
}
