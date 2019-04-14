#ifndef INTAKE_HPP
#define INTAKE_HPP

namespace Intake {
  //global vars
  extern const int VOut;
  extern const int VStop;
  extern const int VIn;
  extern const int VOver;

  enum class Controllers{MANUAL,AUTO,NONE};//add to motors class

  //vars FUNCTIONS
  // Controllers get_controller();
  // void set_controller(Controllers c);
  int get_VSetting();
  void set_VSetting(int v);
  //methods
  void execute();//execute motor requests
  namespace Control{
    //vars
    //vars FUNCTIONS
    //methods

    void intake();
  }

  }

#endif
