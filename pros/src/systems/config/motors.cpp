#include "main.h"
#include "systems/config/motors.hpp"
#include "systems/drive.hpp"
#include "systems/ramping.hpp"
#include "systems/config/setup.hpp"
namespace Drive{
  okapi::Motor front_left_motor(11,false,okapi::AbstractMotor::gearset::green,
    okapi::AbstractMotor::encoderUnits::degrees);
    okapi::Motor back_left_motor(20,false,okapi::AbstractMotor::gearset::green,
      okapi::AbstractMotor::encoderUnits::degrees);
      okapi::Motor front_right_motor(1,true,okapi::AbstractMotor::gearset::green,
        okapi::AbstractMotor::encoderUnits::degrees);
        okapi::Motor back_right_motor(10,true,okapi::AbstractMotor::gearset::green,
          okapi::AbstractMotor::encoderUnits::degrees);

          }


          namespace Flipper{
            okapi::Motor motor(19,false,okapi::AbstractMotor::gearset::red,
              okapi::AbstractMotor::encoderUnits::degrees);
              void setFlipVel(int vel){
                if(vel==0) motor.moveVelocity(0);
                else motor.moveVelocity(vel);
              }
            }


            namespace Lift{
              okapi::Motor motor(9,false,okapi::AbstractMotor::gearset::green,
                okapi::AbstractMotor::encoderUnits::degrees);
                void setLiftVel(int vel){
                  if(vel==0) motor.moveVelocity(0);
                  else motor.moveVelocity(vel);
                }
              }
              namespace Catapult{
                okapi::Motor motor(13,false,okapi::AbstractMotor::gearset::red,
                  okapi::AbstractMotor::encoderUnits::degrees);
                  pros::ADIAnalogIn ChargeLightSensor(3);
                  void setCatapultVel(int vel){
                    if(vel==0) motor.moveVelocity(0);
                    else motor.moveVelocity(vel);
                  }
                }
                namespace Intake{
                  okapi::Motor motor(2,false,okapi::AbstractMotor::gearset::blue,
                    okapi::AbstractMotor::encoderUnits::degrees);
                    void setIntakeVel(int vel){
                      if(vel==0) motor.moveVelocity(0);
                      else motor.moveVelocity(vel);
                      pros::ADIAnalogIn BallSenseBottom(6);
                      pros::ADIAnalogIn BallSenseTop(4);
                    }
                  }

                  /* sensors */
                  pros::ADIAnalogIn MainAtonSelect(1);
                  pros::ADIAnalogIn SecAtonSelect(2);
