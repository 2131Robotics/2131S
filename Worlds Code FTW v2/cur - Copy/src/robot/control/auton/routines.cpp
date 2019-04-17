#include "robot/control/auton/routines.hpp"
#include "robot/control/auton/selection.hpp"

#include "robot/control/systems/drive.hpp"
#include "robot/control/systems/intake.hpp"
#include "robot/control/systems/lift.hpp"
#include "robot/control/systems/flipper.hpp"
#include "robot/control/systems/puncher.hpp"

namespace auton{
  namespace Drive=drive::auton;
  namespace Intake=intake::automatic;
  namespace Lift=lift;
  namespace Flipper=flipper;
  namespace Puncher=puncher::auton;
  namespace routines{
    void testing(){
        Drive::turnEnc(90,150,1);
        pros::delay(3000);
        Drive::drive(17,200,1);
        Intake::enable();
        Lift::set_target(200,200,true);
        Drive::driveS(6,150,1);

        Flipper::set_target(flipper::limitMin,100,true);
        Intake::disable();
        Flipper::wait();
        Puncher::fire();

    }
    void RedFront()
    {
      Intake::enable();
      Drive::drive(19);
      Drive::drive(-16.5);
      Drive::turnEnc(-79,200,1);
      Drive::drive(2.5);
      Puncher::fire(); //shooting
      pros::delay(400);
      Drive::turnEnc(45, 150, 1);
      Drive::drive(6);
      Flipper::set_target(500);
      pros::delay(400);

    }
    void BlueFront(){
      Intake::enable();
      Drive::drive(19);
      Drive::turnEnc(90, 150, 1);
      /*Drive::drive(-16.5);
      Drive::turnEnc(81,200,1);
      Drive::drive(2.5);
      Puncher::fire(); //shooting
      pros::delay(400);
    //  Drive::driveS(-.4,200,1); //slides to the left to avoid pole
      Drive::drive(11);
      Drive::turnEnc(-10,150,1);
      Drive::drive(4);
      Drive::drive(-16);ends here
      Drive::turnEnc(-38,200,1);  //turn to hit middle flags
    //  Drive::driveS(.5,200,1);
      Drive::drive(6);
      Flipper::set_target(-500,100,true);

      pros::delay(400);
      Drive::drive(-2);
      Puncher::fire();*/

    }
    void RedBackMidAndFar(){
      Intake::enable();
      Drive::drive(19);

      //pros::delay(400);
      Intake::disable();
      Drive::driveS(2);
      Drive::turnEnc(-63,150,1);
      Puncher::fire();
      pros::delay(300);
      Intake::enable();
      Drive::drive(-4);
      pros::delay(1000);
      Puncher::fire();
    }
    void BlueBackMidAndFar(){
      Intake::enable();
      Drive::drive(19);
      Drive::turnEnc(60,150,1);
      Puncher::fire();
      pros::delay(500);
      Drive::turnEnc(-60,150,1);
      Drive::drive(-3);
      Drive::driveS(-9);
      Drive::drive(2.5);
      Flipper::set_target(flipper::limitMin,100,true);
      pros::delay(400);
      Drive::drive(-3);
      Flipper::set_target(flipper::limitMax,100,true);
      Drive::turnEnc(60,150,1);
      Puncher::fire();

    }
    void RedFrontMidAndPark(){
Intake::enable();
Drive::drive(19);
Drive::turnEnc(-80, 150, 450);
Puncher::fire();
pros::delay(400);
Drive::turnEnc(-50,150,1);
Flipper::set_target(flipper::limitMin,100,true);
Drive::drive(4);
Flipper::set_target(flipper::limitMax,100,true);
pros::delay(300);
Drive::drive(-2);
Drive::turnEnc(180, 150, 1);
}

    void BlueFrontMidAndPark(){
      Intake::enable();
      Drive::drive(19);
      Drive::turnEnc(-90,150,450);
      Puncher::fire();


    }
    void RedBackStackAndPark(){
      Drive::drive(-4);
      Drive::turnEnc(30,150,1);
      Drive::drive(-17);
      Lift::set_target(300);
      pros::delay(200);
      Drive::drive(6);
      Drive::turnEnc(28,100,1);
      Drive::drive(12);
      Drive::driveRecon(100, 300);
      Lift::set_target(575);
      pros::delay(400);
      Drive::drive(-10);
      Lift::set_target(0);
      Drive::turnEnc(113.5,150,1);
      Puncher::fire();
    }
    void BlueBackStackAndPark(){
      Drive::drive(-4);
      Drive::turnEnc(-30,150,1);
      Drive::drive(-17);

      Lift::set_target(300);
      pros::delay(200);
      Drive::drive(6);
      Drive::turnEnc(28,100,1);
      Drive::drive(12);
      Drive::driveRecon(100, 300);
      Lift::set_target(575);
      pros::delay(400);
      Drive::drive(-10);
      Lift::set_target(0);
      Drive::turnEnc(-113.5,150,1);
      Puncher::fire();
    }
    void RedBackUtlimate(){

    }
    void BlueBackUltimate(){

    }
  }
}
