#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"
#include "systems/config/motors.hpp"
// #define TOP_LEFT_PORT 11
// #define TOP_RIGHT_PORT 1
// #define BOTTOM_LEFT_PORT 20
// #define BOTTOM_RIGHT_PORT 10
extern okapi::Controller master;
namespace Drive{
  void mecham (int V1 =0, int V2 =0, int V3 =0, int V4=0);
  void manual ();



}
#endif
