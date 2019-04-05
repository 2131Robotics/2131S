#ifndef DRIVE_HPP
#define DRIVE_HPP
#include "okapi/api.hpp"
#include "systems/config/motors.hpp"
namespace Drive{
  void IsDriveFlippedControll(void);
  void MechDriveLock(void);
  void MechDriveRelease(void);
  void ManualMechDriveCont(void);
  void DriveCont_LockContM(void);

  void Drive_Ramping(void*DriveRampingTask);
}

#endif
