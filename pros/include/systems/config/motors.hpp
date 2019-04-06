#ifndef MOTORS_HPP
#define MOTORS_HPP
//intagrate into systems files
#include "okapi/api.hpp"
#include "systems/ramping.hpp"
#define FRONT_LEFT_MOTOR 11
#define FRONT_RIGHT_MOTOR 1
#define BACK_LEFT_MOTOR 20
#define BACK_RIGHT_MOTOR 10
#define INTAKE_MOTOR 2
#define CATAPULT_MOTOR 13
#define LIFT_MOTOR 10
#define FLIPPER_MOTOR 19


namespace Drive{
  extern okapi::Motor front_left_motor;
  extern okapi::Motor front_right_motor;
  extern okapi::Motor back_left_motor;
  extern okapi::Motor back_right_motor;

}

namespace Catapult{
  extern okapi::Motor motor;

  extern pros::ADILineSensor ChargeLightSensor;
  void setCatapultVel(int vel);

}

namespace Intake{
  extern okapi::Motor motor;

  extern pros::ADILineSensor BallSenseTop;
  extern pros::ADILineSensor BallSenseBottom;
  void setIntakeVel(int vel);

}

namespace Lift{
  extern okapi::Motor motor;
  void setLiftVel(int vel);

}

namespace Flipper{
  extern okapi::Motor motor;
  void setFlipVel(int vel);

}

//Sensors
extern pros::ADIAnalogIn MainAtonSelect;
extern pros::ADIAnalogIn SecAtonSelect;

#endif /* end of include guard: MOTOR_HPP */
