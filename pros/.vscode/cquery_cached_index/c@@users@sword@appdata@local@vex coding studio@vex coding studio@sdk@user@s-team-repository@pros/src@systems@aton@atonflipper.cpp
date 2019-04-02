#include "main.h"
 #include "systems/aton/atonflipper.hpp"
 #include "systems/config/flipper.hpp"

 namespace Flipper {
   void RotateTo(double pos, int vel, bool wait){
     motor.moveAbsolute(pos,vel);
     if(wait) while(motor.isStopped()==0) pros::delay(5);
   }
 } /* Flipper */
