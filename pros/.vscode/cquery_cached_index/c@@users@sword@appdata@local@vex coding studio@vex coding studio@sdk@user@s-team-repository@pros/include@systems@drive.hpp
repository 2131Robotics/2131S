#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"
#include "systems/config/motors.hpp"
namespace Drive{
  void IsDriveFippedControll();
  void MechDriveLock();
  void MechDriveRelease();
  void ManualMechDriveCont();
  void DriveCont_LockContM();

  void Drive_Ramping(void*DriveRampingTask);
}

#endif
