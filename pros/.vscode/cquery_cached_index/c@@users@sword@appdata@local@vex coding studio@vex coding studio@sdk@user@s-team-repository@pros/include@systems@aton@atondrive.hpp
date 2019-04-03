#ifndef ATONDRIVE_HPP
#define ATONDRIVE_HPP

namespace Drive{
  void AtonDriveRamp(double Distance,int Pct=200,int EndWait=250,int Correction=0);
  void TimeAutoDrive(int time, int power);
  void AtonSlide(double Distance,int Pct=200,int EndWait=500,int Correction=2);
  void SlideRecon(int time, int power, int dir);
  void AtonTurn(double deg,int LPowerSend=100,int RPowerSend=100,int EndWait=250);
}

#endif /* end of include guard: ATONDRIVE_HPP */
