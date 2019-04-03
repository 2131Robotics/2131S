#include "main.h"

#include "systems/ramping.hpp"
#include "systems/aton/atondrive.hpp"
#include "systems/aton/atoncatapult.hpp"
#include "systems/aton/atonintake.hpp"
#include "systems/aton/atonlift.hpp"
#include "systems/aton/routine.hpp"
#include "systems/aton/aton_selection.hpp"

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 void autonomous() {
   pros::Task DriveRampingTask (Drive::Drive_Ramping,(void*)"PROS",
     TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");
   pros::Task AutoCatapultTask (Catapult::catapultTaskChargeFire,(void*)"PROS",
     TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "AutoCatapultTask");
   pros::Task AutoIntakeTask (Intake::Auto_Intaking,(void*)"PROS",
     TASK_PRIORITY_DEFAULT,TASK_STACK_DEPTH_DEFAULT, "DriveRampingTask");

   PotSelectors();
 }
