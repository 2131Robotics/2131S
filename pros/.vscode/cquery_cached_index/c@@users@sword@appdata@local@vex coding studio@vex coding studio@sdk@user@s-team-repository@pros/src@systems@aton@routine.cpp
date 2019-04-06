#include "main.h"
#include "systems/aton/routine.hpp"
#include "systems/ramping.hpp"
#include "systems/aton/atoncatapult.hpp"
#include "systems/aton/atonlift.hpp"
#include "systems/aton/atonflipper.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/aton/atonintake.hpp"

//atons are set up here

//right 90 turn 6000
//right 180 turn 12000
//right 270 turn 18000
//left 90 turn -6000
//left 180 turn -12000
//left 270 turn -18000
//-left,+right

/* No Park Match Atons */
void FrontRedNP(){
  Drive::ADrive(900);
  Drive::ADrive(-900);
  Drive::ATurn(-6000);
  Drive::ADrive(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-400);
  Drive::ATurn(-3000);
  Drive::ADrive(-50);
  Flipper::RotateTo(100);


}

void FrontBlueNP(){
  Drive::ADrive(900);
  Drive::ADrive(-900);
  Drive::ATurn(6000);
  Drive::ADrive(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-400);
  Drive::ATurn(3000);
  Drive::ADrive(-50);
  Flipper::RotateTo(100);
}

void BackBlueNP(){
  Drive::ADrive(900);
  Drive::ATurn(3000);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
}

void BackRedNP(){
  Drive::ADrive(900);
  Drive::ATurn(-3000);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
}
/* Parking Match Atons */

void FrontRed(){
  Drive::ADrive(900);
  Drive::ADrive(-900);
  Drive::ATurn(-6000);
  Drive::ADrive(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-400);
  Drive::ATurn(6000);
  Drive::ADrive(600);
  Drive::ATurn(6000);
  Drive::ADrive(300);


}

void FrontBlue(){
  Drive::ADrive(900);
  Drive::ADrive(-900);
  Drive::ATurn(6000);
  Drive::ADrive(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-400);
  Drive::ATurn(-6000);
  Drive::ADrive(600);
  Drive::ATurn(-6000);
  Drive::ADrive(300);
}

void BackBlue(){
  Drive::ADrive(900);
  Drive::ATurn(3000);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
  Drive::ATurn(3000);
  Drive::ASlide(200);
  Drive::ADrive(300);
}

void BackRed(){
  Drive::ADrive(900);
  Drive::ATurn(-3000);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
  Drive::ATurn(-3000);
  Drive::ASlide(200);
  Drive::ADrive(300);
}


/* Skills Aton */
void Skills(){
  Drive::ADrive(900);
  Drive::ASlide(200);
  Drive::ADrive(-900);
  Drive::ATurn(-6000);
  Drive::ADrive(600);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-600);
  Drive::ATurn(6000);
  Drive::ADrive(900);
  Drive::ADrive(-100);
  Drive::ASlide(-50);
  Drive::ATurn(-4000);
  Catapult::Shoot=true;
}
