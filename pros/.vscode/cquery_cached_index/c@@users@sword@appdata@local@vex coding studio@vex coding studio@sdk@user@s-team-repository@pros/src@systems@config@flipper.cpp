#include "systems/config/flipper.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
namespace Flipper{
  void flipper()     {

    if (BtnUp.isPressed()) {
      motor.moveVelocity(100);
    }
    else if (BtnDown.isPressed()) {
      motor.moveVelocity(-100);

    }
    else{
      motor.moveVelocity(0);
    }

  }


}
