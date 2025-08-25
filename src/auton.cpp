#include "auton.h"
#include "robot.hpp"

ASSET(path1_txt);
ASSET(path2_txt);

void auton() {
    chassis.setPose(-41.553, -6.316, 120);
    Bottom_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(12000);
    chassis.moveToPose(-21.349, -22.48, 120,  3000, {.maxSpeed=50});
    pros::delay(1000);
    chassis.turnToHeading(270,  1000);
    chassis.moveToPose(-11.445, -34.758, 240, 10000);
    Inside_Skibidi_Roller.move(0);
    chassis.turnToHeading(90, 1000);
    chassis.moveToPose(-33.161, -47.037, 100, 2000);
    chassis.waitUntilDone();
    SkiBidi_Switcheroo.extend();
    Top_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(-12000);
    
};