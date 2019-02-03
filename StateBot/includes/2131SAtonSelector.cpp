// //-----------Brain Screen Aton Display------------//
//     void AtonUpdator(){
//         int MainSelectValue = MainAtonSelect.value(vex::percentUnits::pct);
//         int secSelectValue = SecAtonSelect.value(vex::percentUnits::pct);
//         Brain.Screen.clearScreen();

//         if(MainSelectValue > 90) {//test
//             Brain.Screen.clearLine(1,vex::color::purple);
//             Brain.Screen.clearLine();

//             Brain.Screen.print("Test");
//         }
//         else if(MainSelectValue > 60){//skills
//             Brain.Screen.clearLine(1,vex::color::orange);
//             Brain.Screen.clearLine();

//             Brain.Screen.print("Skills");

//         }
//         else if(MainSelectValue > 45) {//back red
//             Brain.Screen.clearLine(1,vex::color::red);
//             Brain.Screen.clearLine();

//             if(secSelectValue > 90) Brain.Screen.print("BackRed - Other");
//             else if(secSelectValue > 50) Brain.Screen.print("BackRed - Sniper");
//             else if(secSelectValue > 10) Brain.Screen.print("BackRed - Parking");
//             else if(secSelectValue >= 0) Brain.Screen.print("BackRed - Normal");
//         }
//         else if(MainSelectValue > 25){//front red
//             Brain.Screen.clearLine(1,vex::color::red);
//             Brain.Screen.clearLine();

//             if(secSelectValue > 90) Brain.Screen.print("FrontRed - Other");
//             else if(secSelectValue > 50) Brain.Screen.print("FrontRed - Sniper");
//             else if(secSelectValue > 10) Brain.Screen.print("FrontRed - Parking");
//             else if(secSelectValue >= 0) Brain.Screen.print("FrontRed - Normal");
//         }
//         else if(MainSelectValue > 10){//back blue
//             Brain.Screen.clearLine(1,vex::color::blue);
//             Brain.Screen.clearLine();

//             if(secSelectValue > 90) Brain.Screen.print("BackBlue - Other");
//             else if(secSelectValue > 50) Brain.Screen.print("BackBlue - Sniper");
//             else if(secSelectValue > 10) Brain.Screen.print("BackBlue - Parking");
//             else if(secSelectValue >= 0) Brain.Screen.print("BackBlue - Normal");
//         }
//         else if(MainSelectValue >= 0){//front blue
//             Brain.Screen.clearLine(1,vex::color::blue);
//             Brain.Screen.clearLine();

//             if(secSelectValue > 90) Brain.Screen.print("FrontBlue - Other");
//             else if(secSelectValue > 50) Brain.Screen.print("FrontBlue - Sniper");
//             else if(secSelectValue > 10) Brain.Screen.print("FrontBlue - Parking");
//             else if(secSelectValue >= 0) Brain.Screen.print("FrontBlue - Normal");
//         }
        
//     }
//     int WhatAton(){
//         while(true){
//             AtonUpdator();
//             Brain.Screen.render();
//             vex::task::sleep(20);
//         }
//         return 1;
//     }
// /**/
// //-----------Pot Selector Values Function------------//
void AutoSense()
{
    int selectValue = MainAtonSelect.value(vex::percentUnits::pct);
    int slots = SecAtonSelect.value(vex::percentUnits::pct);
    if(slots >  70)         white = true;
    else if(slots > 47)     pink = true;
    else if(slots > 30)     green = true;
    else if(slots >=0)      yellow = true;
    if(selectValue > 70)    RFlags = true;
    else if(selectValue > 40)   RCaps = true;
    else if (selectValue > 25)  BCaps = true;
    else if(selectValue >= 0)    BFlags = true;
    
}
void PotSelectors()
{
    
    AutoSense();
    Brain.Screen.print(slots);
    Brain.Screen.render();
    if(yellow==true)
    {
        Brain.Screen.print(" yellow");
        Brain.Screen.render();
        if (RFlags) FrontRed();
        else if(RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    else if (green==true){
        Brain.Screen.print(" green");
        Brain.Screen.render();
        if (RFlags) {} 
        else if(RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    else if (white==true)   
    {
        Brain.Screen.print(" white");
        Brain.Screen.render();
        if (RFlags) {}
        else if (RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    else if (pink==true)   
    {
        Brain.Screen.print(" pink");
        Brain.Screen.render();
        if (RFlags) {}
        else if (RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    debugger();
}
  /**/