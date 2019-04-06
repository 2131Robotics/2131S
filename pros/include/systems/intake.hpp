#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace Intake {
  extern int BottomLightValue;
  extern int TopLightValue;
  extern int BottomBallInMax;
  extern int TopBallInMax;
  extern bool BallInBottom;
  extern bool BallInTop;
  extern bool AutoIntakeOff;
  extern bool IntakeFlip;

  void manualintake(void);
   void autointake(void);
}

#endif
