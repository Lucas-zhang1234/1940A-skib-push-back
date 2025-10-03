#include "auton.h"
#include "lemlib/asset.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"
#include "skills_auton.h"

ASSET(path1_txt);
ASSET(path3_txt);
ASSET(testpath_txt);

void auton(int autonToRun) {
    if (autonToRun == 0)
    {
        skills_auton();
    }

    if (autonToRun == 1)
    {
        cornerAuton();
    }
    
    // --- LEGACY AUTON ---
    // chassis.turnToHeading(270,  1000);
    // chassis.moveToPoint(-28.583, -23.057, 3000);
    // chassis.turnToHeading(180, 1000);
    // chassis.moveToPoint(-32.434, -50.653, 2000, {.maxSpeed = 50});
    // chassis.turnToHeading(90, 1000,{.maxSpeed = 60});
    // chassis.moveToPoint(-23, -54, 1000,{.maxSpeed = 20});
    // chassis.waitUntilDone();
    // chassis.swingToPoint(-27.905, -47.123, DriveSide::LEFT, 5000, {.minSpeed=80, .earlyExitRange=2});
    // chassis.moveToPose(-11.445, -34.758, 240, 10000);
    // Inside_Skibidi_Roller.move(0);
    // chassis.turnToHeading(90, 1000);
    // chassis.moveToPose(-33.161, -47.037, 100, 2000);
    // chassis.waitUntilDone();
    // SkiBidi_Switcheroo.extend();
    // Top_Skibidi_Roller.move(-12000);
    // Inside_Skibidi_Roller.move(-12000);
};

void cornerAuton()
{
    
    // Initialise
    chassis.setPose(-50.425, 16.29, 0);
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(-47, 48, 0, 1000);
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(-64, 44, 270, 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(-67.5, 44, 450);
        chassis.moveToPoint(-64, 44, 450);
    }
 
    // Move to long goal
    chassis.moveToPoint(-58, 45, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.moveToPose(-31.5, 45, 90, 1000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2800);

    // Move back slightly
    chassis.moveToPoint(-60, 44, 1000, {.forwards=false});
    chassis.turnToHeading(135, 500);
    Top_Roller.move_velocity(-50);
    Switcheroo.toggle();
    chassis.moveToPoint(-27, 11,2000, {.maxSpeed = 100});
    

    //  chassis.moveToPose(-22.73, 23.44, 64, 2000);
    //  chassis.turnToHeading(135, 2000);
    //  Matchloader.extend();
    //  chassis.moveToPose(-13, 13, 135,  1000);
    //  Top_Roller.move(-12000);
    //  Inside_Roller.move(-12000);
    
}