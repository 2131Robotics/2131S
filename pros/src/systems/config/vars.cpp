#include "main.h"
#include "systems/config/vars.hpp"


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

/*Catapult vars*/
bool AutoCatapultEnabled = true;
bool IsCharged = false;

/*Intake vars*/
bool AutoIntakeEnabled = false;
bool AutoIntakeTaskEnabled = false;
// bool AutoMan=false;

bool IntakeEnabledBtnPressed;
bool IntakeEnabledInverted = true;
bool UserAutoIntakeMode = false;

/*Puncher vars*/
bool AutoPuncherFiring = false;

/*Ram Rod vars*/
bool RamEnabledBtnPressed;
bool RamEnabledInverted;
bool RamManualEnabled = false;
bool RamPosEnabled = true;

/*Lift vars*/
bool liftButtonWait;
int liftMode = 1;
int PIDliftUserCpower = 100;
bool liftDeployed = false;
//bool easyFlipDir = false;
bool LiftEEnabledBtnPressed;

/*Lock vars*/
bool jawButtonWait;
int jawMode = 1;
int jawUserCpower = 100;

bool JawMotorConBtnPressed;
bool JawMotorInverted = false;


/*Aton vars*/
double Nine = 6000;
double Full = Nine*2;

double LiftDown = 0;
double LiftUp = 500;
// int UP = 90;
// int DOWN = 30;
