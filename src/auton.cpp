#include "auton.h"
#include "robot.hpp"

ASSET(path1_txt);
ASSET(path3_txt);

void auton() {
    chassis.setPose(-41.553, -6.316, 110);
    Bottom_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(12000);
    chassis.moveToPose(-21.349, -22.48, 120,  3000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToHeading(270,  1000);
    chassis.swingToPoint(-30.575, -48.321, DriveSide::LEFT, 2000, {.minSpeed=80, .earlyExitRange=20});
    
    
    // chassis.moveToPose(-11.445, -34.758, 240, 10000);
    // Inside_Skibidi_Roller.move(0);
    // chassis.turnToHeading(90, 1000);
    // chassis.moveToPose(-33.161, -47.037, 100, 2000);
    // chassis.waitUntilDone();
    // SkiBidi_Switcheroo.extend();
    // Top_Skibidi_Roller.move(-12000);
    // Inside_Skibidi_Roller.move(-12000);
    
};