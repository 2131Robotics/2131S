#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "okapi/api.hpp"
extern okapi::Controller master_controller;


namespace Drive{
  extern okapi::ControllerButton BtnBrake;
  extern okapi::ControllerButton HoldToggle;
  extern okapi::ControllerButton DriveToggle;
}
namespace Intake{
  extern okapi::ControllerButton BtnIn;
  extern okapi::ControllerButton BtnOut;
  extern pros::ADILineSensor BallSenseTop;
  extern pros::ADILineSensor BallSenseBottom;
}
namespace Lift{
  extern okapi::ControllerButton BtnUp;
  extern okapi::ControllerButton BtnDown;
}

namespace Flipper{
  extern okapi::ControllerButton BtnUp;
  extern okapi::ControllerButton BtnDown;
}
namespace Catapult{
  extern okapi::ControllerButton btnCharge;
}
#endif /* end of include guard: CONTROLLER_HPP */
