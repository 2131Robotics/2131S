#ifndef SETUP_HPP
#define SETUP_HPP
#include "systems/ramping.hpp"
namespace Drive{

    extern Ramping LFDR;
    extern Ramping RFDR;
    extern Ramping LBDR;
    extern Ramping RBDR;
    void setMechLFVel(int pct);
    void setMechLBVel(int pct);
    void setMechRFVel(int pct);
    void setMechRBVel(int pct);

    void setMechDriveVel(int LF,int LB,int RF,int RB);
    void DriveMechVelSend(int j1,int j2,int j3,int j4);
    void setDriveVel(int left, int right);




}


#endif /* end of include guard: SETUP_HPP */
