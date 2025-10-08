#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
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
        chassis.moveToPoint(62.5, 46, 450, {.minSpeed = 100});
        chassis.moveToPoint(59, 46, 450);
    }

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(56, 46, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(33, 47, 90, 1000);
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    chassis.moveToPoint(35, 47, 1000, {.minSpeed = 90});
    chassis.moveToPoint(33, 47, 1000, {.minSpeed = 90});
    pros::delay(3000);
    chassis.moveToPoint(33,47, 700);

    // Reverse slightly and intake 4 more blocks
    Inside_Roller.move(0);
    chassis.moveToPoint(55, 46, 1500);
    chassis.waitUntilDone();
    Switcheroo.toggle();
    chassis.turnToHeading(225, 700, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.moveToPose(24, 24, 225, 1000);
    chassis.waitUntilDone();
    pros::delay(300);

    // Go back to the front of the long goal
    chassis.moveToPoint(55, 47.5, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    chassis.moveToPoint(33, 47.5, 800, {.maxSpeed = 45});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(1500);
};