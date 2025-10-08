#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "robot.hpp"

void skills_auton() {
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
    chassis.moveToPose(60, 46, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 6; i++) {
        chassis.moveToPoint(62, 46, 450, {.minSpeed = 100});
        chassis.moveToPoint(60, 46, 450);
    }

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(56, 46, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.moveToPose(31, 47, 90, 1300, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2000);
    chassis.moveToPoint(33, 47, 700);
    chassis.moveToPoint(31,47, 700);

    // Reverse slightly and intake 4 more blocks
    Inside_Roller.move(0);
    chassis.moveToPoint(42, 46, 1000);
    Switcheroo.toggle();
    chassis.turnToHeading(225, 700);
    chassis.moveToPose(28, 25, 225, 1000);
};