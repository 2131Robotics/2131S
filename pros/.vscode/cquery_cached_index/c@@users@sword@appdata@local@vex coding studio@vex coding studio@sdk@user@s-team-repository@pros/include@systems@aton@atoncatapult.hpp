#ifndef ATONCATAPULT_HPP
#define ATONCATAPULT_HPP
namespace Catapult{
  extern bool Shoot;

  extern bool Charged;
  extern int ChargeSenseValue;
  extern int ChargeMaxValue;

  void ACatapult(void*CatapultTask);
}

#endif /* end of include guard: CATAPULT_HPP */
