#ifndef MOTOR_CONFIG_HPP
#define MOTOR_CONFIG_HPP
//intagrate into systems files
#include "okapi/api.hpp"
#define FRONT_LEFT_MOTOR 11
#define FRONT_RIGHT_MOTOR 1
#define BACK_LEFT_MOTOR 20
#define BACK_RIGHT_MOTOR 10
#define INTAKE_PORT 12
namespace Drive{
  extern okapi::Motor front_left_motor;
  extern okapi::Motor front_right_motor;
  extern okapi::Motor back_left_motor;
  extern okapi::Motor back_right_motor;
}




namespace Lift{
  // extern okapi::Motor motor0;
  // extern okapi::Motor motor1;
  extern okapi::MotorGroup motor;
}
namespace Flipper{
  extern okapi::MotorGroup motor;


}
namespace Catapult{
extern okapi::MotorGroup motor;


}
namespace Intake{
  extern okapi::Motor motor;
  namespace Auto{
    namespace Balls{
      extern pros::ADILineSensor Puncher;
      extern pros::ADILineSensor Over;
      extern pros::ADILineSensor Top;
      extern pros::ADILineSensor Bottom;
    }
  }
}
#endif /* end of include guard: MOTOR_CONFIG_HPP */
