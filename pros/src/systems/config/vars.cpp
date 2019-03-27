/*Math vars*/
// double abs(double Var) {
// 	if (Var < 0)  Var = Var * (-1);
// 	return Var;
// }
double sgn(double Var) {
  if (Var > 0)   Var = 1;
  else        Var = -1;
  return Var;
}
/*Drive vars*/
bool DriveRampingEnabled;
bool MechDriveRampingEnabled;

bool DriveLockConBtnPressed;
bool DriveLockInverted = false;

bool DriveDirConBtnPressed;
bool DriveDirInverted = false;

/*Flipper vars*/
bool FlipperMotorConBtnPressed;
bool FlipperMotorInverted = false;

/*Wrist vars*/
bool WristTaskEnabled;
bool WristMotorConBtnPressed;
bool WristMotorInverted = false;
bool WristCalibrated=false;
bool wristRan=true;
//bool WristMotorConBtnTwoPressed;
//bool WristMotorInvertedTwo = true;

/*Catapult vars*/
bool AutoCatapultEnabled = true;
