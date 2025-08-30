#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "robot.hpp"

void skills_auton() {
     chassis.setPose(-46.874, -10.883, 115);
    Bottom_Skibidi_Roller.move(-12000);
    // Inside_Skibidi_Roller.move(12000);
    Top_Skibidi_Roller.move(-12000);
    // right_mg.move_velocity(70);
    // left_mg.move_velocity(70);
    chassis.moveToPoint(-21.676, -22.491, 3000, {.maxSpeed = 70});
    // chassis.moveToPose(-21.676, -22.491, 110,  3000);
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToHeading(270,  1000);
    chassis.moveToPoint(-28.583, -23.057, 3000);
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-32.434, -54.653, 2000, {.maxSpeed = 50});
    chassis.turnToHeading(90, 1000,{.maxSpeed = 60});
    chassis.moveToPoint(-23, -54, 1000,{.maxSpeed = 20});
    chassis.waitUntilDone();
    SkiBidi_Switcheroo.extend();
    Top_Skibidi_Roller.move(-12000);
    Inside_Skibidi_Roller.move(-12000);

}