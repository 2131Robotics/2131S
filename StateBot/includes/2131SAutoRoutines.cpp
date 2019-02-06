// /*testing*/
//     void test(){
//         toggleWrist();
//         wait(500);
//         toggleWrist();
//         // TimeAutoDrive(10000,-1);
//         // AutoIntakeEnabled = false;
//         // wait(500);
//         // AutoIntakeEnabled = true;
//         // wait(10000);
//     }
// /**/
// /*blue*/
//     //Normal
    void FrontBlue()
    {
        AutoIntakeEnabled = true;
        AutoIntakeOff = false;
        wait(350);
        AtonDriveRamp(1045,65,350);
        AtonDriveRamp(-15,65,350);
        AtonTurn(15);
        AtonSlide(30);
        AtonDriveRamp(-10,65);
        TimeAutoDrive(150,-70);
        AtonDriveRamp(100);
        AtonTurn(-3);
        wait(350);
        AtonTurn(13);
        AutoIntakeOff = true;
        AutoFlip = true;
        AtonDriveRamp(110,100,400);
        AtonDriveRamp(-150);
        AtonTurn(-8);
        AtonDriveRamp(-80);
        TimeAutoDrive(300,-60);
        AtonDriveRamp(-150);
    }
//         void BackBlue(){
//             AutoIntakeEnabled = true;
//             AutoIntakeOff = false;
//             wait(350);
//             AtonDriveRamp(1000,65);  
//             wait(500);
//             AtonDriveRamp(-50,100);
//             AtonSlide(-350);

//             AutoIntakeOff = true;
//             AutoFlip = true;
//             wait(200);

//             AtonDriveRamp(210,100);
//             wait(500);
//             // AtonDriveRamp(-80,100);
//             AutoIntakeOff = false;
//             AutoFlip = false;
//             SlideRecon(800, -40, 1);
//             wait(500);
//             AtonSlide(100);
//             AtonTurn(-NineM+2);
//             liftRotateTo(350);

//             AtonDriveRamp(-300,75);
//             wait(800);
//             TimeAutoDrive(800,-15);
//             AtonDriveRamp(-450,100);
//             MechDriveLock();
//         }
//     //Parking
//         void ParkFrontBlue(){
//             AutoIntakeEnabled = true;
//             AutoIntakeOff = false;
//             wait(500);

//             AtonDriveRamp(900,75); 
//             wait(450);
//             AtonDriveRamp(50,50);
//             AtonDriveRamp(-70,75);
//             AtonTurn(NineM+3);
//             // AtonSlide(-4);

//             AutoIntakeOff = true;
//             AutoFlip = true;
//             AutoCataFiring = true;
//             wait(600);
//             AtonDriveRamp(300,100);
//             wait(100);  
//             SlideRecon(300, -50, -1);
//             wait(300);
//             AtonDriveRamp(250,100);
//             TimeAutoDrive(800,30);
//             SlideRecon(500, 60, 1);
//             TimeAutoDrive(800,30);
//         }
// /**/
// /*red*/
//     //Normal
    void FrontRed()
    {
        AutoIntakeEnabled = true;
        AutoIntakeOff = false;
        wait(350);
        AtonDriveRamp(1045,65,350);
        AtonDriveRamp(-15,65,350);
        AtonTurn(-15);
        AtonSlide(30);
        AtonDriveRamp(-10,65);
        TimeAutoDrive(150,-70);
        AtonDriveRamp(100);
        AtonTurn(3);
        wait(350);
        AtonTurn(-13);
        AutoIntakeOff = true;
        AutoFlip = true;
        AtonDriveRamp(110,100,400);
        AtonDriveRamp(-150);
        AtonTurn(8);
        AtonDriveRamp(-80);
        TimeAutoDrive(300,-60);
        AtonDriveRamp(-150);
    }

//         void BackRed(){
//             AutoIntakeEnabled = true;
//             AutoIntakeOff = false;
//             wait(350);
//             AtonDriveRamp(1000,65);  
//             wait(500);
//             AtonDriveRamp(-50,100);
//             AtonSlide(210);

//             AutoIntakeOff = true;
//             AutoFlip = true;
//             wait(200);

//             AtonDriveRamp(210,100);
//             wait(500);
//             AtonDriveRamp(-130,100);
//             AutoIntakeOff = false;
//             AutoFlip = false;
//             SlideRecon(700, 40, 1);
//             wait(500);
//             AtonSlide(-100);
//             AtonTurn(NineM);
//             liftRotateTo(350);

//             AtonDriveRamp(-300,75);
//             wait(800);
//             TimeAutoDrive(400,-15);
//             AtonDriveRamp(-400,100);
//             MechDriveLock();
//         }
//     //Parking
//         void ParkingFrontRed(){
//             AutoIntakeEnabled = true;
//             AutoIntakeOff = false;
//             wait(500);

//             AtonDriveRamp(750,75); 
//             wait(450);
//             AtonDriveRamp(80,50);
//             wait(300);
//             AtonDriveRamp(-50,75);
//             AtonTurn(-NineM-3);
//             // AtonSlide(-4);

//             AutoIntakeOff = true;
//             AutoFlip = true;
