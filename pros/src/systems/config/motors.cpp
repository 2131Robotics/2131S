#include "main.h"
#include "systems/config/motors.hpp"
namespace Drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor front_right_motor(1,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_left_motor(20,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
  okapi::Motor back_right_motor(10,true,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);
}

namespace Flipper{
  okapi::Motor motor(19,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);

}

// namespace Puncher{
// okapi::Motor motor(20,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
// }
namespace Lift{
  okapi::Motor motor(9,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);
}
namespace Catapult{
  okapi::Motor motor(13,false,okapi::AbstractMotor::gearset::red,okapi::AbstractMotor::encoderUnits::degrees);

}
namespace Intake{
  okapi::Motor motor(12,false,okapi::AbstractMotor::gearset::green,okapi::AbstractMotor::encoderUnits::degrees);

}
