#ifndef ATONINTAKE_HPP
#define ATONINTAKE_HPP

namespace Intake{
  extern int BottomLightValue;
  extern int TopLightValue;
  extern int BottomBallInMax;
  extern int TopBallInMax;
  extern bool BallInBottom;
  extern bool BallInTop;
  extern bool AutoIntakeOff;
  extern bool IntakeFlip;

  void AIntake(void*AutoIntaking);
}

#endif /* end of include guard: AUTOINTAKE_HPP */
