#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "robot.hpp"

void skills_auton() {
    chassis.setPose(45.65, 16.7, 0);
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(42.5, 46.9, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(55.5, 47.3, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 7; i++) {
        chassis.moveToPoint(57.75, 47.3, 450, {.minSpeed = 100});
        chassis.moveToPoint(55.5, 47.3, 450);
    }
    chassis.moveToPoint(57.75, 47.3, 450, {.minSpeed = 100});
    pros::delay(700);
    chassis.moveToPoint(55.5, 47.3, 450);

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(50.5, 47.5, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(30, 47, 90, 1000);
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(5000);

    // Reverse slightly
    chassis.moveToPoint(51.5, 47.3, 1500, {.forwards = false});
    chassis.waitUntilDone();
    Switcheroo.toggle();
    chassis.turnToHeading(225, 70, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    Top_Roller.move(12000);

    // Intake 4 more blocks
    chassis.moveToPose(14, 14, 225, 3000, {.maxSpeed = 70});
    chassis.waitUntilDone();

    // Go back to the front of the long goal
    chassis.moveToPoint(45.5, 45, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(30, 40.5, 270, 1800, {.maxSpeed = 70});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2900);
    Switcheroo.toggle();

    // Move back
    chassis.moveToPoint(40, 47.3,  1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000);
    // Move to wall to reset pose
    chassis.moveToPoint(40, -74, 4000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.setPose(lemlib::Pose(39.4, -63, 0));


    // ======== OTHER CORNER ========
    // Move to matchloader
    chassis.moveToPose(42.5, -46.9, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(55, -47.3, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 6; i++) {
        chassis.moveToPoint(58, -47.3, 450, {.minSpeed = 100});
        chassis.moveToPoint(55, -47.3, 450);
    }
    chassis.moveToPoint(57.75, -47.3, 450, {.minSpeed = 100});
    pros::delay(500);
    chassis.moveToPoint(55.5, -47.3, 450);

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(51.5, -47.5, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(30, -47, 90, 1000);
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.brake();
    Inside_Roller.move(-12000);
    pros::delay(4000);

    // Reverse slightly
    chassis.moveToPoint(51.5, -47.3, 1500, {.forwards = false});
    chassis.waitUntilDone();
    Switcheroo.toggle();
    chassis.turnToHeading(315, 70, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    Top_Roller.move(12000);

    // Intake 4 more blocks
    Inside_Roller.move(0);
    chassis.moveToPoint(19, -16, 3000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(600);

    // Go back to the front of the long goal
    chassis.moveToPoint(45.5, -47, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(25.6, -48, 270, 1000);
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2900);
    Switcheroo.toggle();

    // Park and clear park zone
    chassis.moveToPoint(35, -48, 1500, {.forwards = false});
    chassis.moveToPose(-64, 0, 180, 15000, {.minSpeed = 70});
};