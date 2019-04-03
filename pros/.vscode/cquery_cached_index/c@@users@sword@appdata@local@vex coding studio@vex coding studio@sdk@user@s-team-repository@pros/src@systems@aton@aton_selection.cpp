#include "main.h"
#include "systems/aton/routine.hpp"

void PotSelectors(){
    int MainSelectValue = MainAtonSelect.get_value();
    int secSelectValue = SecAtonSelect.get_value();
    if(MainSelectValue > 3500) {
        FrontRed();
    }
    else if(MainSelectValue > 2000){
        FrontRed();
    }
    else if(MainSelectValue > 1350) {
        if(secSelectValue > 3600) FrontRed();
        else if(secSelectValue > 1900) FrontRed();
        else if(secSelectValue > 450) FrontRed();
        else if(secSelectValue >= 0) FrontRed();
    }
    else if(MainSelectValue > 775){
        if(secSelectValue > 3600) FrontRed();
        else if(secSelectValue > 1900) FrontRed();
        else if(secSelectValue > 450) FrontRed();
        else if(secSelectValue >= 0) FrontRed();

    }
    else if(MainSelectValue > 225){
        if(secSelectValue > 3600) FrontRed();
        else if(secSelectValue > 1900) FrontRed();
        else if(secSelectValue > 450) FrontRed();
        else if(secSelectValue >= 0) FrontRed();
    }
    else if(MainSelectValue >= 0){
        if(secSelectValue > 3600) FrontRed();
        else if(secSelectValue > 1900) FrontRed();
        else if(secSelectValue > 450) FrontRed();
        else if(secSelectValue >= 0) FrontRed();
    }
}
