#include "main.h"
#include "systems/config/motors.hpp"
namespace Drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor front_right_motor(1,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_left_motor(20,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_right_motor(10,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Flipper{
  okapi::Motor flip_mtr(19,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);

}

// namespace Puncher{
// okapi::Motor motor(20,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
// }
namespace Lift{
  okapi::Motor lift_mtr(9,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace Catapult{
  okapi::Motor lift_mtr(13,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);

}
namespace Intake{
  okapi::Motor motor(12,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  namespace Auto{
    namespace Balls{
      pros::ADIAnalogIn Puncher(8);
      pros::ADIAnalogIn Over(7);
      pros::ADIAnalogIn Top(6);
      pros::ADIAnalogIn Bottom(5);
    }
  }
}
