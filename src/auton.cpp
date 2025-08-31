#include "auton.h"
#include "lemlib/asset.hpp"
#include "robot.hpp"

ASSET(path1_txt);
ASSET(path3_txt);
ASSET(testpath_txt);

void auton() {
    chassis.setPose(-46.874, -10.883, 115);
    Bottom_Skibidi_Roller.move(-12000);
    // Inside_Skibidi_Roller.move(12000);
    Top_Skibidi_Roller.move(-12000);
    // right_mg.move_velocity(70);
    // left_mg.move_velocity(70);
    chassis.moveToPoint(-21.676, -22.491, 3000, {.maxSpeed = 70});
    // chassis.moveToPose(-21.676, -22.491, 110,  3000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToHeading(270,  1000);
    chassis.moveToPoint(-28.583, -23.057, 3000);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-32.434, -50.653, 2000, {.maxSpeed = 50});
    chassis.turnToHeading(90, 1000,{.maxSpeed = 60});
    chassis.moveToPoint(-23, -54, 1000,{.maxSpeed = 20});
    chassis.waitUntilDone();
    SkiBidi_Switcheroo.extend();
    Top_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(-12000);


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