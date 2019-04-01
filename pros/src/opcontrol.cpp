#include "main.h"
#include "systems/drive.hpp"
#include "systems/intake.hpp"
#include "systems/lift.hpp"
#include "systems/config/flipper.hpp"
#include "systems/catapult.hpp"
#include "systems/config/important/fish_weee.hpp"
#include "systems/auto/autointake.hpp"
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
	MechDriveRampingEnabled=false;
	using namespace okapi::literals;
	pros::lcd::set_text(1, "start");


	while (true) {
		Drive::IsDriveFippedControll();
		Drive::DriveCont_LockContM();
		Flipper::flipper();
		Lift::lift();
		Intake::manualintake();
		Catapult::catapultmanual();
		// Fishy::fishy();

	}
}
