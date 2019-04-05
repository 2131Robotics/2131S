#include "main.h"
#include "systems/aton/routine.hpp"

void PotSelectors(){
  int MainSelectValue = MainAtonSelect.get_value();
  int secSelectValue = SecAtonSelect.get_value();
  if(MainSelectValue > 3500) {
    FrontRedNP();
  }
  else if(MainSelectValue > 2000){
    FrontRedNP();
  }
  else if(MainSelectValue > 1350) {
    if(secSelectValue > 3600) FrontRedNP();
    else if(secSelectValue > 1900) FrontBlueNP();
    else if(secSelectValue > 450) BackBlueNP();
    else if(secSelectValue >= 0) BackRedNP();
  }
  else if(MainSelectValue > 775){
    if(secSelectValue > 3600) FrontRedNP();
    else if(secSelectValue > 1900) FrontBlueNP();
    else if(secSelectValue > 450) BackBlueNP();
    else if(secSelectValue >= 0) BackRedNP();

  }
  else if(MainSelectValue > 225){
    if(secSelectValue > 3600) FrontRedNP();
    else if(secSelectValue > 1900) FrontBlueNP();
    else if(secSelectValue > 450) BackBlueNP();
    else if(secSelectValue >= 0) BackRedNP();
  }
  else if(MainSelectValue >= 0){
    if(secSelectValue > 3600) FrontRedNP();
    else if(secSelectValue > 1900) FrontBlueNP();
    else if(secSelectValue > 450) BackBlueNP();
    else if(secSelectValue >= 0) BackRedNP();
  }
}
