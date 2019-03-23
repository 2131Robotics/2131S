#include "main.h"
namespace Drive{
  void mecham (int V1, int V2, int V3, int V4){
    front_left_motor.move_velocity(V1);
    back_left_motor.move_velocity(V2);
    front_right_motor.move_velocity(V3);
    back_left_motor.move_velocity(V4);

  }

  void manual (){
    int Left = ;
    int Right = j2;
    int Side = (j1+j4)/2; //average

    if(std::abs(j1)>std::abs(j4))
    {
      Side = j1;
    }

    else
    {
      Side = j4;
    }

    mecham(
      Left+Side,
      Left-Side,
      Right-Side,
      Right+Side);

    }
  }
