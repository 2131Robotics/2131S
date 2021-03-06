#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"
#include "systems/config/motors.hpp"
namespace Drive{
  //vars
  enum class Controllers{MANUAL,NONE};
  //vars FUNCTIONS
  // bool get_invert();
  void set_inverted(bool i);
  void set_brakeMode(okapi::Motor::brakeMode b);
  //methods
  void execute();
  namespace Control{
    void manual();
    void hold();
  }
}
#endif
