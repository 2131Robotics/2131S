#include "main.h"
#include "systems/aton/atonlift.hpp"
namespace Lift{
  void RotateTo(double pos, int vel, bool wait){
    motor.moveAbsolute(pos,vel);
    if(wait) while(motor.isStopped()==0) pros::delay(5);
  }
}
