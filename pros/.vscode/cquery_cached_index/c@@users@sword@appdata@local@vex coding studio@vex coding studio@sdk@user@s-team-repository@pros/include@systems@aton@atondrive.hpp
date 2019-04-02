#ifndef ATONDRIVE_HPP
#define ATONDRIVE_HPP

namespace Drive{
  void ADrive(double Distance,int Pct=200,int EndWait=250,int Correction=0);
  void ATimeDrive(int time, int power);
  void ASlide(double Distance,int Pct=200,int EndWait=500,int Correction=2);
  void ASlideRecon(int time, int power, int dir);
  void ATurn(double deg,int LPowerSend=100,int RPowerSend=100,int EndWait=250);
}

#endif /* end of include guard: ATONDRIVE_HPP */
