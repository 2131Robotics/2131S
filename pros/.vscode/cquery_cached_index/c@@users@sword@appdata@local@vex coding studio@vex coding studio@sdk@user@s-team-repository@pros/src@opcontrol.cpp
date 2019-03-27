#include "main.h"
#include "systems/drive.hpp"
#include "systems/intake.hpp"
#include "systems/lift.hpp"
#include "systems/config/flipper.hpp"
#include "systems/catapult.hpp"
#include "systems/config/important/fish_weee.hpp"
/**
* Runs the operator control code. This function will be started in its own task
* with the default priority and stack size whenever the robot is enabled via
* the Field Management System or the VEX Competition Switch in the operator
* control mode.
*
* If no competition control is connected, this function will run immediately
* following initialize().
*
* If the robot is disabled or communications is lost, the
* operator control task will be stopped. Re-enabling the robot will restart the
* task, not resume it from where it left off.
*/



void opcontrol() {
	using namespace okapi::literals;
	pros::lcd::set_text(1, "XD");


	while (true) {
		Drive::mechamdrive();
		Drive::drivecontrol();
		Flipper::flipper();
		Lift::lift();
		Intake::intake();
		Catapult::catapultmanual();
		Fishy::fishy();

	}
}
