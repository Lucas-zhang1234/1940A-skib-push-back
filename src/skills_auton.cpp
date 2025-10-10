#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "robot.hpp"

void skills_auton() {
    c
    pros::delay(2900);
    Switcheroo.toggle();

    // Move back
    chassis.moveToPoint(40, 47.3,  1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000);

    // Move to wall to reset pose
    chassis.moveToPoint(40, -74, 4000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);

    // // SETUP FROM CORNER ================================================
    // Bottom_Roller.move(-12000);
    // Top_Roller.move(12000);
    // Inside_Roller.move(0);
    // Switcheroo.retract();

    chassis.setPose(lemlib::Pose(42.67, -64, 0));


    // ======== OTHER CORNER ========
    // Move to matchloader
    chassis.moveToPose(42.5, -47, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(55, -47, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 6; i++) {
        chassis.moveToPoint(58.5, -47, 450, {.minSpeed = 100});
        chassis.moveToPoint(55.2, -47, 450);
    }
    chassis.moveToPoint(57.75, -47, 450, {.minSpeed = 100});
    pros::delay(500);
    chassis.moveToPoint(55.5, -47, 450);

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(51.5, -46.7, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(26.67, -47.3, 90, 1000);
    chassis.waitUntilDone();
    pros::delay(300);

    // Score all 7 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(4000);

    Switcheroo.toggle();

    // Reverse slightly
    chassis.moveToPoint(47, -46.35, 2000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(1300);
    chassis.turnToHeading(315, 70, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    Top_Roller.move(12000);

    // Intake 4 more blocks
    Inside_Roller.move(0);
    chassis.moveToPoint(16, -16, 3000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(400);

    // Go back to the front of the long goal
    chassis.moveToPoint(45.5, -46.4, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(26, -46.5, 270, 1000);
    chassis.waitUntilDone();
    pros::delay(300);

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(3200);
    Switcheroo.toggle();

    // // SETUP FOR PARK ======================================================================
    // chassis.setPose(lemlib::Pose(26, -46.3, 270));
    // Bottom_Roller.move(-12000);
    // Top_Roller.move(12000);
    // Inside_Roller.move(-12000);
    // Switcheroo.extend();

    // Park and clear park zone
    ODOM_Lift.extend();
    chassis.moveToPoint(48, -46.7, 1200, {.forwards = false, .minSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(206.7, 1000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPoint(64, 11.7, 15000, {.minSpeed = 100});
};