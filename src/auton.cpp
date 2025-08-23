#include "auton.h"
#include "robot.hpp"

ASSET(path1_txt);
ASSET(path2_txt);

void auton() {
    chassis.setPose(-50.979, -7.257, 120);
    Bottom_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(12000);
    chassis.moveToPose(-30.028, -18.157, 120,  2000, {.maxSpeed=50});
    pros::delay(1000);
    chassis.turnToHeading(225,  1000);
    chassis.moveToPoint(-60, -36, 10000);
    chassis.moveToPose(-26.011, -46.726, 90, 2000);
    chassis.waitUntilDone();
    
    
};