#ifndef CATAPULT_HPP
#define CATAPULT_HPP

namespace Catapult{

  void catapultmanual(void);
  //vars
  enum class Controllers{POSITION,NONE};
  Controllers controller=Controllers::NONE;

  extern const int VMove;
  extern const int VStop;
  //vars FUNCTIONS
  bool get_doubleShot();
  bool get_charged();
  //methods
  void execute();
  namespace OnOffCon{
    bool get_run();
    Controllers get_controller(){
    return controller;
  }
  }
  namespace control{
    void charge();
    void doubleBack();
    void doubleFront();
  }
  namespace auton{
    void wait(int w=0);
    void charge(bool w=false);
    void fire(bool w=true);
  }

}
#endif /* end of include guard: CATAPULT_HPP */
