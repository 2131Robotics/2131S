//-----------Pot Selector Values Function------------//
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
    
    if(yellow)
    {
        Brain.Screen.print(" yellow");
        Brain.Screen.render();
        if (RFlags) FrontRed();
        else if(RCaps) {}
        else if (BCaps) {}
        else if (BFlags) FrontBlue();
    }
    else if (green){
        Brain.Screen.print(" green");
        Brain.Screen.render();
        if (RFlags) {} 
        else if(RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    else if (white)   
    {
        Brain.Screen.print(" white");
        Brain.Screen.render();
        if (RFlags) {}
        else if (RCaps) {}
        else if (BCaps) {}
        else if (BFlags) {}
    }
    else if (pink)   
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