#include "main.h"
#include "systems/catapult.hpp"
#include "systems/drive.hpp"
#include "systems/intake.hpp"
#include "systems/lift.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
namespace Catapult{
  void catapultmanual(){
    if (ChrgeBtn.isPressed()) {
      motor.moveVelocity(-100);
    }

    else{
      motor.moveVelocity(0);
    }
  }
}
