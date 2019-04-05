#include "main.h"
#include "systems/config/controller.hpp"
// okapi::Controller master(okapi::ControllerId::master);
okapi::Controller master_controller(okapi::ControllerId::master);

namespace Drive{
  okapi::ControllerButton HoldToggle = master_controller[okapi::ControllerDigital::B];
  okapi::ControllerButton DriveToggle = master_controller[okapi::ControllerDigital::Y];
}
namespace Intake{
  // okapi::ControllerButton BtnCombo = master_controller[okapi::ControllerDigital::R2];
  okapi::ControllerButton BtnIn = master_controller[okapi::ControllerDigital::R1];
  okapi::ControllerButton BtnOut = master_controller[okapi::ControllerDigital::R2];
  pros::ADIAnalogIn BallSenseBottom(6);
  pros::ADIAnalogIn BallSenseTop(4);
}
namespace Lift{
  okapi::ControllerButton BtnUp = master_controller[okapi::ControllerDigital::L2];
  okapi::ControllerButton BtnDown = master_controller[okapi::ControllerDigital::L1];
}
namespace Flipper{
  okapi::ControllerButton BtnUp = master_controller[okapi::ControllerDigital::right];
  okapi::ControllerButton BtnDown = master_controller[okapi::ControllerDigital::left];
}
namespace Catapult{
  okapi::ControllerButton ChrgeBtn = master_controller[okapi::ControllerDigital::X];

}
