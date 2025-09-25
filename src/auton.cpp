#include "auton.h"
#include "lemlib/asset.hpp"
#include "robot.hpp"

ASSET(path1_txt);
ASSET(path3_txt);
ASSET(testpath_txt);

void auton() {
    // TODO: Test entire auton to ensure that all the rollers are spinning the right way
    // TODO: and at the right time and the timings are all correct
    // Initialise
    chassis.setPose(-46.874, -10.883, 115);
    Bottom_Roller.move(-12000);
    Inside_Roller.move(12000);
    Switcheroo.extend();
    right_mg.move_velocity(70);
    left_mg.move_velocity(70);
    // Move to the block triplet first
    chassis.moveToPoint(-21.676, -22.491, 3000, {.maxSpeed = 70});
    // chassis.moveToPose(-21.676, -22.491, 110,  3000);
    // Wait until we move to the block triplet
    chassis.waitUntilDone();
    // Wait 200 ms for a buffer delay
    pros::delay(200);
    // Turn towards the high goal in the middle
    chassis.turnToHeading(44, 1000);
    // Move to the high goal in the middle
    chassis.moveToPoint(-8.335, -8.335, 1500);
    // Score a single block into the high goal in the middle
    // TODO: this might be incorrect / incomplete, test to fix
    Top_Roller.move(-12000);
    // Wait 800 ms for a buffer delay
    pros::delay(800);
    Inside_Roller.brake();
    Top_Roller.brake();
    // Move in front of the matchloader
    chassis.moveToPoint(-47.157, -47.157, 1500);
    // Turn towards the matchloader
    chassis.turnToHeading(270, 1000);
    // Move to the matchloader
    chassis.moveToPoint(-56.783, -47.157, 1000);
    // Start intaking
    Bottom_Roller.move(-12000);
    // Use a matchload mechanism to gain 3 more blocks
    Matchloader.extend();
    // Delay for a second to ensure all blocks are taken
    // TODO: test the timing of this delay so that all 3 blocks of our colour are taken but other blocks are not intaked
    pros::delay(1400);
    Bottom_Roller.brake();
    // Turn towards the long goal
    chassis.turnToHeading(90, 1000);
    // Move to the long goal
    chassis.moveToPoint(-32.151, -47.123, 1200);
    // Score as many blocks as possible
    Switcheroo.extend();
    Top_Roller.move(-12000);
    Inside_Roller.move(12000);

    // --- LEGACY AUTON ---
    // chassis.turnToHeading(270,  1000);
    // chassis.moveToPoint(-28.583, -23.057, 3000);
    // chassis.turnToHeading(180, 1000);
    // chassis.moveToPoint(-32.434, -50.653, 2000, {.maxSpeed = 50});
    // chassis.turnToHeading(90, 1000,{.maxSpeed = 60});
    // chassis.moveToPoint(-23, -54, 1000,{.maxSpeed = 20});
    // chassis.waitUntilDone();
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

void cornerAuton()
{
    
}