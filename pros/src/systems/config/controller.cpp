#include "main.h"
#include "systems/config/controller.hpp"
// okapi::Controller master(okapi::ControllerId::master);
okapi::Controller master_controller(okapi::ControllerId::master);
namespace Flow{
  okapi::ControllerButton BtnTog = master_controller[okapi::ControllerDigital::up];
  okapi::ControllerButton BtnToCaps = master_controller[okapi::ControllerDigital::L1];
}
namespace Drive{
  okapi::ControllerButton BtnBrake = master_controller[okapi::ControllerDigital::L2];
}
namespace Intake{
  // okapi::ControllerButton BtnCombo = master_controller[okapi::ControllerDigital::R2];
  okapi::ControllerButton BtnIn = master_controller[okapi::ControllerDigital::R1];
  okapi::ControllerButton BtnOut = master_controller[okapi::ControllerDigital::R2];
  // okapi::ControllerButton BtnTog = master_controller[okapi::ControllerDigital::A];
}
namespace Lift{
  okapi::ControllerButton BtnUp = master_controller[okapi::ControllerDigital::R1];
  okapi::ControllerButton BtnDown = master_controller[okapi::ControllerDigital::R2];
}
namespace Flipper{
  okapi::ControllerButton BtnUp = master_controller[okapi::ControllerDigital::left];
  okapi::ControllerButton BtnDown = master_controller[okapi::ControllerDigital::right];
}
namespace Catapult{
  okapi::ControllerButton ChrgeBtn = master_controller[okapi::ControllerDigital::A];

}
