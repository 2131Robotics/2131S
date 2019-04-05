#include "main.h"
#include "systems/aton/routine.hpp"
#include "systems/ramping.hpp"
#include "systems/aton/atoncatapult.hpp"
#include "systems/aton/atonlift.hpp"
#include "systems/aton/atonflipper.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/aton/atonintake.hpp"

//atons are set up here

/* No Park Match Atons */
void FrontRedNP(){
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

void FrontBlueNP(){
  Drive::ADrive(900);
  Drive::ADrive(-900);
  Drive::ATurn(-600);
  Drive::ADrive(100);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-400);
  Drive::ATurn(-250);
  Drive::ADrive(-50);
  Flipper::RotateTo(100);
}

void BackBlueNP(){
  Drive::ADrive(900);
  Drive::ATurn(-200);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
}

void BackRedNP(){
  Drive::ADrive(900);
  Drive::ATurn(200);
  Drive::ADrive(-150);
  Flipper::RotateTo(100);
}
/* Parking Match Atons */




/* Skills Aton */
void Skills(){
  Drive::ADrive(900);
  Drive::ASlide(200);
  Drive::ADrive(-900);
  Drive::ATurn(20);
  Drive::ADrive(600);
  Catapult::Shoot=true;
  pros::delay(100);
  Drive::ADrive(500);
  Drive::ADrive(-600);
  Drive::ATurn(-20);
  Drive::ADrive(900);
  Drive::ADrive(-100);
  Drive::ASlide(-50);
  Drive::ATurn(15);
  Catapult::Shoot=true;
}
