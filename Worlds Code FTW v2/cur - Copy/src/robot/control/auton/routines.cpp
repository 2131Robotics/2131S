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
      Drive::drive(-15);
      Drive::turnEnc(-89,150,1);
      
      //Drive::drive(1.5);
      Puncher::fire(); //shooting
      pros::delay(150);
      
      Drive::drive(9);
      Drive::turnEnc(-3,200,1);
      Drive::drive(6);
      Drive::drive(-9);
      Drive::turnEnc(66,200,1);
      Drive::drive(7);
      Puncher::fire();
      
          }
    void BlueFront(){
      Intake::enable();
      Drive::drive(19);
      Drive::drive(-15);
      Drive::turnEnc(87,150,1);
      
      Drive::drive(1.5);
      Puncher::fire(); //shooting
      pros::delay(150);
      
      Drive::drive(10);
      Drive::turnEnc(5,150,1);
      Drive::drive(10);

      //pros::delay(400); //pole
      Drive::drive(-9);
      Drive::turnEnc(-66,150,1);
      Drive::drive(4);
      Puncher::fire();
     /* Drive::drive(1.5);
      Flipper::set_target(-500);
      pros::delay(200);
      Drive::drive(-2);
      Flipper::set_target(-100);
      Drive::drive(2);
      Drive::turnEnc(55,100,1);
      Puncher::fire();*/
     /* Drive::drive(-1.5);
      Drive::turnEnc(-112,100,1);      
      Drive::drive(4);
      Flipper::set_target(-450);
      pros::delay(450);
      Drive::drive(-5);
      Drive::turnEnc(60,100,1);
      Drive::drive(6);
      Puncher::fire();*/
      
    }
    void FrontRedPark(){
      Intake::enable();
      Drive::drive(19);
      Drive::drive(-16);
      Drive::turnEnc(-90,100,1);
      Drive::drive(1.5);
      Puncher::fire(); //shooting
      pros::delay(500);
      Intake::disable();
      Drive::drive(-9);
      Drive::turnEnc(90,100,1);
    }
    void FrontBluePark()  {}
    void RedBackMidAndFar(){

      //intake::set_VSetting(40);
      Drive::drive(19);
      Intake::enable();
      pros::delay(400);
      Intake::disable();
      Drive::drive(-1);
      Drive::driveS(1,100,1,1);

      Drive::turnEnc(-62,100,1);
      pros::delay(3000);
      Puncher::fire();
      pros::delay(700);
      Intake::enable();
      Drive::drive(-9);
    //  Drive::driveS(-3);
      pros::delay(1500);
      Drive::turnEnc(2, 100, 1);
      Puncher::fire();
      pros::delay(800);
      Drive::turnEnc(-120,100,1);
    }
    void BlueBackMidAndFar(){
   
      //intake::set_VSetting(40);
      Drive::drive(19);
      Intake::enable();
      pros::delay(400);
      Intake::disable();
      Drive::drive(-2);
      Drive::driveS(-1,100,1,1);

      Drive::turnEnc(58,100,1);
      pros::delay(3000);
      Puncher::fire();
      pros::delay(500);
      Intake::enable();
      Drive::drive(-8.5);
    //  Drive::driveS(-3);
      pros::delay(1500);
      Drive::turnEnc(-2, 100, 1);
      Puncher::fire();
      pros::delay(800);
      Drive::turnEnc(130,100,1);
      Drive::drive(-9);
     // Lift::set_target(100);
    }
    void RedFrontMidAndPark(){
Intake::enable();
Drive::drive(19);
Drive::turnEnc(-80, 100, 450);
Puncher::fire();
pros::delay(400);
Drive::turnEnc(-50,100,1);
Flipper::set_target(flipper::limitMin,100,true);
Drive::drive(4);
Flipper::set_target(flipper::limitMax,100,true);
pros::delay(300);
Drive::drive(-2);
Drive::turnEnc(180, 100, 1);
}

    void BlueFrontMidAndPark(){
      Intake::enable();
      Drive::drive(19);
      Drive::turnEnc(-90,100,450);
      Puncher::fire();


    }
    void RedBackStackAndPark(){
      Drive::drive(-5);
      Drive::turnEnc(30,100,1);
      Drive::drive(-15);
      Lift::set_target(300);
      pros::delay(200);
      Drive::drive(6);
      Drive::turnEnc(-29.4,100,100);
      Drive::drive(11);
      Drive::driveRecon(100, 300);
      //Drive::drive(-.5);
      Lift::set_target(575);
      pros::delay(700);
      Drive::drive(-10);
      Lift::set_target(0);
      Drive::turnEnc(127,100,1);
      pros::delay(300);
      Drive::drive(3);
      Puncher::fire();
      
    }
    void BlueBackStackAndPark(){
      Drive::drive(-5);
      Drive::turnEnc(-30,200,1);
      Drive::drive(-15);
      Lift::set_target(300);
      pros::delay(200);
      Drive::drive(6);
      Drive::turnEnc(30,200,100);
      Drive::drive(11);
      Drive::driveRecon(200, 150);
      //Drive::drive(-.5);
      Lift::set_target(575);
      pros::delay(600);
      Drive::drive(-10);
      Lift::set_target(0);
      Drive::turnEnc(-145,200,1);
      pros::delay(300);
      Puncher::fire();
      
    }
    void RedBackUtlimate(){

    }
    void BlueBackUltimate(){

    }
  }
}
