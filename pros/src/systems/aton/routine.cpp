#include "main.h"
#include "systems/aton/routine.hpp"
#include "systems/ramping.hpp"
#include "systems/aton/atoncatapult.hpp"
#include "systems/aton/atonlift.hpp"
#include "systems/aton/atonflipper.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/aton/atonintake.hpp"

//atons are set up here


void FrontRedNP(){
Drive::AtonDriveRamp(900);
Drive::AtonDriveRamp(-900);
Drive::AtonTurn(600);
Drive::AtonDriveRamp(100);
Catapult::Shoot=true;
pros::delay(100);
Drive::AtonDriveRamp(500);
Drive::AtonDriveRamp(-400);
Drive::AtonTurn(250);
Drive::AtonDriveRamp(-50);
Flipper::RotateTo(100);


}

void FrontBlueNP(){
  Drive::AtonDriveRamp(900);
  Drive::AtonDriveRamp(-900);
  Drive::AtonTurn(-600);
  Drive::AtonDriveRamp(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::AtonDriveRamp(500);
  Drive::AtonDriveRamp(-400);
  Drive::AtonTurn(-250);
  Drive::AtonDriveRamp(-50);
  Flipper::RotateTo(100);
}
