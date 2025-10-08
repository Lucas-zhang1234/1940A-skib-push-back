#include "auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
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
        Left_7B_2G();
    }
    if (autonToRun == 2)
    {
        Right_7B_2G();
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

void Left_7B_2G()
{
    // Initialise
    chassis.setPose(-50.425, 16.29, 0);
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(-47, 45, 0, 1000);
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(-62, 45, 270, 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(-68, 45, 400);
        chassis.moveToPoint(-62, 45, 400);
    }
 
    // Move to long goal
    chassis.moveToPoint(-55, 45, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(200);
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.moveToPose(-32, 45, 90, 1000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2700);

    // Move back slightly
    chassis.moveToPoint(-57, 45, 3000, {.forwards=false});
    chassis.turnToHeading(135, 500);
    Top_Roller.move_velocity(-8000);
    Switcheroo.toggle();
    chassis.moveToPoint(-24.5, 12,2000, {.maxSpeed = 90});
    chassis.waitUntilDone();

    // Pause
    pros::delay(900);
    Bottom_Roller.brake();

    // Ram
    chassis.moveToPoint(-20, 10,2000, {.minSpeed = 100});
}

void Right_7B_2G()
{
    chassis.setPose(50.425, 16.29, 0);
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(47, 48, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(60, 46, 90, 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(62, 46, 450, {.minSpeed = 100});
        chassis.moveToPoint(60, 46, 450);
    }
 
    // Move to long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(56, 46, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.moveToPose(31, 47, 90, 1300, {.maxSpeed = 80});
    chassis.waitUntilDone();

    Top_Roller.move_velocity(600);

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2000);

    // Move back slightly
    chassis.moveToPoint(55, 46, 1000, {.forwards=false});
    chassis.turnToHeading(225, 500);
    Switcheroo.toggle();
    chassis.moveToPoint(22, 14,2000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    pros::delay(900);
    Bottom_Roller.move(12000);
}
