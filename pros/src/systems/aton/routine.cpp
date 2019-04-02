#include "main.h"
#include "systems/aton/routine.hpp"
#include "systems/ramping.hpp"
#include "systems/aton/atoncatapult.hpp"
#include "systems/aton/atonlift.hpp"
#include "systems/aton/atonflipper.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/aton/atonintake.hpp"
//atons are set up here


void FrontRed(){
Drive::ADrive(900);
Drive::ADrive(-900);
Drive::ATurn(600);
Drive::ADrive(100);
Catapult::Shoot=true;
pros::delay(100);
Drive::ADrive(500);
Drive::ADrive(-400);
Drive::ATurn(250);
Drive::ADrive(-50);
Flipper::RotateTo(100);


}
