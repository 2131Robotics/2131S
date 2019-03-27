#include "systems/intake.hpp"
#include "systems/config/motors.hpp"
#include "systems/config/controller.hpp"
namespace Intake{
bool ball1in = false;
bool ball2in = false;

  void manualintake()     {

    if (BtnIn.isPressed()) {
      motor.move_velocity(300);
    }
    else if (BtnOut.isPressed()) {
      motor.move_velocity(-300);

    }
    else{
      motor.move_velocity(0);
    }

  }
  void autointake(){




  }

}
