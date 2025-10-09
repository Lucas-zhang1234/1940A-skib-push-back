#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "robot.hpp"

void skills_auton() {
    chassis.setPose(45.424, 16.29, 0);
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
    for (int i = 0; i < 7; i++) {
        chassis.moveToPoint(62.5, 46, 450, {.minSpeed = 100});
        chassis.moveToPoint(60, 46, 450);
    }

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(56, 46, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(34, 48, 90, 1000);
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    chassis.moveToPoint(35, 47, 1000, {.minSpeed = 90});
    chassis.moveToPoint(33, 47, 1000, {.minSpeed = 90});
    pros::delay(3000);

    // Reverse slightly
    chassis.moveToPoint(57, 46, 1500, {.forwards = false});
    chassis.waitUntilDone();
    Switcheroo.toggle();
    chassis.turnToHeading(225, 70, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    Inside_Roller.brake();

    // Intake 4 more blocks
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

    // Move back
    chassis.moveToPoint(42, 47.5,  1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000);
    // Move to wall to reset pose
    chassis.moveToPoint(42, -64, 1500);
    chassis.setPose(lemlib::Pose(42, -60.85, 0));
    
};