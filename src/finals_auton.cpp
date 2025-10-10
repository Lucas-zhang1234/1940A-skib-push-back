#include "finals_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "robot.hpp"

void finals_auton()
{
    chassis.setPose(45.65, 16.9, 0);
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(42.5, 46.9, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(55.5, 47.3, 90, 1500);
    for (int i = 0; i < 2; i++) {
        chassis.moveToPoint(57.8, 47.3, 450, {.minSpeed = 100});
        chassis.moveToPoint(55.5, 47.3, 450, {.minSpeed = 100});
    }

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(50.5, 47.5, 2000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(29.3, 47, 270, 2000);
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    pros::delay(2800);
    Inside_Roller.move_velocity(0);
    pros::delay(100);

    // Reverse slightly
    chassis.moveToPoint(51.5, 47.3, 1500, {.forwards = false});
    chassis.waitUntilDone();
    Switcheroo.toggle();
    chassis.turnToHeading(225, 70, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    Top_Roller.move(12000);

    // Intake 3 more blocks
    chassis.moveToPose(15, 15, 225, 3000, {.maxSpeed = 60});
    chassis.waitUntilDone();

    // Go back to the front of the long goal
    chassis.moveToPoint(45.5, 45, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(28.7, 42, 270, 1800, {.maxSpeed = 70});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
}